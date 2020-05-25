#include "math.h"
#include <stdio.h>
#include <stdlib.h>

#define EPS 0.000001

double operator_add(double x,double y)
{
	return x + y;
}

double operator_sub(double x,double y)
{
	return x - y;
}

double operator_mut(const double x,const double y)
{
	return x * y;
}

double operator_div(const double x,const double y)
{
	if(y > -EPS && y < EPS)
	{
		puts("除数不能等于0");
		exit(-1);
	}

	return x / y;
}