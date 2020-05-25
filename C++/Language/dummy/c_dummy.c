#include <stdio.h>

#define _DUMMY_
// #undef _DUMMY_

#define ShowArray(arr) showArray(arr,sizeof(arr)/sizeof(arr[0]))

#ifndef _DUMMY_
int array[3] = {1,2,3};
#else
int array[3];

void initArray()
{
	array[0] = 1;
	array[1] = 2;
	array[2] = 3;
}

static int dummy = (initArray(),0);     //C语言不支持使用静态全局变量进行初始
#endif

static void showArray(const int *arr,int size);

int main()
{
	ShowArray(array);
	return 0;
}

void showArray(const int *arr,int size)
{
	if(arr == NULL || size <= 0)
	{
		puts("arr is null,or size<=0");
		return ;
	}
	
	for(int i=0;i<size;++i)
	{
		printf("%d ",arr[i]);
	}
	puts("");
}