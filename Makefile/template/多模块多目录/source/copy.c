#include "copy.h"
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <stdlib.h>

#define BUFF_SIZE 1024

#define STRING_ERROR "PRINT_INFO error: str is null\n"

#define PRINT_INFO(str)                                                  \
	do{                                                                  \
		if(str == NULL)                                                  \
		{                                                                \
			write(STDERR_FILENO,STRING_ERROR,strlen(STRING_ERROR));      \
			exit(-1);                                                    \
		}                                                                \
		write(STDOUT_FILENO,str,strlen(str));                            \
	}while(0)

void showFile(const char* filename)
{
	if(filename == NULL)
	{
		PRINT_INFO("showFile error: filename is null");
		return ;
	}
	
	int fb = 0;
	if((fb = open(filename,O_RDONLY)) == -1)
	{
		PRINT_INFO("showFile error: open file failed\n");
		return ;
	}
	
	char buf[BUFF_SIZE] = {0};
	while(read(fb,buf,BUFF_SIZE) > 0)
	{
		write(STDOUT_FILENO,buf,strlen(buf));
		memset(buf,0,sizeof(buf));
	}
	write(STDOUT_FILENO,"\n",strlen("\n"));
}

bool copyFile(const char* src,const char* dst)
{
	if(src == NULL || dst == NULL)
	{
		PRINT_INFO("copyFile error: src or dst is null\n");
		return false;
	}
	
	int read_fb = open(src,O_RDONLY);
	if(-1 == read_fb)
	{
		PRINT_INFO("copyFile error: src can't open\n");
		return false;
	}
	
	int write_fb = open(dst,O_WRONLY | O_CREAT);
	if(write_fb == -1)
	{
		close(read_fb);
		PRINT_INFO("copy error: dst can't open\n");
		return false;
	}
	
	int size = 0;
	char buf[BUFF_SIZE] = {0};
	while((size = read(read_fb,buf,sizeof(buf))) > 0)
	{
		write(write_fb,buf,size);
		memset(buf,0,BUFF_SIZE);
	}
	
	close(read_fb);
	close(write_fb);
	return true;
}