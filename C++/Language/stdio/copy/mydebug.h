/* 
 *使用时_DEBUG_OFF_调试打印宏开关必须至于mydebug.h头文件之前，才能生效。
 *#define _DEBUG_OFF_
 *#include "mydebug.h" 
 */

#ifndef _MYDEBUG_H
#define _MYDEBUG_H

void doDebug(const char* str);
void doPrint(const char* expr);

#ifndef _DEBUG_OFF_
#define Debug(str)  doDebug(str)
#else
#define Debug(str)
#endif

#ifndef _ASSERT_OFF_
#define Assert(expr)               \
    do{                            \
        if(!(expr))                \
        {                          \
            doPrint(#expr);        \
        }                          \
    }while(0)
#else
#define Assert(expr) ((void)0)
#endif

#endif //_MYDEBUG_H