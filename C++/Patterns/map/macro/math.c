#include "math.h"
#include <stdio.h>
#include <stdlib.h>

DECLARE_MESSAGE_MAP

BEGIN_MESSAGE_MAP
	ON_COMMAND('+',add)
	ON_COMMAND('-',sub)
	ON_COMMAND('x',mult)
	ON_COMMAND('/',divi)
END_MESSAGE_MAP

void calculate(double x,double y,char opt)
{
	for(int i=0;i<messageMap_size;++i)
	{
		if(messageMap[i].signal == opt)
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