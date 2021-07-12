/*1.由于core文件一般比较大，所以Linux系统默认core文件大小为0，即不会生成core文件。
 *（1）ulimit -a                  //查看系统参数限制
 *（2）ulimit -c unlimited        //设置core文件的大小为无限大
 */

/*2.根据core崩溃文件调试程序：
 *（1）gdb -q ./coredump.out core     //启动gdb调试时就加载core崩溃文件
 *（2）gdb -q ./coredump.out          //先进入gdb调试环境
 *     core-file core                 //再使用core-file命令加载core崩溃文件
 *     backtrace                      //查看函数的调用栈帧和层级关系
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define _ERROR_
// #undef _ERROR_

#define EPS 0.000001
#define BUFF_SIZE 64

#ifndef _ERROR_
typedef double data_t;
#else
typedef int data_t;
#endif

static void printString(const char* str);
static void displayArray(const int arr[],int size);

#ifndef _ERROR_
static double division(data_t x,data_t y);
static void* getmemory(void **pptr,int size);
#else
static data_t division(data_t x,data_t y);
static void* getmemory(void *ptr,int size);
#endif

int main(int argc,char* argv[])
{
	if(argc > 1)
	{
		for(int i=0;i<argc;++i)
		{
			printf("main: argv[%d] =%s\n",i,argv[i]);
		}
	}
	
	int *ptr;     //由于还没有为ptr指针分配内存空间，所以此时ptr指针还是野指针
	*ptr = 5;     //野指针访问会造成程序崩溃
	printf("*ptr =%d\n",*ptr);
	
	int arr[5] = {0};
	displayArray(arr,sizeof(arr)/sizeof(arr[0]));
	
	double ret = division(5,0);        //整数除法，当除数为0时软件会崩溃
	fprintf(stdout,"5/0 =%f\n",ret);
	
	char* str = NULL;
#ifndef _ERROR_
	getmemory((void**)&str,BUFF_SIZE);
#else
	getmemory((void*)str,BUFF_SIZE);
#endif
	strcpy(str,"hello world\n");
	fputs(str,stdout);

#ifndef _ERROR_
	char text[] = {'w','e','l','c','o','m','e','\0'};
#else
	char text[] = {'w','e','l','c','o','m','e'};        //数组越界，但程序不一定会崩溃
#endif
	printString(text);
	printf("text =%s ,sizeof(text) =%ld\n",text,sizeof(text));
	
	return 0;
}

void printString(const char* str)
{
	if(NULL == str)
	{
		puts("printString error: str is null");
		return ;
	}
	
	const char* p = str;
	while(*p != '\0')
	{
		printf("%c",*p++);
	}
	putchar('\n');
}

#ifndef _ERROR_
void displayArray(const int arr[],int size)
{
	assert(arr != NULL);
	
	for(int i=0;i<size;++i)
	{
		fprintf(stdout,"arr[%d] =%d ",i,arr[i]);
	}
	puts("\n");
}

double division(data_t x,data_t y)
{
	if(y >= -EPS && y <= EPS)
	{
		puts("division error: divisor can't be zero");
		exit(-1);
	}
	
	return (double)x/y;
}

void* getmemory(void **pptr,int size)
{
	*pptr = malloc(size);
	if(*pptr == NULL)
	{
		puts("getmemory error: malloc() failed");
		return NULL;
	}
	
	return *pptr;
}
#else
void displayArray(const int arr[],int size)
{
	if(arr == NULL)
	{
		fputs("displayArray error: arr is null\n",stdout);
		abort();
	}
	
	for(int i=0;i<=size;++i)    //数组越界，但程序不一定会崩溃
	{
		fprintf(stdout,"arr[%d] =%d ",i,arr[i]);
	}
	puts("\n");
}

/*如果除数是int整型，那么当除数为0时程序会崩溃。如果除数是double浮点型，
 *那么当除数为0时软件不会崩溃，运算结果恒等inf。
 */
data_t division(data_t x,data_t y)
{
	return x/y;
}

void* getmemory(void *ptr,int size)
{
	ptr = malloc(size);
	if(ptr == NULL)
	{
		puts("getmemory error: malloc() failed");
		return NULL;
	}
	
	return ptr;
}
#endif