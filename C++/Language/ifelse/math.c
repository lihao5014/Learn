#include "math.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

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