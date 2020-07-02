#include "fileopt.h"
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <stdio.h>         // π”√sprintf∫Õvsprintf

#define BUFF_SIZE 128

int main(void)
{
	char buf[BUFF_SIZE] = {0};
	write(STDOUT_FILENO,"Please input a string: \n",strlen("Please input a string: \n"));
	write(STDOUT_FILENO,"\n",1);
	read(STDIN_FILENO,buf,BUFF_SIZE);
	write(STDOUT_FILENO,buf,strlen(buf));
	
	const char* str = "hello world\n";
	write(STDOUT_FILENO,str,strlen(str));
	
	showFile("test/text.txt");
	
	int file_size = getFileSize("test/text.txt");
	memset(buf,0,sizeof(buf));
	sprintf(buf,"text.txt file size is %d\n",file_size);
	write(STDOUT_FILENO,buf,strlen(buf));
	
	copyFile("test/copy.txt","test/text.txt");
	showFile("test/copy.txt");
	
	return 0;
}