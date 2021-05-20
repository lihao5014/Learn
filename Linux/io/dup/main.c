//dup2函数在MingW编译器环境中不能生效，复制新的文件描述符总是失败。

#include <fcntl.h>        //creat(),open()
#include <unistd.h>       //dup(),dup2(),read(),write()
#include <sys/types.h>    //ssize_t
#include <sys/stat.h>     //struct stat,fstat()
#include <stdio.h>        //sprintf()
#include <stdlib.h>
#include <string.h>

#define BUFF_SIZE 1024

#define ERROR_INFO(str)                          \
	do{                                          \
		write(STDERR_FILENO,str,strlen(str));    \
		return ;                                 \
	}while(0)

#define PRINT_INFO(str)  \
	write(STDOUT_FILENO,str,strlen(str))

#define SAVE_TO_FILE(fb,str) write(fb,str,strlen(str))

/*dup()和dup()2的作用是复制一个文件描述符，使新的文件描述符也指向旧的文件描述符所标识的文件。
 *操作这两个文件描述符的任何一个，都能操作它所对应的文件。可以用于实现重定向标准输出到文件中。
 */
static void dup_test1();
static void dup_test2();
static void dup_test3();

//dup()和dup2()的用法与功能完全一直，但是dup2()复制出来的新文件描述符可以指定任意一个合法的数字。
static void dup2_test1();
static void dup2_test2();

int main(void)
{
	dup_test1();
	dup_test2();
	dup_test3();
	
	dup2_test1();
	dup2_test2();
	
	return 0;
}

//通过dup()复制的文件描述符是调用进程文件描述符表中最小可用的文件描述符，最终新旧文件描述符都指向同一个文件。
void dup_test1()
{
	//使用O_CREAT需要使用mode说明文件创建的权限。否则创建的文件再次打开时，由于权限不够而打开失败
	int old_fb = open("file/dup_test.txt",O_WRONLY | O_APPEND | O_CREAT,S_IRWXU | S_IRWXG | S_IRWXO);
	if(-1 == old_fb)
	{
		PRINT_INFO("dup_test1 error: open file/dup_text.txt failed!\n");
		return ;
	}
	write(old_fb,"hello world\n",strlen("hello world\n"));
	
	char buf[BUFF_SIZE] = {0};
	sprintf(buf,"---old_fb =%d\n",old_fb);
	write(STDOUT_FILENO,buf,strlen(buf));
	
	int new_fb = dup(old_fb);
	if(-1 == new_fb)
	{
		close(old_fb);
		ERROR_INFO("dup_test1 error: dup old_fb failed!\n");
	}
	write(new_fb,"time is 2021/05/19\n",strlen("time is 2021/05/19\n"));

	memset(buf,0,sizeof(buf));
	sprintf(buf,"---new_fb =%d\n",new_fb);
	PRINT_INFO(buf);
	
	close(old_fb);   //退出函数时，新旧两个文件描述符都需要关闭
	close(new_fb);
}

void dup_test2()
{
	int read_fb = open("file/dup_test.txt",O_RDWR);    //O_RDWR与O_RDONLY | O_WRONLY不等效
	if(-1 == read_fb)
	{
		ERROR_INFO("dup_test2 error: open file/dup_test.txt failed!\n");
	}
	
	//其实read_fb已经可以进行读写操作了，但这里新建一个文件描述符负责写操作，使用于更加明确。
	int write_fb = dup(read_fb);
	if(write_fb == -1)
	{
		close(read_fb);
		PRINT_INFO("dup_test2 error: dup read_fb failed!\n");
		return ;
	}
	
	char *pbuf = (char*)malloc(BUFF_SIZE);
	if(NULL == pbuf)
	{
		close(read_fb);
		close(write_fb);
		ERROR_INFO("dup_test2 error: pbuf malloc failed!\n");
	}
	
	memset(pbuf,0,BUFF_SIZE);
	ssize_t size = read(read_fb,pbuf,BUFF_SIZE);
	write(STDOUT_FILENO,pbuf,size);
	write(STDOUT_FILENO,"\n",1);
	
	lseek(write_fb,0,SEEK_END);
	
	memset(pbuf,0,BUFF_SIZE);
	strcpy(pbuf,"write a string to file\n");
	SAVE_TO_FILE(write_fb,pbuf);
	
	if(pbuf != NULL)
	{
		free(pbuf);
		pbuf = NULL;
	}
	
	close(read_fb);
	close(write_fb);
}

void dup_test3()
{
	int old_fb = open("file/dup_test.txt",O_WRONLY | O_APPEND);
	if(-1 == old_fb)
	{
		ERROR_INFO("dup_test3 error: open file/dup_test.txt failed!\n");
	}
	puts("output to standard device");
	printf("dup_test3: old_fb =%d\n",old_fb);
	
	//创建新的文件描述符，以保存输出设备的文件指针，方便以后还原
	int save_fb = dup(STDOUT_FILENO);

	/*STDOUT_FILENO本来指向标准输出设备，把1文件描述符关闭，就是说1不再指向标准输出设备。
	 *这样1文件描述符就空闲了，它就成为最小可用的文件描述符。
	 */
	close(STDOUT_FILENO);
	
	/*dup会将当前系统中可以创建的最小文件描述符返回给new_fb，由于1文件描述符已经被关闭掉，
	 *所以这里获取出来的是STDOUT_FILENO描述符的值。
	 */
	int new_fb = dup(old_fb);
	if(new_fb == -1)
	{
		close(old_fb);
		PRINT_INFO("dup_test3 error: dup old_fb failed!\n");
		return ;
	}
	close(old_fb);    //关闭多余的文件描述符
	
	/*由于puts/printf等标准IO函数绑定的都是1文件描述符，而现在1文件描述符标识的已经不再是输出设备，
	 *而变成了一个文件。所以再使用puts和printf打印信息时，信息不会再打印到输出设备中，而是被重定向
	 *写到了dup_test.txt文件中。
	 */
	puts("output to dup_test.txt");
	printf("dup_test3: new_fb is %d\n",new_fb);
	
	//dup与dup2重定向功能，在Windows环境中使用MingW编译器测试时，必须要刷新输出缓存，才能重定向到文件中
	fflush(stdout);
	
	close(new_fb);
	if(dup(save_fb) == -1)    //重新将1文件描述符绑定到输出设备上
	{
		ERROR_INFO("dup_test3 error: recover 1 to standard device failed\n");
	}
	PRINT_INFO("dup_test3: recover 1 to standard device successful\n");
}

void dup2_test1()
{
	int old_fb = open("file/dup2_test.txt",O_WRONLY | O_APPEND | O_CREAT,S_IRWXU | S_IRWXG | S_IRWXO);
	if(old_fb == -1)
	{
		ERROR_INFO("dup2_test1 error: open file/dup2_test.txt failed!\n");
	}
	
	char buf[32] = {0};
	sprintf(buf,"---old_fb =%d---\n",old_fb);
	write(STDOUT_FILENO,buf,strlen(buf));
	write(old_fb,"dup2 test\n",strlen("dup2 test\n"));
	
	int new_fb = 8;
	if(dup2(old_fb,new_fb) != new_fb)
	{
		close(old_fb);
		ERROR_INFO("dup2_test1 error: dup2 old_fb failed\n");
	}
	
	memset(buf,0,sizeof(buf));
	sprintf(buf,"---new_fb =%d---\n",new_fb);
	write(STDOUT_FILENO,buf,strlen(buf));
	SAVE_TO_FILE(new_fb,"dup2 can appoint file descriable num\n");
	
	close(old_fb);    //关闭时，两个文件描述符都得关闭
	close(new_fb);
}

void dup2_test2()
{
	int file_fb = open("file/dup2_test.txt",O_WRONLY);
	if(-1 == file_fb)
	{
		ERROR_INFO("dup2_test2 error: open file/dup2_test.txt failed\n");
	}
	
	int save_fb = dup2(STDOUT_FILENO,10);
	if(10 != save_fb)
	{
		close(file_fb);
		PRINT_INFO("dup2_test2 error: save standard output device successful\n");
		return ;
	}
	close(STDOUT_FILENO);     //关闭标准输出设备
	
	const char* info = "close standard output device\n";
	write(save_fb,info,strlen(info));
	
	int stdout_fb = 1;     //stdout_fb定义为标准输出设备文件描述符
	if((stdout_fb = dup2(file_fb,1)) != 1)    //将标准输出设备重定向到dup2_test.txt文件中
	{
		close(file_fb);
		ERROR_INFO("dup2_test2 error: can't redirect\n");
	}
	close(file_fb);
	
	puts("write to file");
	printf("save_fb =%d, stdout_fb =%d\n",save_fb,stdout_fb);
	fputs("data is 2021/05/20\n",stdout);
	fprintf(stdout,"linux io test\n");
	fflush(stdout);
	
	close(stdout_fb);
	if(dup(save_fb) == -1)
	{
		ERROR_INFO("dup2_test2 error: recover standard output device failed\n");
	}
	PRINT_INFO("dup2_test2: recover standard output device successful\n");
}