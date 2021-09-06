#include "mysort.h"

#define ARRAY_SIZE 10

int main(void)
{
	int arr[] = {3,5,7,2,9,6,1,8,0,4};
	displayArray(arr,ARRAY_SIZE);
	
	mysort(arr,sizeof(arr)/sizeof(int));
	displayArray(arr,sizeof(arr)/sizeof(arr[0]));
	
	return 0;
}