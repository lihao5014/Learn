/*系统IO操作的是int文件描述符，而标准IO操作的是FILE*流。
 *fileno()：将文件指针FILE*转换为文件描述符。
 *fdopen()：将文件描述符转换为流FILE*。
 *perror()：linux系统调用失败一般返回-1，且会置全局变量errno为特定的错误码，
 *          可以使用perror()或通过strerror(errno)打印错误提示。
 */

/*fopen()函数打开文件的模式mode：
 *（1）r、rb: 只读方式打开，文件必须已存在。
 *（2）w、wb: 只写方式打开，如果文件不存在则创建，如果文件已存则清空重写。
 *（3）a、ab: 只能在文件末尾追加数据，如果文件不存在则创建。
 *（4）r+、rb+、r+b: 读写方式打开，文件必须已存在。
 *（5）w+、w+b、wb+: 读写方式打开，如果文件不存在则创建，如果文件已存在清空重写。
 *（6）a+、a+b、ab+: 读和追加方式打开，如果文件不存在则创建。
 *（7）b用于区分二进制文件和文本文件，这一点在DOS、Windows系统中是有区分的，
 *     但Linux不区分二进制文件和文本文件。
 */

/*标准IO中流的3种缓存类型：
 *（1）全缓存：当填满标准IO缓存区后才进行实际IO操作。对于放置在磁盘上的普通文件，用标准IO打开时
 *             默认是全缓存的。当缓冲区已满或执行fflush()刷新缓冲区时才会进行磁盘操作。
 *（2）行缓存：当输入和输出中遇到换行符时执行IO操作。标准输入输出流就是使用行缓存的典型例子。
 *（3）无缓存：在对流的读写时会立刻操作实际的文件。标准错误流是不带缓冲的，这就使得错误信息可以
 *             立刻显示在终端上，而不管输出的内容是否包含换行符。
 */

#include <fcntl.h>         //creat(),open()
#include <unistd.h>        //read(),write()
#include <sys/types.h>     //ssize_t,off_t
#include <stdio.h>         //fileno(),fdopen()
#include <stdlib.h>
#include <string.h>        //strerror()
#include <errno.h>         //errno全局变量

#define BUFF_SIZE 1024

static void fileno_test();
static void fdopen_test();

int main()
{
	fileno_test();
	fdopen_test();
	
	return 0;
}

void fileno_test()
{
	printf("stdin <-> %d\n",fileno(stdin));
	printf("stdout <-> %d\n",fileno(stdout));
	printf("stderr <-> %d\n",fileno(stderr));
	
	FILE* fp = fopen("file/fileno_test.txt","w+");
	if(NULL == fp)
	{
		perror("fileno_test error: ");
		abort();
	}
	
	int fb = fileno(fp);   //流FILE*转换为文件描述符
	if(fb == -1)
	{
		fclose(fp);
		puts("fileno_test error: FILE* to file descriptor failed");
		exit(-1);
	}
	
	char buf[BUFF_SIZE] = "time is 2021/05/20\n";
	write(fb,"hello world\n",strlen("hello world\n"));
	write(fb,buf,strlen(buf));
	
	lseek(fb,0,SEEK_SET);    //文件指针移动到文件开头
	memset(buf,0,BUFF_SIZE);
	
	ssize_t size = 0;
	while((size = read(fb,buf,BUFF_SIZE)) > 0)
	{
		puts(buf);
		memset(buf,0,BUFF_SIZE);
	}
	
	off_t offset = lseek(fb,0,SEEK_END);   //将文件指针移动到文件末尾，以获取文件大小
	fprintf(stdout,"fileno_test: fileno_test.txt size is %ld\n",offset);
	
	fclose(fp);
}

void fdopen_test()
{
	FILE* stdin_fp = fdopen(STDIN_FILENO,"r");    //将文件描述符转换为FILE*
	if(stdin_fp == NULL)
	{
		fputs("fdopen_test error: STDIN_FILENO to FILE* failed\n",stdout);
		abort();
	}
	
	char buf[BUFF_SIZE] = "fdopen_test error: STDOUT_FILENO to FILE* failed\n";
	FILE* stdout_fp = fdopen(STDOUT_FILENO,"w");    //将文件描述符转换为FILE*
	if(stdout_fp == NULL)
	{
		fprintf(stdout,"%s",buf);
		exit(-1);
	}
	
	memset(buf,0,BUFF_SIZE);
	printf("Please input a text: ");
	if(fgets(buf,BUFF_SIZE,stdin_fp) != NULL)
	{
		fwrite(buf,strlen(buf),1,stdout_fp);
	}
	
	int fb = open("file/fdopen_test.txt",O_RDWR | O_CREAT,S_IRWXU | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);
	if(fb == -1)
	{
		perror("fdopen_test error: ");
		abort();
	}
	
	FILE* fp = fdopen(fb,"w+");
	if(fp == NULL)
	{
		close(fb);
		printf("fdopen_test error: %s\n",strerror(errno));
		exit(-1);
	}
	
	fwrite("hello world\n",strlen("hello world\n"),1,fp);
	fputs("time is 2021.05.21",fp);
	fprintf(fp,"study fdopen usage");
	
	fseek(fp,0,SEEK_SET);   //文件指针移动到文件开头
	memset(buf,0,sizeof(buf));
	
	size_t size = 0;
	while((size = fread(buf,BUFF_SIZE,1,fp)) > 0)
	{
		fwrite(buf,size,1,stdout);
		memset(buf,0,BUFF_SIZE);
	}
	
	//刚读取完文件中的内容，文件指针在文件末尾所以可以直接使用ftell()获取文件大小
	fprintf(stdout,"fdopen_test: fdopen_test.txt size is %ld\n",ftell(fp));
	
	close(fb);
}