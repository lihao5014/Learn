/*Linux文件类型和文件的文件名所代表的意义是两个不同的概念，在linux中文件类型与文件扩展名没有关系。
 *它不像Windows那样是依靠文件后缀名来区分文件类型的，在linux中文件名只是为了方便操作而取得的名字。
 */

//Linux中的7种文件类型：普通文件[-]、目录文件[d]、链接文件[l]、管道[p]、套接字[s]、字符设备[c]、块设备[b]

/*1.文件打开的方式flags：
 *（1）O_RDONLY：以只读方式打开。
 *（2）O_WRONLY：以只写方式打开。
 *（3）O_RDWR： 以可读、可写的范式打开。
 *（4）O_CREAT：如果文件不存在则创建文件，使用此选项时需要使用mode说明文件创建的权限。
 *（5）O_EXCL：如果同时指定了O_CREAT，文件存在则出错。
 *（6）O_TRUNC：如果文件存在，则清空文件内容。
 *（7）O_APPEND：写文件时，数据添加到文件末尾。
 *（8）O_NONBLOCK：当打开的文件是FIFO、字符设备、块设备时，此选项为非阻塞标志位
 */

/*2.新建文件时指定文件的权限mode:
 *（1）S_IRWXU：文件所以者的读、写、可执行权限
 *（2）S_IRUSR：文件所以者的读权限
 *（3）S_IWUSR：文件所以者的写权限
 *（4）S_IXUSR：文件所以者的可执行权限
 *
 *（5）S_IRWXG：文件所以者同组用户的读、写、可执行权限
 *（6）S_IRGRP：文件所以者同组用户的读权限
 *（7）S_IWGRP：文件所以者同组用户的写权限
 *（8）S_IXGRP：文件所以者同组用户的可执行权限
 *
 *（9）S_IRWXO：其他组用户的读、写、可执行权限
 *（10）S_IROTH：其他组用户的读权限
 *（11）S_IWOTH：其他组用户的写权限
 *（12）S_IXOTH：其他组用户的可执行权限
 */

#include <fcntl.h>          //open()、O_RDONLY、OWRONLY、O_CREAT、S_IRWXU、S_IRGRP、S_IWGRP、S_IROTH、S_IWOTH
#include <unistd.h>         //read()、write()、close()
#include <sys/types.h>      //ssize_t
#include <sys/stat.h>       //没有获取文件的属性，所以可以不用包含sys/stat.h头文件
#include <string.h>

#define BUFF_SIZE 1024

int main(void)
{
	char msg[] = "copy file.txt to copy.txt\n";
	write(STDOUT_FILENO,msg,sizeof(msg) - 1);    //减1是为了去掉字符串后面的'\0'结尾标志，以避免输出打印乱码
	
	const char* error_info = "open file.txt error\n";
	int read_fb = open("./file.txt",O_RDONLY);        //open()失败返回-1，成功返回文件描述符
	if(read_fb == -1)
	{
		write(STDOUT_FILENO,error_info,strlen(error_info));
		return -1;
	}
	
	error_info = "open copy.txt failed\n";
	int write_fb = open("./copy.txt",O_WRONLY | O_CREAT,S_IRWXU | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);   //新建的copy.txt文件的三级权限-rwxrw-rw-或766
	if(write_fb == -1)
	{
		write(STDERR_FILENO,error_info,strlen(error_info));
		return -1;
	}
	
	ssize_t size = 0;
	char buf[BUFF_SIZE] = {0};
	while((size = read(read_fb,buf,sizeof(buf))) > 0)
	{
		write(write_fb,buf,size);
		memset(buf,0,BUFF_SIZE);
	}
	
	close(read_fb);
	close(write_fb);
	
	return 0;
}