#include "linkqueue.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

LinkQueue* createLinkQueue()
{
	LinkQueue* linkqueue = (LinkQueue*)malloc(sizeof(LinkQueue*));
	if(linkqueue == NULL){
		printf("createLinkQueue warn: linkqueue malloc failed\n");
		return NULL;
	}
	
	linkqueue->rear = linkqueue->front = (Node*)malloc(sizeof(Node));
	if(linkqueue->rear == NULL){
		printf("createLinkQueue warn: linkqueue->rear malloc failed\n");
		return NULL;
	}
	linkqueue->rear->data = -1;
	linkqueue->rear->next = NULL;
	
	return linkqueue;
}

void destroyLinkQueue(LinkQueue** linkqueue)
{
	if(*linkqueue == NULL){
		printf("destroyLinkQueue warn: linkqueue=NULL\n");
		return ;
	}
	
	clearLinkQueue(*linkqueue);
	
	if((*linkqueue)->rear != NULL){
		free((*linkqueue)->rear);
		(*linkqueue)->rear = NULL;
	}
	
	free(*linkqueue);
	*linkqueue = NULL;	
}

LinkQueue* initLinkQueue(LinkQueue* linkqueue,unsigned int size,data_t data)
{
	if(linkqueue == NULL || linkqueue->rear == NULL){
		printf("initLinkQueue warn: linkqueue=NULL or linkqueue->rear=NULL\n");
		return NULL;
	}
	
	if(size == 0){
		printf("initLinkQueue warn: size is illegal\n");
		return NULL;
	}
	
	clearLinkQueue(linkqueue);
	
	Node* p = linkqueue->rear;
	Node* newNode = NULL;
	while(size--){
		newNode = (Node*)malloc(sizeof(Node));
		if(newNode == NULL){
			printf("initLinkQueue warn: newNode malloc failed!");
			clearLinkQueue(linkqueue);
			return NULL;
		}
		newNode->data = data;
		newNode->next = NULL;
		
		p->next = newNode;
		p = p->next;
	}
	linkqueue->front = p;	
	
	return linkqueue;
}

void clearLinkQueue(LinkQueue* linkqueue)
{
	if(linkqueue == NULL || linkqueue->rear == NULL){
		printf("clearLinkQueue warn: linkqueue=NULL or linkqueue->rear=NULL\n");
		return ;
	}
	
	Node* p = linkqueue->rear->next;
	Node* q = NULL;
	if(p != NULL){
		q = p->next;
		free(p);
		p = q;
	}
	linkqueue->front = linkqueue->rear;
	linkqueue->rear->next = NULL;
}

bool isNull(const LinkQueue* linkqueue)
{
	if(linkqueue == NULL){
		return true;
	}
	
	return linkqueue->rear == NULL ? true : false;
}

bool isEmpty(const LinkQueue* linkqueue)
{
	if(isNull(linkqueue)){
		return true;
	}
	
	return linkqueue->rear == linkqueue->front ? true : false;
}

int getLength(const LinkQueue* linkqueue)
{
	if(isNull(linkqueue)){
		printf("getLength warn: linkqueue is null\n");
		return -1;		
	}
	
	int len = 0;
	Node* p = linkqueue->rear->next;
	while(p != NULL){
		len++;
		p = p->next;
	}
	
	return len;
}

bool pushLinkQueue(LinkQueue* linkqueue,data_t data)
{
	if(isNull(linkqueue)){
		printf("pushLinkQueue warn: linkqueue is null\n");
		return false;		
	}

	Node* newNode = (Node*)malloc(sizeof(Node));
	if(newNode == NULL){
		printf("pushLinkQueue warn: newNode malloc failed!");
		return NULL;		
	}
	newNode->data = data;
	newNode->next = NULL;
	
	linkqueue->front->next = newNode;
	linkqueue->front = linkqueue->front->next;
	
	return true;
}

data_t popLinkQueue(LinkQueue* linkqueue)
{
	assert(!isEmpty(linkqueue));
	
	Node* p = linkqueue->rear;
	data_t data = linkqueue->rear->next->data;
	
	linkqueue->rear = linkqueue->rear->next;
	free(p);
	p = NULL;
	
	return data;
}

data_t getFront(const LinkQueue* linkqueue)
{
	assert(!isEmpty(linkqueue));

	return linkqueue->front->data;
}

data_t getRear(const LinkQueue* linkqueue)
{
	assert(!isEmpty(linkqueue));

	return linkqueue->rear->next->data;
}

bool changeFront(LinkQueue* linkqueue,data_t data)
{
	if(isEmpty(linkqueue)){
		printf("pushLinkQueue warn: linkqueue is empty\n");
		return false;		
	}
	
	linkqueue->front->data = data;
	return true;
}

bool changeRear(LinkQueue* linkqueue,data_t data)
{
	if(isEmpty(linkqueue)){
		printf("changeRear warn: linkqueue is empty\n");
		return false;		
	}
	
	linkqueue->rear->next->data = data;
	return true;
}

data_t findByPos(const LinkQueue* linkqueue,unsigned int pos)
{
	assert(!isEmpty(linkqueue) && pos < getLength(linkqueue));
	
	Node* p = linkqueue->rear->next;
	while(pos--){
		p = p->next;
	}
	
	return p->data;
}

int findByData(const LinkQueue* linkqueue,data_t data)
{
	if(isEmpty(linkqueue)){
		printf("findByData warn: linkqueue is empty\n");
		return -1;		
	}
	
	Node* p = linkqueue->rear->next;
	for(int i=0;p != NULL;++i){
		if(p->data == data){
			return i;
		}
	}
	
	return -1;
}

void showLinkQueue(const LinkQueue* linkqueue)
{
	if(isEmpty(linkqueue)){
		printf("showLinkQueue warn: linkqueue is empty\n");
		return ;
	}
	
	Node* p = linkqueue->rear->next;
	while(p != NULL){
		printf("%d ",p->data);
		p = p->next;
	}
	printf("\n");
}