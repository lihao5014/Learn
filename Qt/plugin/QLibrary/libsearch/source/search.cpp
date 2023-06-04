#include "search.h"
#include <stdlib.h>

void* search(const void* data,const void* arr,unsigned int itemSize,unsigned int arrLen,CmpFunPtr compare)
{
	if(data == NULL || compare == NULL)
	{
		TRACK("error: data or equal is null!");
		return NULL;
	}
	
	if(arr == NULL || itemSize == 0 || arrLen == 0)
	{
		TRACK("error: input array is illegal!");
		return NULL;
	}
	
	//void*指针在C语言中可以"+,-,++,--,+=,-="运算，但是在C++语言中则不允许，因为void类型没有大小。
	char* p = (char*)arr;
	int low = 0;
	int high = arrLen - 1;
	int mid = (low + high) / 2;	
	if(compare(arr,p + high * itemSize) < 0)
	{
		do{
			if(compare(data,p + mid * itemSize) == 0)
			{
				 return p + mid * itemSize;
			}
			else if(compare(data,p + mid * itemSize) < 0)
			{
				high = mid - 1;
			}
			else
			{
				low = mid + 1;
			}
			
			mid = (low + high) / 2;
		}while(low <= high);
	}
	else if(compare(arr,p + high * itemSize) > 0)
	{
		do{
			if(compare(data,p + mid * itemSize) == 0)
			{
				return p + mid * itemSize;
			}
			else if(compare(data,p + mid * itemSize) > 0)
			{
				high = mid - 1;
			}
			else
			{
				low = mid + 1;
			}

			mid = (low + high) / 2;
		}while(low <= high);	
	}
	else
	{
		if(compare(data,arr) == 0)
		{
			return p;
		}
	}
	
	return NULL;
}