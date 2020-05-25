#include "../include/math.h"
#include <stdio.h>

#define _MULT_ERROR_
// #undef _MULT_ERROR_

double add(double x,double y)
{
	return x + y;
}

double sub(double x,double y)
{
	return x - y;
}

double mult(double x,double y)
{
#ifndef _MULT_ERROR_
	return x * y;
#else
	return x * y * 2;
#endif
}

double divi(double x,double y)
{
	if(y >= -EPS && y <= EPS)
	{
		puts("divisor can't to be zero");
		return -EPS;
	}
	
	return x / y;
}