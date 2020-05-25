#include "sqstack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

SqStack* createSqstack()
{
	SqStack* sqstack = (SqStack*)malloc(sizeof(SqStack));
	if(sqstack == NULL){
		printf("createSqstack warn: sqstack malloc failed\n");
		return NULL;
	}
	memset(sqstack->data,0,sizeof(sqstack->data));
	sqstack->top = -1;
	
	return sqstack;
}

void destroySqstack(SqStack** sqstack)
{
	if(*sqstack == NULL){
		printf("destroySqstack warn: *sqstack=NULL\n");
		return ;
	}
	
	free(*sqstack);
	*sqstack = NULL;
}

SqStack* initSqstack(SqStack* sqstack,const data_t data)
{
	if(sqstack == NULL){
		printf("initSqstack warn: sqstack=NULL\n");
		return NULL;
	}

	for(int i=0;i<SIZE;++i){
		sqstack->data[i] = data;
	}
	sqstack->top = SIZE-1;
	
	return sqstack;
}

void clearSqstack(SqStack* sqstack)
{
	if(sqstack == NULL){
		printf("clearSqstack warn: sqstack=NULL\n");
		return ;
	}
	
	memset(sqstack->data,0,sizeof(data_t)*SIZE);
	sqstack->top = -1;
}

bool isEmpty(const SqStack* sqstack)
{
	if(sqstack == NULL){
		printf("isEmpty warn: sqstack=NULL\n");
		return true;
	}
	
	return sqstack->top == -1 ? true : false;
}

bool isFull(const SqStack* sqstack)
{
	if(sqstack == NULL){
		printf("isFull warn: sqstack=NULL\n");
		return false;
	}
	
	return sqstack->top == SIZE-1 ? true : false;
}

int getSize(const SqStack* sqstack)
{
	if(sqstack == NULL){
		printf("getSize warn: sqstack=NULL\n");
		return -1;
	}
	
	return SIZE;
}

int getLength(const SqStack* sqstack)
{
	if(sqstack == NULL){
		printf("getSize warn: sqstack=NULL\n");
		return -1;
	}
	
	return sqstack->top +1;
}

bool pushSqstack(SqStack* sqstack,const data_t data)
{
	if(sqstack == NULL || isFull(sqstack)){
		printf("pushSqstack warn: sqstack=NULL or sqstack is full\n");
		return false;		
	}
	
	sqstack->top++;
	sqstack->data[sqstack->top] = data;
	
	return true;
}

data_t popSqstack(SqStack* sqstack)
{
	assert(!isEmpty(sqstack));
	
	data_t data = sqstack->data[sqstack->top];
	sqstack->top--;
	
	return data;
}

data_t getTop(const SqStack* sqstack)
{
	assert(!isEmpty(sqstack));
	
	return sqstack->data[sqstack->top];
}

bool changeTop(SqStack* sqstack,const data_t data)
{
	if(isEmpty(sqstack)){
		printf("changeTop warn:sqstack is empty\n");
		return false;		
	}
	
	sqstack->data[sqstack->top] = data;
	return true;
}

data_t findByPos(const SqStack* sqstack,const int pos)
{
	assert(!isEmpty(sqstack) && pos >=0 && pos <= sqstack->top);
	
	return sqstack->data[pos];
}

int findByData(const SqStack* sqstack,const data_t data)
{
	if(isEmpty(sqstack)){
		printf("findByPos warn: sqstack is empty\n");
		return -1;		
	}
	
	for(int i=sqstack->top;i>=0;--i){
		if(sqstack->data[i] == data){
			return i;
		}
	}
	
	return -1;
}

void showSqstack(const SqStack* sqstack)
{
	if(isEmpty(sqstack)){
		printf("showSqstack warn: sqstack is empty\n");
		return ;
	}
	
	for(int i=0;i<=sqstack->top;++i){
		printf("%d ",sqstack->data[i]);
	}
	printf("\n");
}