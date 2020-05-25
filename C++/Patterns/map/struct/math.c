#include "math.h"
#include <stdio.h>
#include <stdlib.h>

#ifndef INIT_CHANGE
Message_t messageMap[SIZE] = {
	{ADD,add},
	{SUB,sub},
	{MULT,mult},
	{DIVI,divi}
};

void initMath()
{
	
}
#else
Message_t messageMap[SIZE];

void initMath()
{
	messageMap[0].signal = ADD;
	messageMap[0].operate = add;
	
	messageMap[1].signal = SUB;
	messageMap[1].operate = sub;
	
	messageMap[2].signal = MULT;
	messageMap[2].operate = mult;
	
	messageMap[3].signal = DIVI;
	messageMap[3].operate = divi;
}
#endif

const int messageMap_size = sizeof(messageMap)/sizeof(messageMap[0]);

void calculate(double x,double y,char opt)
{
	for(int i=0;i<messageMap_size;++i)
	{
		if(messageMap[i].signal == (Signal_t)opt)
		{
			messageMap[i].operate(x,y);
			return ;
		}
	}
	
	puts("opt is illegal");
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
	if(str == NULL)
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