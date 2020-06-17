#include "math.h"
#include <stdio.h>
#include <stdlib.h>

data_t add(data_t x,data_t y)
{
	return x + y;
}

data_t sub(data_t x,data_t y,bool *isOk)
{
	if(isOk == NULL)
	{
		puts("sub error: isOk is null");
		exit(-1);
	}
	
	*isOk = true;
	return x - y;
}

void mult(data_t x,data_t y,data_t *ret)
{
	if(ret == NULL)
	{
		fputs("mult error: ret is null",stdout);
		return ;
	}
	
	*ret = x * y;
	return ;
}

bool divi(data_t x,data_t y,data_t *ret)
{
	if(ret == NULL || (y >= -EPS && y <= EPS))
	{
		return false;
	}
	
	*ret = x / y;
	return true;
}

void power(double x,int y,double *ret,bool *isOk)
{
	if(ret == NULL || isOk == NULL)
	{
		fprintf(stdout,"power error: ret or isOk is null");
		return ;
	}
	
	*ret = 1;
	if(y > 0)
	{
		while(--y) *ret *= x;
	}
	else if(y < 0)
	{
		while(++y) *ret *= x;
		*ret = 1.0 / *ret;
	}
	
	*isOk = true;
}

void extreme(data_t x,data_t y,data_t *min,data_t *max)
{
	if(x > y)
	{
		*min = y;
		*max = x;
		return ;
	}
	
	*min = x;
	*max = y;
}