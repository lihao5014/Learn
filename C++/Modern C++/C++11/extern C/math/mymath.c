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
	assert(y != 0);     //��Ϊy�����ͣ����������Ժ�0���Ƚ�
#else
	assert(y < -EPS && y > EPS);   //���y�Ǹ���������ô���Ͳ�����0ֱ�����Ƚϡ�
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