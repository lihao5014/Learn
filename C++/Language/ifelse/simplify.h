#ifndef _SIMPLIFY_H
#define _SIMPLIFY_H

#include "math.h"

#define _CHANGE_WAY_
#undef _CHANGE_WAY_

typedef int data_t;

typedef double (*pFun)(double,double);

typedef struct Message_t
{
	Option opt;
	pFun pfun;
}Message;

const Message messageMap[] = 
{
	{ADD,add},
	{SUB,sub},
	{MULT,mult},
	{'x',mult},
	{DIVI,divi},
	{MAX,max},
	{MIN,min}
};

const int messageMap_size = sizeof(messageMap)/sizeof(Message);

//if else语句中的else分支，大部分都可以通过使用return，break和continue等控制语句替换
void use_else(data_t value);            //不能去掉else的情况
void use_return(data_t value);          //使用return语句，去掉else
void use_break(data_t value);           //使用break语句，去掉else
void use_continue(data_t value);        //使用continue语句，去掉else

data_t use_switch(data_t x,data_t y, Option opt);        //使用switch语句代替if else
data_t use_operator(data_t value);                       //使用三目运算符，去掉else

void front(data_t value,data_t *num);                    //使用将else中的语句前置，去掉else
void merge(data_t value,data_t num);                     //使用合并if判断的方法，去掉else

void tableDriven(data_t x,data_t y, Option opt);                     //使用数据驱动编程/表驱动编程/映射方法，去掉else

#ifndef _CHANGE_WAY_
void strategyPattern(data_t x,data_t y, Option opt);                 //使用策略模式。因为只有C++可以面向对象，C语言不可以。所以只有C++可以使用策略模式
#else
void strategyPattern(data_t x,data_t y, pFun pfun); 	             //C语言可以使用回调函数模拟策略模式，将走那个if else分支的选择权，提前交给客户端去选择
#endif

void stateMachine(data_t value);                                     //使用状态机，去掉else

#endif //_SIMPLIFY_H