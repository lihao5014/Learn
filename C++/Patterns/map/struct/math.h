#ifndef _MATH_H
#define _MATH_H

#define SIZE 4
#define EPS 0.000001

#define INIT_CHANGE
// #undef INIT_CHANGE

#ifdef _DEBUG_
#define TRACK(expr)   \
	printf("[%s: %s] $s =%f\n",__FILE__,__LINE__,#expr,expr)
#else
#define TRACK(expr)
#endif

typedef enum Signal_t
{
	ADD = '+',
	SUB = '-',
	MULT = 'x',
	DIVI = '/'
}Signal_t;

typedef double (*pFun)(double x,double y);

typedef struct Message_t
{
	Signal_t signal;
	pFun operate;
}Message_t;

#ifndef INIT_CHANGE
extern Message_t messageMap[];           //使用extern声明数组时，可以不用指定数组的大小。到定义数组时才指定数组大小。
#else
extern Message_t messageMap[SIZE];       //头文件中定义变量的时候，最好都要加extern或static，如果都不加会造成重定义。extern定义的真正的全局变量，
#endif                                   //static定义的在每一个源文件中都会定义一个同名的static变量，只能在当前源文件中使用。源文件之间互不影响。

extern const int messageMap_size;

extern void calculate(double x,double y,char opt);
extern void initMath();

extern double add(double x,double y);
extern double sub(double x,double y);
extern double mult(double x,double y);
extern double divi(double x,double y);

extern char strToChar(const char* str);
#endif //_MATH_H