#ifndef _MATH_H
#define _MATH_H

#include <stdbool.h>

#define EPS 0.000001

typedef double data_t;

extern data_t add(data_t x,data_t y);
extern data_t sub(data_t x,data_t y,bool *isOk);

extern void mult(data_t x,data_t y,data_t *ret);
extern bool divi(data_t x,data_t y,data_t *ret);

extern void power(double x,int y,double *ret,bool *isOk);
extern void extreme(data_t x,data_t y,data_t *min,data_t *max);         //求极值运算

#endif //_MATH_H