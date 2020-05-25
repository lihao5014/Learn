#include "sort.h"

int main()
{
	int arr[] = {8,6,5,1,7,3,0,9,2,4};
	int size = sizeof(arr)/sizeof(arr[0]);
	
	display(arr,sizeof(arr)/sizeof(int));
	
	sort(arr,size,ascend);
	display(arr,size);
	
	sort(arr,size,descend);
	display(arr,sizeof(arr)/sizeof(int));
	
	return 0;
}