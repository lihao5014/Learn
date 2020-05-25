#ifndef _SQQUEUE_H
#define _SQQUEUE_H

#include <stdbool.h>

#define SIZE 20

typedef int data_t;

typedef struct
{
	int rear;
	int front;
	data_t data[SIZE];
}SqQueue;

SqQueue* createSqQueue();
void destroySqQueue(SqQueue** sqqueue);

SqQueue* initSqQueue(SqQueue* sqqueue,data_t data);
void clearSqQueue(SqQueue* sqqueue);

bool isEmpty(const SqQueue* sqqueue);
bool isFull(const SqQueue* sqqueue);
int getSize(const SqQueue* sqqueue);
int getLength(const SqQueue* sqqueue);

bool pushSqQueue(SqQueue* sqqueue,data_t data);
data_t popSqQueue(SqQueue* sqqueue);

data_t getFront(const SqQueue* sqqueue);
data_t getRear(const SqQueue* sqqueue);

bool changeFront(SqQueue* sqqueue,data_t data);
bool changeRear(SqQueue* sqqueue,data_t data);

data_t findByPos(const SqQueue* sqqueue,unsigned int pos);
int findByData(const SqQueue* sqqueue,data_t data);

void showSqQueue(const SqQueue* sqqueue);

#endif //_SQQUEUE_H