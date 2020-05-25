#ifndef _SQSTACK_H
#define _SQSTACK_H

#include <stdbool.h>

#define SIZE 20

typedef int data_t;

typedef struct
{
	int top;
	data_t data[SIZE];
}SqStack;

SqStack* createSqstack();
void destroySqstack(SqStack** sqstack);

SqStack* initSqstack(SqStack* sqstack,const data_t data);
void clearSqstack(SqStack* sqstack);

bool isEmpty(const SqStack* sqstack);
bool isFull(const SqStack* sqstack);
int getSize(const SqStack* sqstack);
int getLength(const SqStack* sqstack);

bool pushSqstack(SqStack* sqstack,const data_t data);
data_t popSqstack(SqStack* sqstack);

data_t getTop(const SqStack* sqstack);
bool changeTop(SqStack* sqstack,const data_t data);

data_t findByPos(const SqStack* sqstack,const int pos);
int findByData(const SqStack* sqstack,const data_t data);

void showSqstack(const SqStack* sqstack);

#endif //_SQSTACK_H