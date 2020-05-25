#include <string.h>
#include <stdio.h>

int myMemcmp(const void* src1,const void* src2,unsigned int size);

int main()
{
	char a[]="string--[a]";
	char b[]="string--(b)";
	
	int result;


	result = memcmp(a,"string123",10);
	printf("memcmp():%s, %s, result =%d\n",a,"string123",result);

	result = myMemcmp(a,"string123",10);;
	printf("memcmp():%s, %s, result =%d\n",a,"string123",result);	
	
	return 0;
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