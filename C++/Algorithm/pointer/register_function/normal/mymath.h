#ifndef _MYMATH_H
#define _MYMATH_H

typedef int data_t;

typedef data_t (*pFunc)(const data_t x,const data_t y);

data_t min(const data_t x,const data_t y);
data_t max(const data_t x,const data_t y);

bool register_min(pFunc pfunc);
bool register_max(pFunc pfunc);

#endif // _MYMATH_H