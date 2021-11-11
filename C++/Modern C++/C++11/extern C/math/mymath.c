#include "mymath.h"
#include <assert.h>

#define _CHANGE_WAY_
#undef _CHANGE_WAY_

static const double EPS = 0.000001;

int add(int x,int y)
{
	return x + y;
}

int sub(int x,int y)
{
	return x - y;
}

int mult(int x,int y)
{
	return x * y;
}

double divi(int x,int y)
{
#ifndef _CHANGE_WAY_
	assert(y != 0);     //因为y是整型，所以它可以和0做比较
#else
	assert(y < -EPS && y > EPS);   //如果y是浮点数，那么它就不能与0直接做比较。
#endif
	
	return (double)x / (double)y;
}

double max(double x,double y)
{
	return x > y ? x : y;
}

double min(double x,double y)
{
	return x < y ? x : y;
}