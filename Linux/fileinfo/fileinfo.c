/*Linux是一个基于文件的操作系统，因此作为文件本身也就有很多属性，如果想要查看某一个文件的属性
 *有两种方式：命令和函数。虽然有两种方式但是它们对应的名字是相同的，叫做stat。另外使用file命令
 *也可以查看文件的一些属性信息。
 */

/*1.查看文件属性的两个命令：
 *（1）file命令：用来识别文件类型，也可用来辨别一些文件的编码格式。它是通过查看文件的头部信息
 *               来获取文件类型，而不是像Windows通过扩展名来确定文件类型的。
 *（2）stat命令：显示文件或目录的详细属性信息包括文件系统状态，比ls命令输出的信息更详细。
 */
				
/*2.stat()和lstat()函数的区别：
 *stat()和lstat()函数的功能和stat命令的功能是一样的，只不过是应用场景不同。这两个函数的区别在于处理软链接
 *文件的方式上，lstat()得到的是软连接文件本身的属性信息，stat()得到的是软链接文件关联的文件的属性信息。
 */

/*3.stat()和fstat()函数的区别：
 *stat()只需要提供文件路径就可以输出文件属性信息，而fstat()函数则需要提供打开文件的文件描述符。
 */

/*4.文件属性结构体struct stat的定义：（使用man 2 stat可以查看）
 * struct stat {
 * 	  dev_t     st_dev;     //ID of device containing file（文件的设备编号）。
 * 	  ino_t     st_ino;     //inode number（inode节点）。
 * 	  mode_t    st_mode;    //protection（文件的类型和存取的权限, 16位整型数）。
 * 	  nlink_t   st_nlink;   //number of hard links（连到该文件的硬连接数目，刚建立的文件值为1）
 * 	  uid_t     st_uid;     //user ID of owner（文件所有者的用户ID）。
 * 	  gid_t     st_gid;     //group ID of owner（文件所属组ID）。
 * 	  dev_t     st_rdev;    //device ID (if special file)（设备类型，若此文件为设备文件，则为其设备编号）。
 * 	  off_t     st_size;    //total size, in bytes（文件大小, 以字节计算）。
 * 	  blksize_t st_blksize; //blocksize for filesystem I/O（文件系统的I/O缓冲区大小）。
 * 	  blkcnt_t  st_blocks;  //number of 512B blocks allocated（占用文件区块的个数, 每一区块大小为512个字节）。
 * 	  time_t    st_atime;   //time of last access（最后一次访问时间）。
 * 	  time_t    st_mtime;   //time of last modification（最后一次修改文件内容时间）。
 * 	  time_t    st_ctime;   //time of last status change（最后一次改变文件属性时间）。
 * };
 */

/*文件的类型信息存储在struct stat结构体的st_mode成员中，它是一个mode_t类型，本质上是一个16位的整数。
 *Linux API中为我们提供了相关的宏函数，通过对应的宏函数可以直接判断出文件是不是某种类型，这些信息都
 *可以通过man文档（man 2 stat）查询到。
 */

/*文件类型与权限存储在st_mode中，可以用S_ISREG(m)宏获取文件类型，判断文件是否为普通文件，
 *参数m为结构体中的st_mode成员，若m为宏功能所指对象，则返回真，不符合为假。
 */

/*5.判断文件类型宏函数:
 *（1）S_ISDIR(m)：判断文件是否为目录文件
 *（2）S_ISCHR(m)：判断文件是否为字符文件
 *（3）S_ISBLK(m)：判断文件是否为块文件
 *（4）S_ISFIFO(m)：判断文件是否为管道文件
 *（5）S_ISLNK(m)：判断文件是否为符号链接文件
 *（6）S_ISSOCK(m)：判断文件是否为套接字文件
 *（7）S_ISREG(m)：判读文件是否为普通文件
 */

/*用户对文件的操作权限也存储在struct stat结构体的st_mode成员中，在这个16位的整数中前4位用于存储文件类型，
 *而后9位用于存储文件访问权限。如果想知道有没有相关权限可以通过按位与(&)操作将这个标志位值取出判断即可。
 */

/*16位整数st_mode中每一位的含义: 
	0-2 bit -- 其他人权限
		- S_IROTH    00004  读权限   100
		- S_IWOTH    00002  写权限   010
		- S_IXOTH    00001  执行权限  001
		- S_IRWXO    00007  掩码, 过滤st_mode中除其他人权限以外的信息
	3-5 bit -- 所属组权限
		- S_IRGRP    00040  读权限
		- S_IWGRP    00020  写权限
		- S_IXGRP    00010  执行权限
		- S_IRWXG    00070  掩码, 过滤st_mode中除所属组权限以外的信息
	6-8 bit -- 文件所有者权限
		- S_IRUSR    00400    读权限
		- S_IWUSR    00200    写权限
		- S_IXUSR    00100    执行权限
		- S_IRWXU    00700    掩码, 过滤st_mode中除文件所有者权限以外的信息
	12-15 bit -- 文件类型
		- S_IFSOCK   0140000 套接字
		- S_IFLNK    0120000 符号链接（软链接）
		- S_IFREG    0100000 普通文件
		- S_IFBLK    0060000 块设备
		- S_IFDIR    0040000 目录
		- S_IFCHR    0020000 字符设备
		- S_IFIFO    0010000 管道
		- S_IFMT     0170000 掩码,过滤st_mode中除文件类型以外的信息
*/

/*6.Linux中文件三级权限宏：（每个文件/目录都有九个访问权限位）
 *（1）S_IRUSR：用户读权限
 *（2）S_IWUSR：用户写权限
 *（3）S_IXUSR：用户可执行权限
 *（4）S_IRWXU：用户读权限,用户写权限,用户可执行权限
 *（5）S_IRGRP：同组读权限
 *（6）S_IWGRP：同组读权限
 *（7）S_IXGRP：同组可执行权限
 *（8）S_IRWXG：同组读权限，同组读权限，同组可执行权限
 *（9）S_IROTH：其他读权限
 *（10）S_IWOTH：其他写权限
 *（11）S_IXOTH：其他可执行权限
 *（12）S_IRWXO：其他读权限，其他写权限，其他可执行权限
 */

#include <pwd.h>      //getpwuid()
#include <grp.h>      //getgrgid()
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>    //struct stat,stat()、fstat()、lstat()
#include <sys/sysmacros.h>    //major(),minor()
#include <stdio.h>       //perror()
#include <stdlib.h>
#include <string.h>      //strerror()
#include <time.h>
#include <errno.h>       //errno全局变量

#define _CHANGE_WAY_
#undef _CHANGE_WAY_

#define BUFF_SIZE 1024

static int getFileSize();
static void getFileType(const char* fileName);
static void getFilePermission(const char* fileName);
static void getFileInfo(const char* fileName);

int main(int argc,char** argv)
{
	getFileSize();
	getFileType("file");
	getFileType("file/logo.bmp");
	
	getFilePermission("file");
	getFilePermission("file/scenery.jpg");
	
	getFileInfo("file");
	getFileInfo("file/china.png");
	
	return 0;
}

int getFileSize()
{
	int ret = -1;
	struct stat fprop;     //定义文件属性结构体变量，以存储文件属性

	//stat()与lstat()只是在软衔接的处理上有区别，其他功能完全相同
#ifndef _CHANGE_WAY_
	ret = stat("file/dict.txt",&fprop);   //获取file/dict.txt文件属性
#else
	ret = lstat("file/dict.txt",&fprop);
#endif
	if(ret == -1)
	{
		perror("getFileSize error: ");
		return -1;
	}
	printf("get file size by stat: %ld\n",fprop.st_size);
	
	const char* str = "getFileSize error: can't open file/dict.txt\n";
	int fb = open("file/dict.txt",O_RDONLY);
	if(fb == -1)
	{
		write(STDERR_FILENO,str,strlen(str));
		return -1;
	}
	
	int size = lseek(fb,0,SEEK_END);
	printf("get file size by lseek: %d\n\n",size);
	
	close(fb);
	return size;
}

void getFileType(const char* fileName)
{
	if(fileName == NULL)
	{
		puts("getFileType error: fileName is null");
		return ;
	}
	printf("getFileType: file name is %s\n",fileName);
	
	int fb = open(fileName,O_RDONLY);   //目录文件只能使用只读打开，而不能使用读写方式打开
	if(fb == -1)
	{
		fprintf(stdout,"getFileType error: %s\n",strerror(errno));
		return ;
	}
	
	struct stat finfo;
	if(fstat(fb,&finfo) == -1)    //fstat()是根据文件描述符，获取文件属性
	{
		perror("getFileType error: ");
		return ;
	}
	
	if(S_ISREG(finfo.st_mode))    //使用宏判断文件类型
	{
		puts("regular file");
	}
	else if(S_ISDIR(finfo.st_mode))
	{
		fputs("directory\n",stdout);
	}
	else if(S_ISCHR(finfo.st_mode))
	{
		printf("charactor device\n");
	}
	else if(S_ISBLK(finfo.st_mode))
	{
		fprintf(stdout,"block device\n");
	}
	else if(finfo.st_mode & S_IFLNK)    //使用按位与操作获取文件类型
	{
		fwrite("symbolic link\n",strlen("symbolic link\n"),1,stdout);
	}
	else if(finfo.st_mode & S_IFIFO)
	{
		write(STDOUT_FILENO,"named pipe(FIFO)\n",strlen("named pipe(FIFO)\n"));
	}
	else if(finfo.st_mode & S_IFSOCK)
	{
		write(STDOUT_FILENO,"Unix domain socket\n",strlen("Unix domain socket\n"));
	}
	else
	{
		puts("unknown file");
	}
	
	putchar('\n');
}

void getFilePermission(const char* fileName)
{
	if(fileName == NULL)
	{
		puts("getFilePermission error: fileName is null");
		return ;
	}
	printf("getFilePermission: file name is %s\n",fileName);

	//尽量使用lstat()来获取文件属性，因为lstat()是获取软连接文件本身的属性信息
	struct stat fprop;
	if(lstat(fileName,&fprop) == -1)
	{
		perror("getFilePermission error: ");
		return ;
	}
	
	char perms[11] = "----------";         //保存文件的三级权限
	switch(fprop.st_mode & S_IFMT){        //使用文件类型掩码S_IFMT，判断文件类型
	case S_IFREG: perms[0] = '-'; break;
	case S_IFDIR: perms[0] = 'd'; break;
	case S_IFCHR: perms[0] = 'c'; break;
	case S_IFBLK: perms[0] = 'b'; break;
	case S_IFIFO: perms[0] = 'p'; break;
	case S_IFLNK: perms[0] = 'l'; break;
	case S_IFSOCK: perms[0] = 's'; break;
	default: perms[0] = '?'; break;
	}
	
	//判断文件所有者权限
	perms[1] = (fprop.st_mode & S_IRUSR) ? 'r' : '-';
	perms[2] = (fprop.st_mode & S_IWUSR) ? 'w' : '-';
	perms[3] = (fprop.st_mode & S_IXUSR) ? 'x' : '-';
	
	//判断所属组权限
	perms[4] = (fprop.st_mode & S_IRGRP) ? 'r' : '-';
	perms[5] = (fprop.st_mode & S_IWGRP) ? 'w' : '-';
	perms[6] = (fprop.st_mode & S_IXGRP) ? 'x' : '-';
	
	//判断其他用户权限
	perms[7] = (fprop.st_mode & S_IROTH) ? 'r' : '-';
	perms[8] = (fprop.st_mode & S_IWOTH) ? 'w' : '-';
	perms[9] = (fprop.st_mode & S_IXOTH) ? 'x' : '-';
	
	perms[10] = '\0';    //字符串结尾标志位
	printf("permission: %s\n",perms);
	
	int linkNum = fprop.st_nlink;    //硬链接计数
	printf("link count: %d\n",linkNum);
	
	char *fileUser = getpwuid(fprop.st_uid)->pw_name;   //文件所有者
	printf("user name: %s\n",fileUser);
	
	char* fileGroup = getgrgid(fprop.st_gid)->gr_name;  //文件所属组
	printf("group name: %s\n",fileGroup);
	
	int fileSize = (int)fprop.st_size;     //文件大小
	printf("file size: %d\n",fileSize);
	
	char *time = ctime(&fprop.st_mtime);   //修改时间
	printf("modify time: %s\n",time);
}

void getFileInfo(const char* fileName)
{
	if(fileName == NULL)
	{
        fprintf(stderr, "getFileInfo error: fileName is null\n");
        return ;
	}
	printf("getFileInfo: file name is %s\n",fileName);
	
	struct stat sb;
    if (lstat(fileName, &sb) == -1) {
        perror("lstat");
        return ;
    }

    printf("ID of containing device:  [%lx,%lx]\n",
			(long)major(sb.st_dev), (long)minor(sb.st_dev));

	printf("File type:                ");
    switch (sb.st_mode & S_IFMT){
    case S_IFBLK:  printf("block device\n");      break;
    case S_IFCHR:  printf("character device\n");  break;
    case S_IFDIR:  printf("directory\n");         break;
    case S_IFIFO:  printf("FIFO/pipe\n");         break;
    case S_IFLNK:  printf("symlink\n");           break;
    case S_IFREG:  printf("regular file\n");      break;
    case S_IFSOCK: printf("socket\n");            break;
    default:       printf("unknown?\n");          break;
    }

    printf("I-node number:            %ld\n", (long)sb.st_ino);

    printf("Mode:                     %lo (octal)\n",
			(unsigned long)sb.st_mode);

    printf("Link count:               %ld\n", (long)sb.st_nlink);
    printf("Ownership:                UID=%ld   GID=%ld\n",
			(long)sb.st_uid, (long)sb.st_gid);

    printf("Preferred I/O block size: %ld bytes\n",
            (long)sb.st_blksize);
    printf("File size:                %lld bytes\n",
            (long long)sb.st_size);
    printf("Blocks allocated:         %lld\n",
            (long long)sb.st_blocks);

    printf("Last status change:       %s", ctime(&sb.st_ctime));
    printf("Last file access:         %s", ctime(&sb.st_atime));
    printf("Last file modification:   %s", ctime(&sb.st_mtime));
	
	putc('\n',stdout);
}

