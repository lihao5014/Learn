#ifndef _COMMON_H
#define _COMMON_H

#define FALSE 0
#define TRUE 1
typedef char BOOL;

typedef int data_t;

typedef void (*pFun)();
typedef void (*pFunc)(data_t data);

typedef struct CallBack_t
{
	pFun pfun;
	pFunc pfunc;
}CallBack;

#endif //_COMMON_H