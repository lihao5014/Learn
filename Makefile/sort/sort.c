#include "sort.h"
#include <stdio.h>

void sort(data_t arr[],int size,pRule prule)
{
	if(prule == NULL || size <= 0)
	{
		printf("sort error: prule is null,or size<=0\n");
		return ;
	}
	
	int maxIndex = 0;
	for(int i=0;i<size;++i)
	{
		maxIndex = 0;
		for(int j=1;j<size-i;++j)
		{
			if(prule(arr[maxIndex],arr[j]) == arr[j])
			{
				maxIndex = j;
			}
		}
		swap(arr+maxIndex,&arr[size-i-1]);
	}
}


void bubbleSort(data_t arr[],int size)
{
	if(size <= 0)
	{
		puts("bubbleSort error: size <= 0");
		return ;
	}
	
	for(int i=0;i<size;++i)
	{
		for(int j=0;j<size-i-1;++j)
		{
			if(arr[j] > arr[j+1])
			{
				swap(&arr[j],&arr[j+1]);
			}
		}
	}
}

void insertSort(data_t *parr,int size)
{
	if(parr == NULL || size <= 0)
	{
		fputs("insertSort error: parr is null,size <= 0\n",stdout);
		return ;
	}
	
	for(int i=0;i<size;++i)
	{
		for(int j=i+1;j>0;--j)
		{
			if(*(parr + j) < *(parr + j -1))
			{
				swap(parr+j,parr+j-1);
			}
			else
			{
				break;
			}
		}
	}
}

void selectSort(data_t *parr,int size)
{
	if(parr == NULL || size <= 0)
	{
		fprintf(stdout,"insertSort error: parr is null,size <= 0\n");
		return ;
	}
	
	for(int i=0;i<size;++i)
	{
		int maxIndex = 0;
		for(int j=1;j<size-i;++j)
		{
			if(parr[maxIndex] < *(parr + j))
			{
				maxIndex = j;
			}
		}
		swap(&parr[maxIndex],parr+size-i-1);
	}
}