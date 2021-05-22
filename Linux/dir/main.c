/*Linux的目录是一个树状结构，遍历一棵树最简单的方式是递归。Linux给我们提供了相关的目录遍历的函数，opendir(),
 *readdir()和closedir()。DIR结构体类似于FILE结构体，目录的操作方式和标准C库提供的文件操作步骤是类似的。
 */

/*目录文件包含了其他文件的名字以及指向与这些文件有关的信息的指针。从定义能够看出，dirent不仅仅指向目录，
 *还指向目录中的具体文件，readdir函数同样也读取目录下的文件。
 */

/*1.目录属性结构体struct dirent定义：（使用man 3 readdir可以查看）
 * struct dirent{
 *     ino_t          d_ino;       // Inode number（文件对应的inode编号, 定位文件存储在磁盘的那个数据块上）。
 *     off_t          d_off;       // Offset to the next dirent（文件在当前目录中的偏移量）。
 *     unsigned short d_reclen;    // Length of this record（文件名字的实际长度）。
 *     unsigned char  d_type;      // Type of file（文件的类型, linux中有7中文件类型）。
 *     char           d_name[256]; // Null-terminated filename（文件的名字）。
 * };
 */
 
/*2.dirent结构体中的文件类型d_type：（正好对于Linux中的7种文件类型）
 *（1）DT_BLK：块设备文件
 *（2）DT_CHR：字符设备文件
 *（3）DT_DIR：目录文件
 *（4）DT_FIFO ：管道文件
 *（5）DT_LNK：软连接文件
 *（6）DT_REG ：普通文件
 *（7）DT_SOCK：本地套接字文件
 *（8）DT_UNKNOWN：无法识别的文件类型
 */

/*3.获取某目录下所有文件的详细信息步骤：
 *（1）使用opendir()函数打开目录，返回指向目录的DIR结构体。
 *（2）调用readdir()函数遍历目录下所有文件（包括目录），返回指向目录下所有文件的dirent结构体。
 *（3）遍历dirent结构体，调用stat()来获取每个文件的详细信息，存储在stat结构体中。
 * 总体就是这样一种逐步细化的过程，在这一过程中，DIR、dirent和stat这3种结构体扮演着不同的角色。
*/

/*opendir()目录打开之后，就可以通过readdir()函数遍历目录中的文件信息了。每调用一次这个函数就可以
 *得到目录中的一个文件信息，当目录中的文件信息被全部遍历完毕会得到一个空对象。目录操作完毕之后，
 *需要通过closedir()关闭通过opendir()得到的实例，释放资源。
 */

/*4.通过readdir()遍历目录中的文件步骤：
 * DIR* dir = opendir("/home/test");      //打开目录
 *
 * struct dirent* ptr = NULL;
 * while( (ptr=readdir(dir)) != NULL)     // 遍历目录
 * {
 *    .......
 * }
 *
 * closedir(dir);                         //关闭目录
 */

/*我们使用的DIR结构也只是声明了该结构的指针，那么DIR结构应该也是同FILE结构一样，
 *在打开一个目录的时候，由内核帮我们分配该结构体的内存。
 */

#include <fcntl.h>
#include <unistd.h>     //rmdir()
#include <sys/types.h>
#include <sys/stat.h>   //mkdir()
#include <dirent.h>     //DIR,struct dirent,opendir(),readdir(),closedir()
#include <stdio.h>      //perror()
#include <stdlib.h>
#include <string.h>     //strerror()
#include <errno.h>      //errno全局变量

#define _CHANGE_WAY_
// #undef _CHANGE_WAY_

#define BUFF_SIZE 1024

#define PRINT_INFO(str)  \
	write(STDOUT_FILENO,str,strlen(str))

#define ERROR_INFO(str)                        \
	do{                                        \
		write(STDERR_FILENO,str,strlen(str));  \
		return ;                               \
	}while(0)

#define SAVE_INFO(fb,str)  \
	write(fb,str,strlen(str))
	
static void mkdir_test();
static void rmdir_test();

static void printDir();
static void printDetail();

static void displayFile(char suffix[]);   //遍历单层目录
static int displayDir(const char* path);                 //遍历多层目录

int main(int argc,char* argv[])
{
	if(argc != 2)
	{
		PRINT_INFO("main warn: usage main.out mkdir/rmdir/ls/ls -l/ls -f/ls -d\n");
		return -1;
	}
	fprintf(stdout,"exe name: %s ,argument %s\n",argv[0],argv[1]);
	
	if(strcmp(argv[1],"mkdir") == 0)
	{
		mkdir_test();
	}
	else if(strcmp(argv[1],"rmdir") == 0)
	{
		rmdir_test();
	}
	else if(strcmp(argv[1],"ls") == 0)
	{
		printDir();
	}
	else if(strcmp(argv[1],"ls -l") == 0)
	{
		printDetail();
	}
	else if(strcmp(argv[1],"ls -f") == 0)
	{
		displayFile(".txt");
	}
	else if(strcmp(argv[1],"ls -d") == 0)
	{
		int file_count = displayDir("../io");
		printf("\ndisplayDir: have %d file in ../io\n",file_count);
	}
	else
	{
		SAVE_INFO(STDOUT_FILENO,"main: input argument illegal\n");
	}
	
	return 0;
}

void mkdir_test()
{
	int ret = mkdir("./directory",S_IRWXO | S_IRGRP | S_IROTH);
	if(ret == -1)
	{
		perror("mkdir_test error: ");
		return ;
	}
	PRINT_INFO("mkdir_test: make directory successfully\n");
	
	ret = chmod("directory",S_IRWXU | S_IRWXG |S_IRWXO);
	if(-1 == ret)
	{
		printf("mkdir_test error: %s\n",strerror(errno));
		return ;
	}
	puts("mkdir_test: change mode successfully\n");
	
	/*creat()创建文件相当于调用open(char* filename,O_CREAT|O_WRONLY|O_TRUNC)，
	 *创建的文件已经被打开了，不需要再调用open()
	 */
	 int fb = creat("directory/mkdir_test.txt",S_IRWXO | S_IRGRP | S_IWGRP | S_IRWXO);
	 if(-1 == fb)
	 {
		 PRINT_INFO("mkdir_test error: create mkdir_test.txt failed\n");
		 return ;
	 }
	 
	write(fb,"hello world\n",strlen("hello world\n"));
	SAVE_INFO(fb,"time is 2021/05/22\n");
	SAVE_INFO(fb,"this is mkdir test\n");
	
	close(fb);
}

void rmdir_test()
{
	char buf[128] = {0};
	if(getcwd(buf,sizeof(buf)) == NULL)   //获取当前目录绝对路径
	{
		ERROR_INFO("rmdir_test error: getcwd failed\n");
	}
	printf("rmdir_test: current directory is %s\n",buf);
	
	//使用C库中的remove方法删除文件，Linux中没有删除文件系统调用
	if(remove("directory/mkdir_test.txt") == -1)
	{
		perror("rmdir_test error: ");
		return ;
	}
	
	//rmdir()只能删除空目录，所以目录删除时，需要将目录中的文件清空
	if(rmdir("./directory") == -1)
	{
		printf("rmdir_test error: %s\n",strerror(errno));
		return ;
	}
	PRINT_INFO("rmdir_test: remove directory successfully\n");
}

void printDir()
{
	DIR *dir = opendir("..");    //打开目录
	if(dir == NULL)
	{
		fprintf(stderr,"printDir error: %s\n",strerror(errno));
		return ;
	}
	
	struct dirent* entity = NULL;
	while((entity = readdir(dir)) != NULL)    //遍历打开目录中的所有文件
	{
		if(strncmp(entity->d_name,".",1) == 0
			|| strncmp(entity->d_name,"..",2) == 0)      //过滤掉当前目录和上一级目录
		{
			continue;
		}
		
		printf("%s\n",entity->d_name);
	}
	
	closedir(dir);    //关闭目录
}

void printDetail()
{
	DIR *dir = opendir(".");
	if(dir == NULL)
	{
		ERROR_INFO("printDetail error: can't open directory failed\n");
	}
	
	char buf[32] = {0};
	struct dirent* entity = NULL;
	while((entity = readdir(dir)) != NULL)
	{
		switch(entity->d_type){
		case DT_BLK:
			strcpy(buf,"block device");
			break;
		case DT_CHR:
			strcpy(buf,"charactor device");
			break;
		case DT_DIR:
			strncpy(buf,"directory",strlen("directory") + 1);
			break;
		case DT_FIFO:
			strncpy(buf,"named pipe(FIFO)",strlen("named pipe(FIFO)") + 1);
			break;
		case DT_LNK:
			memcpy(buf,"symbolic link",strlen("symbolic link") + 1);
			break;
		case DT_REG:
			memcpy(buf,"regular file",strlen("regular file") + 1);
			break;
		case DT_SOCK:
			sprintf(buf,"Unix domain socket");
			break;
		case DT_UNKNOWN:
			sprintf(buf,"could not be determined");
			break;
		}
		
		printf("d_ino: %ld, d_off: %ld, d_reclen: %d,d_type: %s, d_name: %s\n",
				entity->d_ino,entity->d_off,entity->d_reclen,buf,entity->d_name);
		memset(buf,0,sizeof(buf));
	}
	
	closedir(dir);
}

void displayFile(char suffix[])
{
	if(suffix == NULL)
	{
		ERROR_INFO("displayFile error: input argument suffix is null\n");
	}
	
	DIR *dir = opendir("directory");
	if(dir == NULL)
	{
		ERROR_INFO("displayFile error: can't open directory\n");
	}
	
	int count = 0;
	struct dirent* entity = NULL;
	while((entity = readdir(dir)) != NULL)
	{
		if((strcmp(entity->d_name,".") == 0)
			|| strncmp(entity->d_name,"..",strlen("..") == 0))
		{
			continue;
		}
		
		if(entity->d_type == DT_REG)
		{
#ifndef _CHANGE_WAY_
			char *str = strstr(entity->d_name,suffix);
			if(str != NULL && *(str + strlen(suffix)) == '\0')
			{
				++count;
				printf("%s\n",entity->d_name);
			}
#else
			char *str = strchr(entity->d_name,'.');
			if(str != NULL && strcmp(str,suffix) == 0)
			{
				++count;
				printf("%s\n",entity->d_name);
			}
#endif
		}
	}
	
	printf("%s count is %d\n",suffix,count);
	closedir(dir);
}

/*Linux的目录是树状结构，遍历每层目录的方式都是一样的，也就是说最简单的遍历方式是递归。
 *递归遍历文件夹程序的重点就是确定递归结束的条件：遍历的文件如果不是目录类型就结束递归。
 */
int displayDir(const char* path)
{
	if(path == NULL)
	{
		return 0;
	}
	puts(path);
	
	DIR *dir = opendir(path);
	if(dir == NULL)
	{
		perror("displayDir error: ");
		return 0;
	}
	
	int count = 0;
	struct dirent* entity = NULL;
	while((entity = readdir(dir)) != NULL)
	{
		if((strcmp(entity->d_name,".") == 0) 
			|| strncmp(entity->d_name,"..",strlen("..")) == 0)
		{
			continue;
		}
		
		if(entity->d_type == DT_REG)
		{
			count++;
			fprintf(stdout,"%s\n",entity->d_name);
		}
		else if(entity->d_type == DT_DIR)
		{
			char newPath[1024] = {0};
			sprintf(newPath,"%s/%s",path,entity->d_name);
			count += displayDir(newPath);       //递归遍历目录及其子目录中的文件
		}
	}
	
	closedir(dir);
	return count;
}