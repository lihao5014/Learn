#ifndef _STACK_H
#define _STACK_H

#include <stdbool.h>

typedef int data_t;

typedef struct
{
	int size;
	int top;
	data_t *data;
}Stack;

Stack* createStack(unsigned int size);
void destroyStack(Stack** stack);

Stack* initStack(Stack* stack,data_t data);
void clearStack(Stack* stack);

bool isNull(const Stack* stack);
bool isEmpty(const Stack* stack);
bool isFull(const Stack* stack);
int getSize(const Stack* stack);
int getLength(const Stack* stack);

bool reSize(Stack* stack,unsigned int size);

bool pushStack(Stack* stack,data_t data);
data_t popStack(Stack* stack);

data_t getTop(const Stack* stack);
bool changeTop(Stack* stack,data_t data);

data_t findByPos(const Stack* stack,unsigned int pos);
int findByData(const Stack* stack,data_t data);

void showStack(const Stack* stack);

#endif //_STACK_H