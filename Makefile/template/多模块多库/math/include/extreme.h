#ifndef _EXTREME_H_
#define _EXTREME_H_

#include "common.h"
#include "mymath_global.h"

#ifdef __cplusplus
extern "C" {
#endif

MYMATH_LIB_EXPORT BOOL isgreater(data_t x,data_t y);                //判断x是否比y大
MYMATH_LIB_EXPORT data_t max(data_t x,data_t y);                  //获取两个数中的最大值
MYMATH_LIB_EXPORT data_t max3(data_t x,data_t y,data_t z);        //获取三个数中的最大值

MYMATH_LIB_EXPORT BOOL isless(data_t x,data_t y);                  //判断x是否比y小
MYMATH_LIB_EXPORT data_t min(data_t x,data_t y);                 //获取两个数中的最小值       
MYMATH_LIB_EXPORT data_t min3(data_t x,data_t y,data_t z);       //获取三个数中的最小值

#ifdef __cplusplus
}
#endif

#endif //_EXTREME_H_