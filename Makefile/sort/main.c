#include "sort.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

int main(void)
{
	data_t arr[SIZE] = {4,3,8,6,2,7,1,9,5,0};
	
	data_t *parr = (data_t*)malloc(sizeof(data_t)*SIZE);
	if(parr == NULL)
	{
		printf("parr malloc failed\n");
		return -1;
	}
	memset(parr,0,sizeof(data_t)*SIZE);
	memcpy(parr,arr,sizeof(arr));
	
	displayArray(arr,SIZE);
	bubbleSort(arr,SIZE);
	displayArray(arr,SIZE);
	puts("");
	
	displayArray(parr,SIZE);
	insertSort(parr,SIZE);
	displayArray(parr,SIZE);
	putc('\n',stdout);
	
	data_t list[] = {4,3,8,6,2,7,1,9,5,0};
	displayArray(list,sizeof(list)/sizeof(data_t));
	selectSort(list,sizeof(list)/sizeof(list[0]));
	displayArray(list,sizeof(list)/sizeof(list[0]));
	putchar('\n');
	
	data_t vector[SIZE] = {4,3,8,6,2,7,1,9,5,0};
	displayArray(vector,SIZE);
	sort(vector,SIZE,min);
	displayArray(vector,sizeof(vector)/sizeof(vector[0]));
	
	return 0;
}