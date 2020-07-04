#include "delay.h"
#include <stdio.h>
#include <stdlib.h>

typedef void (*pFunc)(const char* str);
typedef unsigned long (*pCallback)(unsigned int num);

static pFunc s_pfunc = NULL;
static pCallback s_pcallback = NULL;

static void register_callback(pFunc pfunc,pCallback pcallback);
static void funcwrapper();

static void print(const char* str);
static unsigned long factorial(unsigned int num);

int main(int argc,char* argv[])
{
	register_callback(print,NULL);
	delayHandle(funcwrapper,2);
	
	register_callback(NULL,factorial);
	executeTime(funcwrapper);
	
	return 0;
}

void register_callback(pFunc pfunc,pCallback pcallback)
{
	s_pfunc = pfunc;
	s_pcallback = pcallback;
}

void funcwrapper()
{
	if(s_pfunc != NULL)
	{
		s_pfunc("hello world\n");
	}
	
	if(s_pcallback != NULL)
	{
		int num = 12;
		printf("factorial: num =%d\n",num);
		unsigned long result = s_pcallback(num);
		printf("factorial: result =%lu\n",result);
	}
}

unsigned long factorial(unsigned int num)
{
	if(num <= 0)
	{
		puts("factorial: num is less than one");
		exit(-1);
	}
	
	if(num == 1)
	{
		return 1;
	}
	return num * factorial(num - 1);
}

void print(const char* str)
{
	if(str == NULL)
	{
		puts("print: str is null\n");
		return ;
	}
	
	fputs(str,stdout);
}