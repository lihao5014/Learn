#ifndef _SEARCH_H_
#define _SEARCH_H_

#include "util.h"
#include "libsearch_global.h"

#ifdef __cplusplus
extern "C" {
#endif  //__cplusplus

PUBLIC_FUNCTION void* search(const void* data,const void* arr,unsigned int itemSize,unsigned int arrLen,CmpFunPtr compare);

#ifdef __cplusplus
}
#endif  //__cplusplus

#endif  //_SEARCH_H_