#include <stdio.h>
#include <string.h>

static void display(const int a[],unsigned int size);
static void show(const char a[],unsigned int size);

void* myMemset(void* dst,int data,unsigned int size);

int main(void)
{
	unsigned int size;
	int a[5] = {0,1,2,3,4};
	char b[5] = {'a','b','c','d','e'};
	
	size = sizeof(a)/sizeof(a[0]);
	display(a,size);
	
	memset(a,0,sizeof(a));
	display(a,size);
	
	memset(a,1,sizeof(a));
	display(a,size);
	
	memset(b,'f',sizeof(b));
	show(b,sizeof(b)/sizeof(b[0]));
	
	myMemset(a,1,sizeof(a));
	display(a,size);
	
	myMemset(b,'g',sizeof(b));
	show(b,sizeof(b)/sizeof(b[0]));
	
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

static void show(const char a[],unsigned int size)
{
	if(a == NULL){
		printf("display warn: a=NULL\n");
		return ;
	}
	
	for(int i=0;i<size;++i){
		printf("%c ",a[i]);
	}
	printf("\n");
}

void* myMemset(void* dst,int data,unsigned int size)
{
    if(dst==NULL){
		printf("myMemset warn: dst=NULL\n");
		return NULL;
	}
	
    char *p=(char*)dst;
    while(size--){
		*p++ = data;
    }
	
    return dst;
}

