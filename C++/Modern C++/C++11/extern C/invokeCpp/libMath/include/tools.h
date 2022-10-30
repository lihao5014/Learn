#ifndef _TOOLS_H_
#define _TOOLS_H_

#include "libMath_global.h"

LIB_MATH_EXPORT int absolute(int n);
LIB_MATH_EXPORT double absolute(double n);

LIB_MATH_EXPORT bool toString(int n,char* str);
LIB_MATH_EXPORT bool toString(double n,char* str);

LIB_MATH_EXPORT int min(int x,int y);
LIB_MATH_EXPORT int min(int x,int y,int z);
LIB_MATH_EXPORT double min(double x,double y);
LIB_MATH_EXPORT double min(double x,double y,double z);

LIB_MATH_EXPORT int max(int x,int y);
LIB_MATH_EXPORT int max(int x,int y,int z);
LIB_MATH_EXPORT double max(double x,double y);
LIB_MATH_EXPORT double max(double x,double y,double z);

#endif // _TOOLS_H_