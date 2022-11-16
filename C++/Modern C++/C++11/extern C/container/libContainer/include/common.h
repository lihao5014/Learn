#ifndef _COMMON_H_
#define _COMMON_H_

#include <stdio.h>
#include <math.h>
#include <stdbool.h>

#define EPS 0.000001

#ifdef _DEBUG_ON_
#	define Assert_print(expr)                                                                    \
		do{                                                                                      \
			if(expr)                                                                             \
			{                                                                                    \
				printf("[%s %s %s %d] %s : true\n",__TIME__,__FILE__,__func__,__LINE__,#expr);   \
			}                                                                                    \
			else                                                                                 \
			{                                                                                    \
				printf("[%s %s %s %d] %s : false\n",__TIME__,__FILE__,__func__,__LINE__,#expr);  \
			}                                                                                    \
		}while(0)
		
#else
#	define Assert_output(expr)
#endif

bool isZero(int n)
{
	return n == 0;
}

bool isZerof(double n)
{
	return fabs(n) < EPS ? true : false;
}

bool greaterThan(int x,int y)
{
	return x > y;
}

bool greaterThanf(double x,double y)
{
	return x > y;
}

bool lessThan(int x,int y)
{
	return x < y;
}

bool lessThanf(double x,double y)
{
	return x < y;
}

#endif //_COMMON_H_