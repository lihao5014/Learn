#include "utility.h"
#include <stdio.h>
#include <stdlib.h>

void swap(data_t *x,data_t *y)
{
	data_t temp = *x;
	*x = *y;
	*y = temp;
}

data_t max(data_t x,data_t y)
{
	return x > y ? x : y;
}

data_t min(data_t x,data_t y)
{
	return x < y ? x : y;
}

data_t sumArray(const data_t *parr,int size)
{
	if(parr == NULL || size <= 0)
	{
		puts("sumArray error: parr is null,or size <= 0");
		exit(-1);
	}
	
	data_t sum = 0;
	while(size--)
	{
		sum += *(parr + size);
	}
	
	return sum;
}

void displayArray(data_t *parr,int size)
{
	if(parr == NULL || size <= 0)
	{
		fputs("sumArray error: parr is null,or size <= 0",stdout);
		return ;
	}
	
	for(int i=0;i<size;++i)
	{
		printf("%d ",parr[i]);
	}
	putchar('\n');
}