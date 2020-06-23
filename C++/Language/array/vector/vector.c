#include <stdio.h>

#define SIZE 2

typedef int vector_t[SIZE];

int main(int argc,char* argv[])
{
	vector_t vec = {4,5};
	for(int i=0;i<SIZE;++i)
	{
		printf("%d ",vec[i]);
	}
	puts("");
	
	vector_t* pvec = &vec;
	(*pvec)[0] = 7;
	(*pvec)[1] = 8;
	for(int i=0;i<SIZE;++i)
	{
		printf("%d ",vec[i]);
	}
	putc('\n',stdout);
	
	int arr[10] = {0,1,2,3,4,5,6,7,8,9};
	vector_t *p = (vector_t*)arr;
	for(int j=0;j<5;++j)
	{
		printf("%d ",(*p)[j]);
	}
	puts("\n-----");
	
	for(int j=0;j<5;++j)
	{
		printf("%d ",(*p++)[0]);
	}
	puts("\n-----");
	
	p = (int (*)[2])arr;
	for(int j=0;j<5;++j)
	{
		printf("%d ",*((int*)p));
		p++;
	}
	putchar('\n');
	
	return 0;
}