#include "extreme.h"

BOOL isgreater(data_t x,data_t y)
{
	return x > y ? TRUE : FALSE;
}

data_t max(data_t x,data_t y)
{
	return x > y ? x : y;
}

data_t max3(data_t x,data_t y,data_t z)
{
	data_t maxNum = x;
	if(y > x)
	{
		maxNum = y;
	}
	
	if(z > maxNum)
	{
		maxNum = z;
	}
	return maxNum;
}

BOOL isless(data_t x,data_t y)
{
	return x < y ? TRUE : FALSE;
}

data_t min(data_t x,data_t y)
{
	return x < y ? x : y;
}

data_t min3(data_t x,data_t y,data_t z)
{
	data_t arr[3] = {x,y,z};
	data_t maxNum = arr[0];
	for(int i=1;i<3;++i)
	{
		if(maxNum < arr[i])
		{
			maxNum = arr[i];
		}
	}
	return maxNum;
}