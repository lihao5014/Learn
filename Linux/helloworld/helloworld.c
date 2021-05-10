/*在Linux的世界里，一切设备皆文件。我们可以使用系统调用中I/O的函数，对文件进行相应的open()、close()、write()、read()等操作。
 *打开现有文件或新建文件时，操作系统会返回一个文件描述符（非负整数来）标识已打开的文件。操作文件描述符相当于操作这个描述符
 *所指定的文件。每个程序运行起来后都会先创建一张文件描述符表，并默认打开标准输入、标准输出和标准错误输出这3个设备文件。
 */

/*程序运行起来后标准输入、标准输出和标准错误输出这3个流是默认打开的，它们分别对应的文件描述符是0、1、2。
 *（1）#define STDIN_FILENO   0      //标准输入的文件描述符
 *（2）#define STDOUT_FILENO  1      //标准输出的文件描述符
 *（3）#define STDERR_FILENO  2      //标准错误的文件描述符
 *（4）STDIN_FILENO、STDOUT_FILENO、STDERR_FILENO这三个宏定义在unistd.h头文件中
 */

/*常用系统I/0函数需要的头文件：
 *（1）#include <fcntl.h>      //creat()、open()、SEEK_SET、SEEK_CUR、SEEK_END、O_RDONLY、O_WRONLY、O_CREAT，所在目录"/usr/include/"
 *（2）#include <unistd.h>     //read()、write()、close()、STDIN_FILENO、STDOUT_FILENO、STDERR_FILENO，所在目录"/usr/include/"
 *（3）#include <sys/types.h>  //ssize_t、off_t、pid_t，所在目录"/usr/include/x86_64-linux-gnu/sys/"
 *（4）#include <sys/stat.h>   //struct stat、stat()、fstat()、lstat()，所在目录"/usr/include/x86_64-linux-gnu/sys/"
 */

// #include <fcntl.h>        //没有使用open()打开文件，所以不需要包含fcntl.h头文件
#include <unistd.h>          //read()、write()
// #include <sys/types.h>    //没有获取read()和write()的ssize_t类型返回值，所以不需要包含"sys/types.h"头文件
// #include <sys/stat.h>     //没有获取文件的属性信息struct stat，所以不需要包含"sys/stat.h"头文件
#include <string.h>          //strlen()

#define BUFF_SIZE 128

int main()
{
	const char* str = "hello world!\n";
	write(STDOUT_FILENO,str,strlen(str));
	write(STDOUT_FILENO,"\n",1);
	
	char buf[BUFF_SIZE] = {0};
	write(STDOUT_FILENO,"Please input a string: ",strlen("Please input a string: "));
	read(STDIN_FILENO,buf,BUFF_SIZE);
	write(STDOUT_FILENO,buf,strlen(buf));

	return 0;
}