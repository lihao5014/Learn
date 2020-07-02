#include "fileopt.h"
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

#define BUFF_SIZE 128

#define ERROR_INFO "filename is null\n"
#define OPEN_FAILED "filename can't open\n"

int getFileSize(const char filename[])
{
	int fb = 0;
	if((fb = open(filename,O_RDONLY)) == -1)
	{
		write(STDOUT_FILENO,OPEN_FAILED,strlen(OPEN_FAILED));
		return -1;
	}
	
	int size = lseek(fb,0,SEEK_END);
	
	close(fb);
	return size;
}

bool copyFile(const char dst[],const char* src)
{
	if(src == NULL)
	{
		write(STDOUT_FILENO,ERROR_INFO,strlen(ERROR_INFO));
		return false;
	}
	
	int read_fb = open(src,O_RDONLY);
	if(-1 == read_fb)
	{
		write(STDERR_FILENO,"src open failed\n",strlen("src open failed\n"));
		return false;
	}
	
	int write_fb = open(dst,O_WRONLY | O_CREAT);
	if(write_fb == -1)
	{
		close(read_fb);
		write(STDERR_FILENO,"dst open failed\n",strlen("dst open failed\n"));
		return false;
	}
	
	int size = 0;
	char buf[BUFF_SIZE] = {0};
	while((size = read(read_fb,buf,BUFF_SIZE)) > 0)
	{
		write(write_fb,buf,size);
		memset(buf,0,sizeof(buf));
	}
	
	close(read_fb);
	close(write_fb);
}

void showFile(const char* filename)
{
	if(filename == NULL)
	{
		write(STDOUT_FILENO,ERROR_INFO,strlen(ERROR_INFO));
		return ;
	}
	
	int fb = open(filename,O_RDONLY);
	if(-1 == fb)
	{
		write(STDERR_FILENO,OPEN_FAILED,strlen(OPEN_FAILED));
		return ;
	}
	
	char buf[BUFF_SIZE] = {0};
	while(read(fb,buf,sizeof(buf)) > 0)
	{
		write(STDOUT_FILENO,buf,strlen(buf));
		memset(buf,0,BUFF_SIZE);
	}
	write(STDOUT_FILENO,"\n",1);
	
	close(fb);
}