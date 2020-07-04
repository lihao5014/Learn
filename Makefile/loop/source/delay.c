#include "delay.h"
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <time.h>
#include <stdio.h>

#define BUFF_SIZE 64

#define PRINT_INFO(str)                              \
	write(STDOUT_FILENO,str,strlen(str))

#define ERROR_INFO(str)                              \
	do{                                              \
		write(STDERR_FILENO,str,strlen(str));        \
		return ;                                     \
	}while(0)

void delayHandle(pFun pfun,unsigned int time)
{
	if(pfun == NULL)
	{
		ERROR_INFO("delayHandle: pfun is null\n");
	}
	
	char buf[BUFF_SIZE] = {0};
	sprintf(buf,"delay time is %u\n",time);
	PRINT_INFO(buf);
	
	PRINT_INFO("---delay handle start---\n");
	sleep(time);                                    //延时时间以秒为单位
	pfun();
	PRINT_INFO("---delay handle end---\n");
}

void executeTime(pFun pfun)
{
	char buf[BUFF_SIZE] = {0};
	clock_t beginTime = clock();
	sprintf(buf,"begin time is %ld\n",beginTime);
	PRINT_INFO(buf);
	
	pfun();

	memset(buf,0,BUFF_SIZE);
	clock_t endTime = clock();
	sprintf(buf,"end time is %ld\n",endTime);
	PRINT_INFO(buf);
	
	memset(buf,0,BUFF_SIZE);
	double total = (double)(endTime - beginTime);
	sprintf(buf,"total time is %f\n",total);          //精确到毫秒
	PRINT_INFO(buf);
}