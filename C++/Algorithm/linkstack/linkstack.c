#include "linkstack.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

LinkStack* createLinkStack()
{
	LinkStack* head = (LinkStack*)malloc(sizeof(LinkStack));
	if(head == NULL){
		printf("createLinkStack warn: head malloc failed\n");
		return NULL;
	}
	head->data = -1;
	head->next = NULL;
	
	return head;
}

void destroyLinkStack(LinkStack** linkstack)
{
	if(*linkstack == NULL){
		printf("destroyLinkStack warn: *linkstack=NULL\n");
		return ;
	}
	
	clearLinkStack(*linkstack);
	free(*linkstack);
	*linkstack = NULL;
}

LinkStack* initLinkStack(LinkStack* linkstack,unsigned int size,data_t data)
{
	if(linkstack == NULL || size == 0){
		printf("initLinkStack warn: linkstack=NULL or size is illegal\n");
		return NULL;
	}
	
	clearLinkStack(linkstack);
	
	LinkStack* p = linkstack;
	LinkStack* newNode = NULL;
	for(int i=0;i<size;++i){
		newNode = (LinkStack*)malloc(sizeof(LinkStack));
		if(newNode == NULL){
			printf("initLinkStack warn: newNode malloc failed\n");
			clearLinkStack(linkstack);
			return NULL;
		}
		newNode->data = data;
		newNode->next = p->next;;
		
		p->next = newNode;
	}

	return linkstack;
}

void clearLinkStack(LinkStack* linkstack)
{
	if(linkstack == NULL){
		printf("linkstack warn: linkstack=NULL\n");
		return ;
	}
	
	LinkStack* p = linkstack->next;
	LinkStack* q = NULL;
	while(p != NULL){
		q = p->next;
		free(p);
		p = q;
	}
	linkstack->next = NULL;
}

bool isNull(const LinkStack* linkstack)
{
	return linkstack == NULL ? true : false;
}

bool isEmpty(const LinkStack* linkstack)
{
	if(linkstack == NULL){
		return true;
	}
	
	return linkstack->next == NULL ? true : false;
}

int getLength(const LinkStack* linkstack)
{
	if(linkstack == NULL){
		printf("getLength warn: linkstack=NULL\n");
		return -1;
	}
	
	int len = 0;
	LinkStack* p = linkstack->next;
	while(p != NULL){
		p = p->next;
		len++;
	}
	
	return len;
}

bool pushLinkStack(LinkStack* linkstack,data_t data)
{
	if(linkstack == NULL){
		printf("pushLinkStack warn: linkstack=NULL\n");
		return false;		
	}
	
	LinkStack* p = linkstack;
	LinkStack* newNode = (LinkStack*)malloc(sizeof(LinkStack));
	if(newNode == NULL){
		printf("pushLinkStack warn: newNode malloc failed\n");
		return false;		
	}
	newNode->data = data;
	newNode->next = p->next;
	
	p->next = newNode;
	return true;
}

data_t popLinkStack(LinkStack* linkstack)
{
	assert(!isEmpty(linkstack));
	
	LinkStack* p = linkstack->next;
	data_t data = p->data;
	linkstack->next = p->next;
	
	free(p);
	p = NULL;
	
	return data;
}

data_t getTop(const LinkStack* linkstack)
{
	assert(!isEmpty(linkstack));	
	
	return linkstack->next->data;
}

bool changeTop(LinkStack* linkstack,data_t data)
{
	if(isEmpty(linkstack)){
		printf("changeTop warn: linkstack is empty\n");
		return false;
	}

	linkstack->next->data = data;
	return true;
}

data_t findByPos(const LinkStack* linkstack,unsigned int pos)
{
	assert(!isEmpty(linkstack) && pos < getLength(linkstack));
	
	LinkStack* p = linkstack->next;
	while(pos--){
		p = p->next;
	}
	
	return p->data;
}

int findByData(const LinkStack* linkstack,data_t data)
{
	if(isEmpty(linkstack)){
		printf("findByPos warn: linkstack is empty\n");
		return -1;
	}
	
	int len = 0;
	LinkStack* p = linkstack->next;
	while(p != NULL){
		if(p->data == data){
			return len;
		}
		p = p->next;
		len++;
	}
	
	return -1;
}

void showLinkStack(const LinkStack* linkstack)
{
	if(isEmpty(linkstack)){
		printf("findByPos warn: linkstack is empty \n");
		return ;
	}
	
	LinkStack* p = linkstack->next;
	while(p != NULL){
		printf("%d ",p->data);
		p = p->next;
	}
	printf("\n");
}