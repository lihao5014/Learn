#include "math.h"
#include <stdio.h>
#include <stdlib.h>

#ifdef INIT_CHANGE
SignalMap_t g_signalMap = {
	{ADD,add},
	{SUB,sub},
	{MULT,mult},
	{DIVI,divi}
};

void initMath()
{

}
#else
SignalMap_t g_signalMap;

void initMath()
{
	g_signalMap.insert(SignalPair_t(ADD,add));
	g_signalMap.insert(SignalPair_t(SUB,sub));
	g_signalMap[MULT] = mult;
	g_signalMap[DIVI] = divi;
}
#endif

void calculate(double x,double y,char opt)
{
	SignalMapIter_t iter = g_signalMap.find(static_cast<Signal_t>(opt));
	if(iter != g_signalMap.end() && iter->second != nullptr)
	{
		iter->second(x,y);
	}
}

double add(double x,double y)
{
	printf("add: %f + %f = %f\n",x,y,x+y);
	return x + y;
}

double sub(double x,double y)
{
	printf("sub: %f - %f = %f\n",x,y,x-y);
	return x - y;	
}

double mult(double x,double y)
{
	fprintf(stdout,"mult: %f * %f = %f\n",x,y,x*y);
	return x * y;
}

double divi(double x,double y)
{
	if(y >= -EPS && y <= EPS)
	{
		puts("the divisor can't be zero");
		exit(-1);
	}
	
	fprintf(stdout,"divi: %f / %f = %f\n",x,y,x/y);
	return x / y;
}

char strToChar(const char* str)
{
	if(str == nullptr)
	{
		puts("strToChar warn: str is null");
		return '\0';
	}
	
	int size = 0;
	const char* p = str;
	while(*p != '\0')
	{
		size++;
		p++;
	}
	
	if(size != 1)
	{
		printf("strToChar warn: %s can't be changed to char\n",str);
		return 0;
	}
	
	return str[0];
}