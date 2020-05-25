#ifndef _MATH_H
#define _MATH_H

#define EPS 0.000001

#ifdef _DEBUG_
#define TRACK(expr)   \
	printf("[%s: %s %s] $s =%f\n",__FILE__,__func__,__LINE__,#expr,expr)
#else
#define TRACK(expr)
#endif

#define DECLARE_MESSAGE_MAP                       \
typedef double (*pFun)(double x,double y);        \
typedef struct Message_t                          \
{                                                 \
	char signal;                                  \
	pFun operate;                                 \
}Message_t;

#define BEGIN_MESSAGE_MAP                         \
struct Message_t messageMap[] = {

#define END_MESSAGE_MAP                                                           \
	{0,0}                                                                         \
};                                                                                \
                                                                                  \
const int messageMap_size = sizeof(messageMap)/sizeof(struct Message_t) - 1;

#define ON_COMMAND(signal,fun)  {signal,fun},    

extern void calculate(double x,double y,char opt);

extern double add(double x,double y);
extern double sub(double x,double y);
extern double mult(double x,double y);
extern double divi(double x,double y);

extern char strToChar(const char* str);
#endif //_MATH_H