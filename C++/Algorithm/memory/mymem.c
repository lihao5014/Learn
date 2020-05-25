#include "mymem.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void* myMemset(void* dst,data_t data,unsigned int size)
{
	if(dst == NULL){
		printf("myMemset warn: dst=NULL\n");
		return NULL;		
	}
	
	char* p = (char*)dst;
	while(size--){
		*p++ = data;
	}
	
	return dst;
}

void* myMemcpy(void* dst,const void* src,unsigned int size)
{
	if(dst == NULL || src == NULL){
		printf("myMemccpy warn: dst=NULL or src=NULL\n");
		return NULL;		
	}
	
	if(dst == src){
		return dst;
	}
	
	char* p = (char*)dst;
	char* q = (char*)src;
	while(size--){
		*p++ = *q++;
	}
	
	return dst;
}

void* myMemccpy(void* dst,const void* src,data_t data,unsigned int size)
{
	if(dst == NULL || src == NULL){
		printf("myMemccpy warn: dst=NULL\n");
		return NULL;		
	}
	
	char* p = (char*)dst;
	if(dst == src){
		while(size--){
			if(*p++ == data){
				return p;
			}
		}
		return NULL;
	}
	
	char* q = (char*)src;
	while(size--){
		if((*p++ = *q++) == data){
			return p;
		}
	}
	
	return NULL;
}

void* myMemmove(void* dst,const void* src,unsigned int size)
{
	if(dst == NULL || src == NULL){
		printf("myMemmove warn: dst=NULL or src=NULL\n");
		return NULL;		
	}
	
	if(dst == src){
		return dst;
	}
	
	if(dst > src && dst < src+size){
		char* p = (char*)dst+size;
		char* q = (char*)src+size;
		while(size--){
			*--p = *--q;
		}
	}else{
		char* p = (char*)dst;
		char* q = (char*)src;
		while(size--){
			*p++ = *q++;
		}
	}
	return dst;
}

void* myMemchr(const void* src,data_t data,unsigned int size)
{
	if(src == NULL){
		printf("myMemchr warn: src=NULL\n");
		return NULL;		
	}
	
	char* p = (char*)src;
	while(size--){
		if(*p == data){
			return p;
		}
		p++;
	}
	
	return NULL;
}

int myMemcmp(const void* src1,const void* src2,unsigned int size)
{
	if(src1 == NULL || src2 == NULL){
		printf("myMemccpy warn: src1=NULL or src2=NULL\n");
		return 0;		
	}
		
	const char* p = (char*)src1;
	const char* q = (char*)src2;
	for(int i=0;i<size;++i,++p,++q){
		if(*p != *q){
			return *p > *q ? 1 : -1;
		}
	}
	
	return 0;
}

void* getMemory(void** dst,unsigned int size)
{
	*dst = (char*)malloc(size);
	if(*dst == NULL){
		return NULL;
	}
	
	return *dst;
}

void myFree(void** dst)
{
	if(*dst != NULL){
		free(*dst);
		*dst = NULL;
	}
}
