#include "mymath.h"
#include <stdio.h>
#include <stdlib.h>

data_t add(data_t x,data_t y)
{
	return x + y;
}

data_t sub(data_t x,data_t y)
{
	return x - y;
}

data_t mult(data_t x,data_t y)
{
	return x * y;
}

data_t divi(data_t x,data_t y)
{
	if(y >= -EPS && y <= EPS)
	{
		puts("divisor can't be zero");
		abort();
	}
	
	return x / y;
}