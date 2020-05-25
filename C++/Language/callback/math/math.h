#ifndef _MATH_H
#define _MATH_H

#define EPS 0.000001

typedef enum BOOL
{
	FALSE,
	TRUE
}BOOL;

typedef double (*pFun)(double x,double y);

double calculate(double x,double y,pFun pfun);
double process(double x,double y,pFun pfun);      //process和calculate的实现完全一模一样，只是为了命名不会产生误导而另外写一个函数

double add(double x,double y);
double sub(double x,double y);
double mult(double x,double y);
double divi(double x,double y);
double max(double x,double y);
double min(double x,double y);

#endif //_MATH_H