#ifndef _MATH_H
#define _MATH_H

#include <map>

#define INIT_CHANGE
// #undef INIT_CHANGE

#define EPS 0.000001

enum Signal_t
{
	ADD = '+',
	SUB = '-',
	MULT = 'x',
	DIVI = '/'
};

typedef double (*pFun)(double x,double y);
typedef std::pair<Signal_t,pFun> SignalPair_t;
typedef std::map<Signal_t,pFun> SignalMap_t;
typedef std::map<Signal_t,pFun>::iterator SignalMapIter_t;

extern SignalMap_t g_signalMap;
extern void calculate(double x,double y,char opt);
extern void initMath();

extern double add(double x,double y);
extern double sub(double x,double y);
extern double mult(double x,double y);
extern double divi(double x,double y);

extern char strToChar(const char* str);
#endif //_MATH_H