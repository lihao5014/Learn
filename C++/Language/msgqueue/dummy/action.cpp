#include "action.h"
#include <stdio.h>
#include <stdlib.h>

#ifndef _CHANGE_WAY_
const Message messageMap[] = {
	{ADD,add},
	{SUB,sub},
	{MULT,mult},
	{DIVI,divi},
	{MAX,max},
	{MIN,min}
};

const int messageMap_size = sizeof(messageMap)/sizeof(messageMap[0]);

double doProcess(double x,double y,Action_t action)
{
	for(int i=0;i<ACTION_COUNT;++i)
	{
		if(messageMap[i].action == action)
		{
			return messageMap[i].pfun(x,y);
		}
	}
	
	fputs("action is illegal\n",stdout);
	return -EPS;
}
#else
Message messageMap[ACTION_COUNT];          //C语言不支持使用静态全局变量初始来调用函数，C++才支持

static void initMessageMap()
{
	messageMap[ADD].action = ADD;
	messageMap[ADD].pfun = add;
	
	messageMap[SUB].action = SUB;
	messageMap[SUB].pfun = sub;
	
	messageMap[MULT].action = MULT;
	messageMap[MULT].pfun = mult;
	
	messageMap[DIVI].action = DIVI;
	messageMap[DIVI].pfun = divi;
	
	messageMap[MAX].action = MAX;
	messageMap[MAX].pfun = max;	

	messageMap[MIN].action = MIN;
	messageMap[MIN].pfun = min;	
}

static int dummy = (initMessageMap(),1);        //利用全局变量的初始化过程初始化消息映射表，这里巧妙的使用了逗号运算符，
                                                //因为initMessageMap()返回值是void类型，不能直接跟int类型的dummy变量赋值

const int messageMap_size = sizeof(messageMap)/sizeof(int);

double doProcess(double x,double y,Action_t action)
{
	if(action < ADD || action >= ACTION_COUNT)
	{
		puts("doProcess warn: input is illegal");
		return -EPS;;
	}
	
	return messageMap[action].pfun(x,y);
}
#endif

double add(double x,double y)
{
	printf("add: %f + %f = %f\n",x,y,x+y);
	return x + y;
}

double sub(double x,double y)
{
	fprintf(stdout,"sub: %f - %f =%f\n",x,y,x-y);
	return x - y;
}

double mult(double x,double y)
{
	printf("mult: %f * %f = %f\n",x,y,x*y);
	return x * y;
}

double divi(double x,double y)
{
	if(y > -EPS && y < EPS)
	{
		puts("divisor is zero");
		abort();
	}
	
	fprintf(stdout,"divi: %f / %f =%f\n",x,y,x/y);
	return x / y;	
}

double max(double x,double y)
{
	printf("max: %f and %f max is %f\n",x,y,x > y ? x : y);
	return x > y ? x : y;	
}

double min(double x,double y)
{
	fprintf(stdout,"min: %f and %f min is %f\n",x,y,x < y ? x : y);	
	return x < y ? x : y;
}