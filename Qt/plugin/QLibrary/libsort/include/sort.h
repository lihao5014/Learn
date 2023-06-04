#ifndef _SOERT_H_
#define _SOERT_H_

#include "util.h"
#include "libsort_global.h"

#ifdef __cplusplus
extern "C" {
#endif  //__cplusplus

PUBLIC_FUNCTION void sort(void* arr,unsigned int itemSize,unsigned int arrLen,CmpFunPtr compare);

#ifdef __cplusplus
}
#endif  //__cplusplus

#endif //_SOERT_H_