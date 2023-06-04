#include "sort.h"

void sort(void* arr,unsigned int itemSize,unsigned int arrLen,CmpFunPtr compare)
{
	if(arr == NULL || itemSize == 0 || arrLen == 0)
	{
		TRACK("error: input array is illegal!");
		return;
	}
	
	if(compare == NULL)
	{
		TRACK("error: compare is null!");
		return;
	}
	
	char* p = arr;   //void*指针在C语言中可以"+,-,++,--,+=,-="运算，但是在C++语言中则不允许，因为void类型没有大小。
	for(unsigned int i=0;i<arrLen;++i)
	{
		for(unsigned int j=0;j < (arrLen - i - 1);++j)
		{
			if(compare(p + j * itemSize,p + (j + 1) * itemSize) > 0)
			{
				memswap(p + j * itemSize,p + (j + 1) * itemSize,itemSize);
			}
		}
	}
}