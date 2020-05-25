#include "mystring.h"
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

int myStrlen(const char* str)
{
	if(str == NULL){
		printf("myStrlen error: str=NULL\n");
		return -1;
	}
	
	int len = 0;
	const char *p = str;
	for(;*p++ != '\0';len++);
	return len;
}

char* myStrcpy(char *dst,const char* src)
{
	assert(dst != NULL && src != NULL);
	
	char *p = dst;
	while((*p++ = *src++) != '\0');
	return dst;
}

bool myStrcmp(const char* str1,const char* str2)
{
	if(str1 == NULL || str2 == NULL){
		printf("myStrcmp warn: str1=NULL or str2=NULL\n");
		return false;
	}
	
	if(str1 == str2){
		return true;
	}
	
	bool flag = true;
	while(*str1 != '\0' && *str2 != '\0'){
		if(*str1++ != *str2++){
			flag = false;
			break;
		}
		flag = true;
	}
	return flag;
}

char* myStrcat(char* dst,const char* src)
{
	assert(dst != NULL && src != NULL);
	
	char *p = dst;
	while(*p != '\0') p++;
	while((*p++ = *src++) != '\0');
	return dst;
}

char* myStrncpy(char *dst,const char *src,int n)
{
	assert(dst != NULL && src != NULL && n > 0 && n <= myStrlen(src));
	
	char* p = dst;
	while(n--){
		*p++ = *src++;
	}
	*p = '\0';
	return dst;
}

bool myStrncmp(const char *str1,const char *str2,int n)
{
	if(str1 == NULL || str2 == NULL || n <0 || n > myStrlen(str2)){
		printf("myStrcmp warn: str1=NULL or str2=NULL or n is illegal\n");
		return false;
	}
	
	if(str1 == str2){
		return true;
	}
	
	bool flag = true;
	while(n--){
		if(*str1++ != *str2++){
			flag = false;
			break;
		}
		flag = true;
	}
	
	return flag;
}

char* myStrncat(char* dst,const char* src,int n)
{
	assert(dst != NULL && src != NULL && n > 0 && n <= myStrlen(src));
	
	char* p = dst;
	while(*p != '\0') p++;
	while(n--){
		*p++ = *src++;
	}
	*p = '\0';
	return dst;
}

char* myStrchr(const char* src,const char chr)
{
	if(src == NULL){
		printf("myStrchr warn: str=NULL\n");
		return NULL;		
	}
	
	do{
		if(*src == chr){
			return (char*)src;
		}
	}while(*src++ != '\0');

	return NULL;
}

char* myStrstr(const char* src,const char* str)
{
	assert(src != NULL && str != NULL);
	
	if(myStrlen(src) < myStrlen(str)){
		return NULL;
	}
	
	const char* p = src;
	const char* q = str;
	for(;*p != '\0';p++){
		for(;*q != '\0';q++){
			if(*p != *q){
				q = str;
				break;
			}
			src = p;
		}
		if(*q == '\0'){
			return (char*)src;
		}
	}
	return NULL;
}

char* myStrrchr(const char* src,const char chr)
{
	if(src == NULL){
		printf("myStrrchr warn: str=NULL\n");
		return NULL;		
	}
	
	int len = myStrlen(src);
	const char *p = src+len-1;
	while(len--){
		if(*p == chr){
			return (char*)p;
		}
		p--;
	}
	return NULL;
}

char* myStrpbrk(const char* src,const char* key)
{
	assert(src != NULL && key != NULL);
	
	const char *p = NULL;
	for(;*src != '\0';src++){
		for(p = key;*p++ != '\0';p++){
			if(*src == *p){
				return (char*)src;
			}
		}
	}
	return NULL;
}

void strShow(const char *str)
{
	if(str == NULL){
		return ;
	}
	
	const char *p = str;
	for(;*p != '\0';p++){
		printf("%c",*p);
	}
	printf("\n");
}

char* strLeft(const char* src,const int n)
{
	assert(src != NULL && n >0 && n <= myStrlen(src));
	
	char* p = (char*)malloc(sizeof(char)*n+1);
	return myStrncpy(p,src,n);
}

char* strRight(const char* src,const int n)
{
	assert(src != NULL && n >0 && n <= myStrlen(src));
	
	char* p = (char*)malloc(sizeof(char)*n+1);
	int len = myStrlen(src);
	return myStrncpy(p,src+len-n,n);
}

char* strMid(const char* src,const int index,const int n)
{
	assert(src != NULL && index >= 0 && index < myStrlen(src)
		&& n >0 && n <= myStrlen(src));
		
	char *p = (char*)malloc(sizeof(char)*n+1);
	return myStrncpy(p,src+index,n);
}

bool startWith(const char* src,const char* str)
{
	assert(src != NULL && str != NULL);
	
	return myStrncmp(src,str,myStrlen(str));
}

bool endWith(const char* src,const char* str)
{
	assert(src != NULL && str != NULL);
	
	char* p = strRight(src,myStrlen(str));
	return myStrcmp(p,str);
}

bool contains(const char* src,const char* str)
{
	assert(src != NULL && str != NULL);
	
	return myStrstr(src,str) == NULL ? false : true;
}