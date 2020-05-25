#ifndef _MATH_H
#define _MATH_H

#include <string.h>

#define Operater(x,y,mode) operator_##mode(x,y)

#define OPERATER(x,mode,y,ret)               \
	do{                                      \
		if((strcmp(#mode,"+") == 0))         \
		{                                    \
			ret = operator_add(x,y);         \
		}                                    \
		else if((strcmp(#mode,"-") == 0))    \
		{                                    \
			ret = operator_sub(x,y);         \
		}                                    \
		else if((strcmp(#mode,"*") == 0))    \
		{                                    \
			ret = operator_mut(x,y);         \
		}                                    \
		else if((strcmp(#mode,"/") == 0))    \
		{                                    \
			ret = operator_div(x,y);         \
		}                                    \
	}while(0)


extern double operator_add(double x,double y);                 //x,y在函数内部可以修改，但是函数内部修改不影响实参大小
extern double operator_sub(double x,double y);               

extern double operator_mut(const double x,const double y);     //x,y在函数内部不可以修改。
extern double operator_div(const double x,const double y);

#endif //_MATH_H