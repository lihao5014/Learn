#ifndef _MYMATH_H_
#define _MYMATH_H_

#include "mymath_global.h"
#include "common.h"

#ifdef __cplusplus
extern "C" {
#endif

MYMATH_LIB_EXPORT data_t add(data_t x,data_t y);
MYMATH_LIB_EXPORT data_t sub(data_t x,data_t y);
MYMATH_LIB_EXPORT data_t mult(data_t x,data_t y);
MYMATH_LIB_EXPORT data_t divi(data_t x,data_t y);

#ifdef __cplusplus
}
#endif

#endif //_MYMATH_H_