#include <string.h>
#include <stdio.h>

void* myMemccpy(void* dst,const void* src,int data,unsigned int size);

int main()
{
	char a[]="string[a]";
	char b[]="string(b)";
	
	char* result = NULL;


	result = memccpy(a, b,'b',sizeof(b));
	printf("memccpy():%s, result =%c\n", a,*result);

	result = myMemccpy(a, b,'b',sizeof(b));
	printf("memccpy():%s, result =%c\n", a,*result);	
	
	return 0;
}

void* myMemccpy(void* dst,const void* src,int data,unsigned int size)
{
	if(dst == NULL || src == NULL){
		printf("myMemccpy warn: dst=NULL or src=NULL\n");
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