#ifndef _MY_MATH_H_
#define _MY_MATH_H_

#include "libMath_global.h"

#define EPS 0.000001

/*对于一份.c文件，采用gcc编译时候没有定义__cplusplus，宏判断不起作用，自然是用c语言的方式编译，采用g++编译时
 *定义了_cplusplus，经过#ifdef宏判断候，还是会以c语言的方式编译。注意extern “C”是g++才具有的关键字，gcc并没有，
 *所以如果用gcc编译而不加#ifdef __cplusplus宏判断，直接使用extern “C”那么就会出现语法错误。
 */
#ifdef __cplusplus
extern "C" {
#endif

LIB_MATH_EXPORT double power(double m,int n);

LIB_MATH_EXPORT double add(double x,double y);
LIB_MATH_EXPORT double sub(double x,double y);

LIB_MATH_EXPORT double mult(double x,double y);
LIB_MATH_EXPORT double divi(double x,double y);

#ifdef __cplusplus
}
#endif

#endif //_MY_MATH_H_