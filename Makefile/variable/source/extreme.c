#include "extreme.h"

const char* strBool[] = {
	"false",
	"true"
};

BOOL isMax(data_t x,data_t y)
{
	return x > y ? TRUE : FALSE;
}

data_t max(data_t x,data_t y)
{
	return x > y ? x : y;
}

data_t Max(data_t x,data_t y,data_t z)
{
	data_t max = x;
	if(y > x)
	{
		max = y;
	}
	
	if(z > max)
	{
		max = z;
	}
	return max;
}

BOOL isMin(data_t x,data_t y)
{
	return x < y ? TRUE : FALSE;
}

data_t min(data_t x,data_t y)
{
	return x < y ? x : y;
}

data_t Min(data_t x,data_t y,data_t z)
{
	if(y < x)
	{
		if(z < y)
		{
			return z;
		}
		return y;
	}
	
	if(z < x)
	{
		return z;
	}
	return x;
}