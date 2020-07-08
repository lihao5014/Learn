#include "math.h"
#include <stdio.h>

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
	return x * y;
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