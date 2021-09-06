#include "mysort.h"
#include <stdio.h>
#include <assert.h>

static void swap(int *x,int *y);

void displayArray(int *array,int size)
{
	assert(array != NULL && size > 0);
	
	for(int i=0;i<size;++i)
	{
		printf("%d ",array[i]);
	}
	putchar('\n');
}

void mysort(int *array, int size)
{
	if(array == NULL || size <= 0)
	{
		puts("bubbleSort error: array is null or size<=0");
		return ;
	}
	
	for(int i=0;i<size;++i)
	{
		for(int j=0;j<size -i -1;++j)
		{
			if(array[j] > array[j + 1])
			{
				swap(&array[j],&array[j + 1]);
			}
		}
	}
}

void swap(int *x,int *y)
{
	if(x == NULL || y == NULL)
	{
		puts("swap error: x or y pointer is null");
		return ;
	}

	int temp = *x;
	*x = *y;
	*y = temp;
}