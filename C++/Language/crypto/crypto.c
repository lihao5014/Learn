#include "crypto.h"
#include <stdio.h>
#include <string.h>

#define OFFSET 5

int cryptoNum(int num,int key)
{
	return num ^ key;
}

#if defined(_BETTER_)
bool cryptoStr(const char src[],char* const dts,int key)
{
	if(src == NULL || dts == NULL)
	{
		printf("cryptoStr warn: src or dts is null\n");
		return false;
	}
	
	for(int i=0;i<strlen(src);++i)
	{
		*(dts + i) = *(src + i) ^ key;
	}
	dts[strlen(src)] = src[strlen(src)];
	
	return true;
}
#else
char* cryptoStr(const char *str,int key)
{
	if(str == NULL)
	{
		puts("cryptoStr warn: str is null");
		return NULL;
	}
	
	int size = strlen(str) + 1;           //定义在开头，可以减少几次strlen函数的调用
	char *p = (char*)malloc(size);
	if(NULL == p)
	{
		fputs("cryptoStr warn: p malloc failed\n",stdout);
		return NULL;
	}
	memset(p,0,size);
	
	for(int i=0;i<size-1;++i)
	{
		p[i] = str[i] ^ key;
	}
	p[size - 1] = '\0';
	
	return p;
}
#endif

bool encryptStr(const char *src,char *dts,int key)
{
	if(src == NULL || dts == NULL)
	{
		fprintf(stdout,"encrytStr warn: src or dts is null\n");
		return false;
	}
	
	for(int i=0;i<strlen(src);++i)
	{
		dts[i] = src[i] + i + OFFSET;
	}
	dts[strlen(src)] = '\0';
	
	return true;
}

bool decryptStr(const char* src,char *dts,int key)
{
	if(src == NULL || dts == NULL)
	{
		fputs("decryptStr warn: src or dts is null\n",stdout);
		return false;
	}
	
	for(int i=0;i<strlen(src);++i)
	{
		*(dts + i) = *(src + i) - i - OFFSET;
	}
	*(dts + strlen(src)) = '\0';
	
	return true;
}