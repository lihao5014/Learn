#include "mymem.h"
#include <stdio.h>

static void display(const int a[],unsigned int size);
static void show(const char a[],unsigned int size);

int main()
{
	char dst1[12] = "hello world";
	int dst2[10] = {0,1,2,3,4,5,6,7,8,9};
	char src1[12] = "memory test";
	int src2[10] = {4,4,4,4,4,4,4,4,4,4};
	
	show(dst1,sizeof(dst1)/sizeof(dst1[0])-1);
	myMemset(dst1,'a',sizeof(dst1));
	show(dst1,sizeof(dst1)/sizeof(dst1[0])-1);
	
	display(dst2,sizeof(dst2)/sizeof(dst2[0]));
	myMemset(dst2,1,sizeof(dst2));
	display(dst2,sizeof(dst2)/sizeof(dst2[0]));
	
	myMemcpy(dst2,src2,sizeof(src2));
	display(dst2,sizeof(dst2)/sizeof(dst2[0]));
	
	myMemcpy(dst1,src1,sizeof(src1));
	show(dst1,sizeof(dst1)/sizeof(dst1[0])-1);
	
	char* result = myMemccpy(dst1,"hello c++",'+',10);
	printf("dst =%s, src =%s, *result =%c\n",dst1,"hello c++",*result);
	
	myMemmove(dst1,"hello world",12);
	printf("dst =%s, src =%s\n",dst1,"hello world");
	
	printf("myMemmove: dst =%s, src =%s\n",dst1+3,dst1);
	myMemmove(dst1+3,dst1,8);
	printf("myMemmove: dst =%s, src =%s\n",dst1+3,dst1);
	
	int flag = myMemcmp(dst1,"hello world",8);
	printf("dst =%s, src =%s, flag =%d\n",dst1,"hello world",flag);
	
/*	int flag = myMemcmp(src1,"hello world",5);
	printf("dst =%s, src =%s, flag =%d\n",src1,"hello world",flag);
*/	
	return 0;
}

void display(const int a[],unsigned int size)
{
	if(a == NULL){
		printf("display warn: a=NULL\n");
		return ;
	}
	
	for(int i=0;i<size;++i){
		printf("%d ",a[i]);
	}
	printf("\n");
}

void show(const char a[],unsigned int size)
{
	if(a == NULL){
		printf("show warn: a=NULL\n");
		return ;
	}
	
	for(int i=0;i<size;++i){
		printf("%c",a[i]);
	}
	printf("\n");	
}