#include "sort.h"
#include <stdio.h>

static void swap(int *x,int *y);

BOOL ascend(const int x,const int y)
{
	return x > y ? 1 : 0;
}

BOOL descend(const int x,const int y)
{
	return x < y ? 1 : 0;
}

void sort(int arr[],int size,const pFun pfun)
{
	if(arr == NULL || size <= 0 || pfun == NULL)
	{
		fprintf(stdout,"sort warn: arr==NULL or size<=0 or pfun==NULL\n");
		return ;
	}
	
	for(int i=0;i<size-1;++i)
	{
		for(int j=0;j<size-i-1;++j)
		{
			if(TRUE == pfun(arr[j],arr[j+1]))
			{
				swap(&arr[j],&arr[j+1]);
			}
		}
	}
}

void display(const int arr[],const int size)
{
	if(arr == NULL || size <= 0)
	{
		printf("display warn: arr==NULL or size<=0\n");
		return ;
	}
	
	for(int i=0;i<size;++i)
	{
		printf("%d ",arr[i]);
	}
	puts("");
}

#if 0
void swap(int *x,int *y)
{
	*x = *x ^ *y;
	*y = *x ^ *y;
	*x = *x ^ *y;
}
#else
void swap(int *x,int *y)
{
	*x = *x + *y;
	*y = *x - *y;
	*x = *x - *y;
}
#endif