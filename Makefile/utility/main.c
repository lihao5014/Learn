#include "utility.h"
#include <stdio.h>

int main(void)
{
	printf("%d and %d max is: %d\n",3,5,max(3,5));
	printf("%d and %d min is: %d\n",7,14,min(7,14));
	
	int arr[] = {1,2,5,7,4,3,8,9,6};
	displayArray(arr,sizeof(arr)/sizeof(arr[0]));
	printf("sum =%d\n",sumArray(arr,sizeof(arr)/sizeof(int)));
	
	return 0;
}