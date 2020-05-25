#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

Stack* createStack(unsigned int size)
{
	if(size == 0){
		printf("createStack warn: size is illegal\n");
		return NULL;		
	}
	
	Stack* stack = (Stack*)malloc(sizeof(Stack));
	if(stack == NULL){
		printf("createStack warn: stack malloc failed\n");
		return NULL;
	}
	stack->size = size;
	stack->top = -1;
	
	stack->data = (data_t*)malloc(sizeof(data_t)*size);
	if(stack->data == NULL){
		printf("createStack warn: stack->data malloc failed\n");
		return NULL;		
	}
	memset(stack->data,0,sizeof(data_t)*stack->size);
	
	return stack;
}

void destroyStack(Stack** stack)
{
	if(*stack == NULL){
		printf("destroyStack warn: *stack=NULL\n");
		return ;
	}
	
	if((*stack)->data != NULL){
		free((*stack)->data);
		(*stack)->data = NULL;
	}
	(*stack)->size = -1;
	(*stack)->top = -1;
	
	free(*stack);
	*stack = NULL;
}

Stack* initStack(Stack* stack,data_t data)
{
	if(stack == NULL || stack->data == NULL){
		printf("initStack warn: stack=NULL or stack->data=NULL\n");
		return NULL;		
	}
	
	for(int i=0;i<stack->size;++i){
		stack->data[i] = data;
	}
	stack->top = stack->size -1;
	
	return stack;
}

void clearStack(Stack* stack)
{
	if(stack == NULL){
		printf("clearStack warn: stack=NULL\n");
		return ;
	}
	
	memset(stack->data,0,sizeof(data_t)*stack->size);
	stack->top = -1;
}

bool isNull(const Stack* stack)
{
	if(stack == NULL){
		printf("isNull warn: stack=NULL\n");
		return true;
	}
	
	return stack->data == NULL ? true : false;
}

bool isEmpty(const Stack* stack)
{
	if(isNull(stack)){
		return true;
	}
	
	return stack->top == -1 ? true : false;
}

bool isFull(const Stack* stack)
{
	if(isNull(stack)){
		return false;
	}
	
	return stack->top == stack->size-1 ? true : false;
}

int getSize(const Stack* stack)
{
	if(isNull(stack)){
		return -1;
	}
	
	return stack->size;
}

int getLength(const Stack* stack)
{
	if(isNull(stack)){
		return -1;
	}
	
	return stack->top+1;
}

bool reSize(Stack* stack,unsigned int size)
{	
	if(isNull(stack || size <= 0)
		printf("reSize warn: stack is null or size is illegal\n");
		return false;
	}
	
	if(size == stack->size){
		return true;
	}
	
	data_t* newData = (data_t*)malloc(sizeof(data_t)*size);
	if(newdata == NULL){
		printf("reSize warn: newData is null\n");
		return false;
	}
	memset(newData,0,sizeof(data_t)*size);
	
	if(size >= stack->size){
		memcpy(newData,stack->data,sizeof(data_t)*stack->size);
	}else{
		memcpy(newData,stack->data,sizeof(data_t)*size);
	}
	
	if(stack->top > size-1){
		stack->top = size-1;
	}
	
	stack->size = size;
	free(stack->data);
	stack->data = newData;
	
	return true;
}

bool pushStack(Stack* stack,data_t data)
{
	if(isNull(stack)){
		printf("pushStack warn: stack is null\n");
		return false;
	}
	
	stack->top++;
	stack->data[stack->top] = data;
	
	return true;
}

data_t popStack(Stack* stack)
{
	assert(!isEmpty(stack));

	data_t data = stack->data[stack->top];
	stack->top--;
	
	return data;
}

data_t getTop(const Stack* stack)
{
	assert(!isEmpty(stack));
	
	return stack->data[stack->top];
}

bool changeTop(Stack* stack,data_t data)
{
	if(isEmpty(stack)){
		printf("changeTop warn: stack is empty\n");
		return false;
	}
	
	stack->data[stack->top] = data;
	return true;
}

data_t findByPos(const Stack* stack,unsigned int pos)
{
	assert(!isEmpty(stack) && pos >= 0 && pos <= stack->top);
	
	return stack->data[pos];
}

int findByData(const Stack* stack,data_t data)
{
	if(isEmpty(stack)){
		printf("findByData warn: stack is empty\n");
		return -1;
	}
	
	for(int i=stack->top;i>=0;++i){
		if(stack->data[i] == data){
			return i;
		}
	}
	
	return -1;
}

void showStack(const Stack* stack)
{
	if(isEmpty(stack)){
		printf("showStack warn: stack is empty\n");
		return ;
	}
	
	for(int i=0;i<=stack->top;++i){
		printf("%d ",stack->data[i]);
	}
	printf("\n");
}