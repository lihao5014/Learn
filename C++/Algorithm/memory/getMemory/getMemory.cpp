#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

char* getMemory(char **p,const int n);
char* getMemory(char *&p,const int n);
char* myStrcpy(char *dst,const char* src,const int n);
void myFree(char *&p);
void myFree(char **p);

int main()
{
	char* p = NULL;
	const char* str1 = "hello world";
	char str2[] = "hello C++";
	
	getMemory(&p,strlen(str1)+1);
	myStrcpy(p,str1,strlen(str1)+1);
	printf("%s\n",p);
	myFree(p);
	
	getMemory(p,sizeof(str2));
	myStrcpy(p,str2,sizeof(str2));
	printf("%s\n",p);
	myFree(p);
	
	return 0;
}

char* getMemory(char **p,const int n)
{
	assert(n > 0);
	if(*p != NULL ){
		free(*p);
		*p = NULL;
	}
	
	*p = (char*)malloc(n);
	if(*p == NULL){
		printf("error: malloc failed!\n");
	}
	return *p;
}

char* getMemory(char *&p,const int n)
{
	assert(n > 0);
	if(p != NULL ){
		free(p);
		p = NULL;
	}
	
	p = (char*)malloc(n);
	if(p == NULL){
		printf("error: malloc failed!\n");
	}
	return p;
}

char* myStrcpy(char *dst,const char* src,const int n)
{
	assert(dst != NULL || src != NULL || n >0);
	
	char* p = dst;
	while((*p++ = *src++) != '\0');
	
	return dst;	
}

void myFree(char *&p)
{
	if(p != NULL){
		free(p);
		p = NULL;
	}
}

void myFree(char **p)
{
	if(*p != NULL){
		free(*p);
		*p = NULL;
	}
}

