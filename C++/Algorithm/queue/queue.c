#include "queue.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

Queue* createQueue(unsigned int size)
{
	if(size == 0){
		printf("createQueue warn: queue size is illegal\n");
		return NULL;		
	}
	
	Queue* queue = (Queue*)malloc(sizeof(Queue));
	if(queue == NULL){
		printf("createQueue warn: queue malloc failed\n");
		return NULL;
	}
	
	queue->data = (data_t*)malloc(sizeof(data_t)*size);
	if(queue->data == NULL){
		printf("createQueue warn: queue->data malloc failed\n");
		return NULL;		
	}
	memset(queue->data,0,sizeof(data_t)*size);
	queue->front = queue->rear = 0;
	queue->size = size;
}

void destroyQueue(Queue** queue)
{
	if(*queue == NULL){
		printf("destroyQueue warn: *queue=NULL\n");
		return ;
	}
	
	if((*queue)->data != NULL){
		free((*queue)->data);
		(*queue)->data = NULL;
	}
	
	free(*queue);
	*queue = NULL;
}

Queue* initQueue(Queue* queue,data_t data)
{
	if(queue == NULL || queue->data == NULL){
		printf("initQueue warn: queue=NULL or queue->data=NULL\n");
		return NULL;
	}
	
	for(int i=0;i<queue->size;++i){
		queue->data[i] = data;
	}
	queue->rear = 0;
	queue->front = queue->size -1;
	
	return queue;
}

void clearQueue(Queue* queue)
{
	if(queue == NULL || queue->data == NULL){
		printf("createQueue warn: queue=NULL or queue->data=NULL\n");
		return ;
	}
	
	memset(queue->data,0,sizeof(data_t)*queue->size);
	queue->rear = queue->front = 0;
}

bool isNULL(const Queue* queue)
{
	if(queue == NULL){
		return true;
	}
	
	return queue->data == NULL ? true : false;
}

bool isEmpty(const Queue* queue)
{
	if(isNULL(queue)){
		return true;
	}
	
	return queue->front == queue->rear ? true : false;
}

bool isFull(const Queue* queue)
{
	if(isNULL(queue)){
		return false;
	}
	
	if(queue->front >= queue->rear){
		return queue->front - queue->rear == queue->size - 1;
	}else{
		return queue->rear - queue->front == 1;
	}
}

int getSize(const Queue* queue)
{
	if(isNULL(queue)){
		printf("getSize warn: queue is null\n");
		return -1;
	}
	
	return queue->size;
}

int getLength(const Queue* queue)
{
	if(isNULL(queue)){
		printf("getLength warn: queue is null\n");
		return -1;
	}
	
	if(queue->front >= queue->rear){
		return queue->front - queue->rear;
	}else{
		return queue->front + (queue->size - 1) - queue->rear;
	}
}

bool reSize(Queue* queue,unsigned int size)
{
	if(isNULL(queue) || size == 0){
		printf("reSize warn: queue is null or size is illegal\n");
		return false;
	}
	
	if(size == queue->size){
		return true;
	}
	
	data_t* newData = (data_t*)malloc(sizeof(data_t)*size);
	if(newData == NULL){
		printf("reSize warn: newData malloc failed\n");
		return false;
	}
	memset(newData,0,sizeof(data_t)*size);
	
	if(size >= queue->size){
		char* p = (char*)queue->data + sizeof(data_t)*queue->front;
		char* q = (char*)newData + sizeof(data_t)*getLength(queue);
		while(p != (char*)queue->data + sizeof(data_t)*queue->rear){
			if(p < (char*)queue->data){
				p = (char*)queue->data + sizeof(data_t)*(queue->size-1)+3;
				printf("1---debug--\n");
			}
			*q-- = *p--;
			if(q == (char*)newData){
				break;
			}
		}
		*q = *p;
		queue->front = getLength(queue);
		queue->rear = 0;
		queue->size = size;
		queue->data = newData;
	}else{
		if(size > getLength(queue)){
			char* p = (char*)queue->data + sizeof(data_t)*queue->front;
			char* q = (char*)newData + sizeof(data_t)*getLength(queue);
			while(p != (char*)queue->data + sizeof(data_t)*queue->rear){
				if(p < (char*)queue->data){
					p = (char*)queue->data + sizeof(data_t)*(queue->size-1)+3;
				}
				*q-- = *p--;
				if(q == (char*)newData){
					break;
				}
			}
			*q = *p;
			queue->front = getLength(queue);
			queue->rear = 0;
			queue->size = size;
			queue->data = newData;			
		}else{
			char* p = (char*)queue->data +sizeof(data_t)* queue->front;
			char* q = (char*)newData + sizeof(data_t)*(size-1);
			
			char* r = NULL;
			if(queue->front >= size-1){
				r = (char*)queue->data + sizeof(data_t)*(queue->front -(size-1));
			}else{
				r = (char*)queue->data + sizeof(data_t)*(queue->size + queue->front - size);
			}
			
			while(p != r){
				if(p < (char*)queue->data){
					p = (char*)queue->data + sizeof(data_t)*(queue->size-1)+3;
				}
				*q-- = *p--;
				if(q == (char*)newData){
					break;
				}				
			}
			*q = *p;
			queue->front = size-1;
			queue->rear = 0;
			queue->size = size;
			queue->data = newData;		
		}
	}
	
	return true;
}

bool pushQueue(Queue* queue,data_t data)
{
	if(isNULL(queue) || isFull(queue)){
		printf("pushQueue warn: queue is null or full\n");
		return false;
	}
	
	queue->data[queue->front] = data;
	queue->front = (queue->front + 1) % queue->size;
	
	return true;
}
data_t popQueue(Queue* queue)
{
	assert(!isEmpty(queue));
	
	data_t data = queue->data[queue->rear];
	queue->data[queue->rear] = 0;
	queue->rear = (queue->rear + 1) % queue->size;
	
	return data;
}

data_t getFront(const Queue* queue)
{
	assert(!isEmpty(queue));
	
	if(queue->front == 0){
		return queue->data[queue->size - 1];
	}else{
		return queue->data[queue->front - 1];
	}
}

data_t getRear(const Queue* queue)
{
	assert(!isEmpty(queue));
	
	return queue->data[queue->rear];
}

bool changeFront(Queue* queue,data_t data)
{
	if(isEmpty(queue)){
		printf("changeFront warn: queue is empty\n");
		return false;
	}
	
	if(queue->front == 0){
		queue->data[queue->size - 1] = data;
	}else{
		queue->data[queue->front - 1] = data;
	}	
	
	return true;
}

bool changeRear(Queue* queue,data_t data)
{
	if(isEmpty(queue)){
		printf("changeRear warn: queue is empty\n");
		return false;
	}
	
	queue->data[queue->rear] = data;
	return true;
}

data_t findByPos(const Queue* queue,unsigned int pos)
{
	assert(!isEmpty(queue) && pos < getLength(queue));
	
	int index = (queue->rear + pos) % queue->size;
	return queue->data[index];
}

int findByData(const Queue* queue,data_t data)
{
	if(isEmpty(queue)){
		printf("findByData warn: queue is empty\n");
		return -1;
	}
	
	int index = 0;
	for(int i=queue->rear;i != queue->front;++index){
		if(queue->data[i] == data){
			return index;
		}
		i = (i+1)%queue->size;
	}
	
	return -1;
}

void showQueue(const Queue* queue)
{
	if(isEmpty(queue)){
		printf("showQueue warn: queue is empty\n");
		return ;
	}
	
	int i=queue->rear;
	while(i != queue->front){
		printf("%d ",queue->data[i]);
		i = (i+1) % queue->size;
	}
	printf("\n");
}