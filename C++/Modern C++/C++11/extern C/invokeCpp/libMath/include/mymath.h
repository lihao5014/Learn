#ifndef _MY_MATH_H_
#define _MY_MATH_H_

#include "libMath_global.h"

#define EPS 0.000001

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