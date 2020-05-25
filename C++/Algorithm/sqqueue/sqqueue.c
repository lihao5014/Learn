#include "sqqueue.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

SqQueue* createSqQueue()
{
	SqQueue* sqqueue = (SqQueue*)malloc(sizeof(SqQueue));
	if(sqqueue == NULL){
		printf("createSqQueue warn: sqqueue malloc failed\n");
		return NULL;
	}
	memset(sqqueue->data,0,sizeof(sqqueue->data));
	sqqueue->rear = 0;
	sqqueue->front = 0;
	
	return sqqueue;
}

void destroySqQueue(SqQueue** sqqueue)
{
	if(*sqqueue == NULL){
		printf("destroySqQueue warn: *sqqueue=NULL\n");
		return ;
	}
	
	free(*sqqueue);
	*sqqueue = NULL;
}

SqQueue* initSqQueue(SqQueue* sqqueue,data_t data)
{
	if(sqqueue == NULL){
		printf("initSqQueue warn: sqqueue=NULL\n");
		return NULL;
	}
	
	for(int i=0;i<SIZE-1;++i){
		sqqueue->data[i] = data;
	}
	sqqueue->rear = 0;
	sqqueue->front = SIZE-1;
	
	return sqqueue;
}

void clearSqQueue(SqQueue* sqqueue)
{
	if(sqqueue == NULL){
		printf("clearSqQueue warn: sqqueue=NULL\n");
		return ;
	}
	
	memset(sqqueue->data,0,sizeof(data_t)*SIZE);
	sqqueue->rear = sqqueue->front = 0;
}

bool isEmpty(const SqQueue* sqqueue)
{
	if(sqqueue == NULL){
		printf("isEmpty warn: sqqueue=NULL\n");
		return true;
	}
	
	return sqqueue->rear == sqqueue->front ? true : false;
}

bool isFull(const SqQueue* sqqueue)
{
	if(sqqueue == NULL){
		printf("isFull warn: sqqueue=NULL\n");
		return false;
	}
	
	if(sqqueue->front >= sqqueue->rear){
		return sqqueue->front - sqqueue->rear == SIZE-1 ? true : false;
	}else{
		return sqqueue->rear - sqqueue->front == 1 ? true : false;
	}
}

int getSize(const SqQueue* sqqueue)
{
	if(sqqueue == NULL){
		printf("sqqueue warn: sqqueue=NULL\n");
		return -1;
	}
	
	return SIZE;
}

int getLength(const SqQueue* sqqueue)
{
	if(sqqueue == NULL){
		printf("getLength warn: sqqueue=NULL\n");
		return -1;
	}
	
	if(sqqueue->front >= sqqueue->rear){
		return sqqueue->front - sqqueue->rear;
	}else{
		return sqqueue->front+(SIZE-1) - sqqueue->rear;
	}
}

bool pushSqQueue(SqQueue* sqqueue,data_t data)
{
	if(sqqueue == NULL || isFull(sqqueue)){
		printf("pushSqQueue warn: sqqueue=NULL or sqqueue is full\n");
		return false;
	}
	
	sqqueue->data[sqqueue->front] = data;
	sqqueue->front = (sqqueue->front+1)%SIZE;
	
	return true;
}

data_t popSqQueue(SqQueue* sqqueue)
{
	if(isEmpty(sqqueue)){
		printf("popSqQueue warn: sqqueue is empty\n");
		return false;
	}
	
	data_t data = sqqueue->data[sqqueue->rear];
	sqqueue->data[sqqueue->rear] = 0;
	sqqueue->rear = (sqqueue->rear+1)%SIZE;
	
	return data;
}

data_t getFront(const SqQueue* sqqueue)
{
	assert(!isEmpty(sqqueue));
	
	return sqqueue->front == 0 ? sqqueue->data[SIZE-1] : sqqueue->data[sqqueue->front-1];
}

data_t getRear(const SqQueue* sqqueue)
{
	assert(!isEmpty(sqqueue));
	
	return sqqueue->data[sqqueue->rear];
}

bool changeFront(SqQueue* sqqueue,data_t data)
{
	if(isEmpty(sqqueue)){
		printf("changeFront warn: sqqueue is empty\n");
		return false;
	}
	
	if(sqqueue->front == 0){
		sqqueue->data[SIZE-1] = data;
	}else{
		sqqueue->data[sqqueue->front-1] = data;
	}
	
	return true;
}

bool changeRear(SqQueue* sqqueue,data_t data)
{
	if(isEmpty(sqqueue)){
		printf("changeRear warn: sqqueue is empty\n");
		return false;
	}
	
	sqqueue->data[sqqueue->rear] = data;
	return true;
}

data_t findByPos(const SqQueue* sqqueue,unsigned int pos)
{
	assert(!isEmpty(sqqueue) && pos < getLength(sqqueue));

	int index = (sqqueue->rear + pos) % SIZE;
	return sqqueue->data[index];
}

int findByData(const SqQueue* sqqueue,data_t data)
{
	if(isEmpty(sqqueue)){
		printf("findByData warn: sqqueue is empty\n");
		return -1;	
	}
	
	int index = 0;
	for(int i=sqqueue->rear;i != sqqueue->front;++index){
		if(sqqueue->data[i] == data){
			return index;
		}
		i = (i+1)%SIZE;
	}
	
	return -1;
}

void showSqQueue(const SqQueue* sqqueue)
{
	if(isEmpty(sqqueue)){
		printf("showSqQueue warn: sqqueue is empty\n");
		return ;	
	}

	int i=sqqueue->rear;
	while(i != sqqueue->front){
		printf("%d ",sqqueue->data[i]);
		i = (i+1)%SIZE;
	}
	printf("\n");
}
