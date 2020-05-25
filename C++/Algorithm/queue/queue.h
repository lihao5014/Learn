#ifndef _QUEUE_H
#define _QUEUE_H

#include <stdbool.h>

typedef int data_t;

typedef struct
{
	int front;
	int rear;
	int size;
	data_t *data;
}Queue;

Queue* createQueue(unsigned int size);
void destroyQueue(Queue** queue);

Queue* initQueue(Queue* queue,data_t data);
void clearQueue(Queue* queue);

bool isNULL(const Queue* queue);
bool isEmpty(const Queue* queue);
bool isFull(const Queue* queue);
int getSize(const Queue* queue);
int getLength(const Queue* queue);

bool reSize(Queue* queue,unsigned int size);

bool pushQueue(Queue* queue,data_t data);
data_t popQueue(Queue* queue);

data_t getFront(const Queue* queue);
data_t getRear(const Queue* queue);

bool changeFront(Queue* queue,data_t data);
bool changeRear(Queue* queue,data_t data);

data_t findByPos(const Queue* queue,unsigned int pos);
int findByData(const Queue* queue,data_t data);

void showQueue(const Queue* queue);

#endif //_QUEUE_H