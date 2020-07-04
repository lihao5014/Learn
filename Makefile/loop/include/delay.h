#ifndef _DELAY_H
#define _DELAY_H

typedef void (*pFun)();

extern void delayHandle(pFun pfun,unsigned int time);
extern void executeTime(pFun pfun);

#endif //_DELAY_H