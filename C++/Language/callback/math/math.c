#include "math.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

double calculate(double x,double y,pFun pfun)
{
	assert(pfun != NULL);
	
	puts("call calculate");
	return pfun(x,y);
}

double process(double x,double y,pFun pfun)     //process和calculate的实现完全一模一样，只是为了命名不会产生误导而另外写一个函数
{
	assert(pfun != NULL);
	
	fputs("call process\n",stdout);
	return pfun(x,y);
}

double add(double x,double y)
{
	printf("add: %f + %f =%f\n",x,y,x+y);
	return x + y;
}

double sub(double x,double y)
{
	printf("sub: %f - %f =%f\n",x,y,x-y);
	return x - y;	
}

double mult(double x,double y)
{
	printf("mult: %f * %f =%f\n",x,y,x*y);
	return x * y;	
}

double divi(double x,double y)
{
	if(y >= -EPS && y <= EPS)
	{
		puts("divi warn: divisor is 0");
		exit(-1);
	}
	
	printf("divi: %f / %f =%f\n",x,y,x/y);
	return x / y;	
}
double max(double x,double y)
{
	fprintf(stdout,"max: %f and %f maximum is %f",x,y,(x > y ? x : y));
	return  x > y ? x : y;
}

double min(double x,double y)
{
	printf("mix: %f and %f minimum is %f",x,y,(x < y ? x : y));
	return  x < y ? x : y;	
}