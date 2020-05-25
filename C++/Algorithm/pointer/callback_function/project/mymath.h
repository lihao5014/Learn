#ifndef _MYMATH_H
#define _MYMATH_H

typedef int data_t;

typedef data_t (*pFunc)(const data_t x,const data_t y);

void min(const data_t x,const data_t y,pFunc pfunc);
void max(const data_t x,const data_t y,pFunc pfunc);

#endif  //_MYMATH_H