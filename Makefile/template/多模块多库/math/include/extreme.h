#ifndef _EXTREME_H_
#define _EXTREME_H_

#include "common.h"
#include "mymath_global.h"

#ifdef __cplusplus
extern "C" {
#endif

MYMATH_LIB_EXPORT BOOL isgreater(data_t x,data_t y);                //�ж�x�Ƿ��y��
MYMATH_LIB_EXPORT data_t max(data_t x,data_t y);                  //��ȡ�������е����ֵ
MYMATH_LIB_EXPORT data_t max3(data_t x,data_t y,data_t z);        //��ȡ�������е����ֵ

MYMATH_LIB_EXPORT BOOL isless(data_t x,data_t y);                  //�ж�x�Ƿ��yС
MYMATH_LIB_EXPORT data_t min(data_t x,data_t y);                 //��ȡ�������е���Сֵ       
MYMATH_LIB_EXPORT data_t min3(data_t x,data_t y,data_t z);       //��ȡ�������е���Сֵ

#ifdef __cplusplus
}
#endif

#endif //_EXTREME_H_