#ifndef _MATH_H_
#define _MATH_H_

#include "common.h"

#define EPS 0.000001

#ifdef __cplusplus
extern "C" {
#endif

data_t add(data_t x,data_t y);
data_t sub(data_t x,data_t y);
data_t mult(data_t x,data_t y);
data_t divi(data_t x,data_t y);

#ifdef __cplusplus
}
#endif

#endif //_MATH_H_