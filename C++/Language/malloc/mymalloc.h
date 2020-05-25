#ifndef _MYMALLOC_H
#define _MYMALLOC_H

#include <stdlib.h>

#define Malloc(size,type) ((type*)malloc((size)*sizeof(type)))

#define Free(ptr)                \
	do{                          \
		if(NULL != (ptr))        \
		{                        \
			free(ptr);           \
			(ptr) = NULL;        \
		}                        \
	}while(0)

#define myMalloc(size,type)	((type*)doMalloc((size),#type,__FILE__,__LINE__))

void* doMalloc(size_t size,const char *type,const char *file,int line);
void myFree(void *ptr);
void memReport();

#endif //_MYMALLOC_H