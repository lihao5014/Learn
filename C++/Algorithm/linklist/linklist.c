#include "linklist.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

LinkList* createLinkList()
{
	LinkList* head = (LinkList*)malloc(sizeof(LinkList));
	if(head == NULL){
		printf("createLinkList warn: head malloc failed\n");
		return NULL;
	}
	head->data = -1;
	head->next = NULL;
	
	return head;
}

void destroyLinkList(LinkList** linklist)
{
	if(*linklist == NULL){
		printf("destroyLinkList warn: *linklist = NULL\n");
		return ;
	}
	
	clearLinkList(*linklist);
	
	free(*linklist);
	*linklist = NULL;	
}

LinkList* initLinkList(LinkList* linklist,const int size,const data_t data)
{
	if(linklist == NULL || size <= 0){
		printf("initLinkList warn: linklist=NULL or size is illegal\n");
		return NULL;
	}
	
	clearLinkList(linklist);
	
	LinkList* p = linklist;
	for(int i=0;i<size;++i){
		LinkList* newNode = (LinkList*)malloc(sizeof(LinkList));
		if(newNode == NULL){
			printf("initLinkList warn: newNode malloc failed\n");
			clearLinkList(linklist);
			return NULL;
		}
		newNode->data = data;
		newNode->next = NULL;
		
		p->next = newNode;
		p = p->next;
	}
	
	return linklist;
}

void clearLinkList(LinkList* linklist)
{
	if(linklist == NULL){
		printf("clearLinkList warn: linklist=NULL\n");
		return ;
	}
	
	LinkList* p = linklist->next;
	LinkList* q = NULL;
	while(p != NULL){
		q = p->next;
		free(p);
		p = q;
	}
	linklist->next = NULL;
}

bool isNull(const LinkList* linklist)
{
	return linklist == NULL ? true : false;
}

bool isEmpty(const LinkList* linklist)
{
	if(linklist == NULL){
		return true;
	}
	
	return linklist->next == NULL ? true : false;
}

int getLength(const LinkList* linklist)
{
	if(linklist == NULL){
		printf("getLength warn: linklist=NULL\n");
		return -1;
	}
	
	int len = 0;
	LinkList* p = linklist->next;
	while(p != NULL){
		p = p->next;
		len++;
	}
	
	return len;
}

bool append(LinkList* linklist,const data_t data)
{
	if(isNull(linklist)){
		printf("append warn: linklist is NULL\n");
		return false;
	}
	
	LinkList* p = linklist;
	while(p->next != NULL){
		p = p->next;
	}
	
	LinkList* newNode = (LinkList*)malloc(sizeof(LinkList));
	if(newNode == NULL){
		printf("append warn: newNode malloc failed\n");
		return false;
	}
	newNode->data = data;
	newNode->next = NULL;
	
	p->next = newNode;
	return true;
}

bool prepend(LinkList* linklist,const data_t data)
{
	if(isNull(linklist)){
		printf("prepend warn: linklist is NULL\n");
		return false;
	}
	
	LinkList* p = linklist->next;
	
	LinkList* newNode = (LinkList*)malloc(sizeof(LinkList));
	if(newNode == NULL){
		printf("prepend warn: newNode malloc failed\n");
		return false;
	}
	newNode->data = data;
	newNode->next = NULL;

	linklist->next = newNode;
	linklist->next->next = p;
	return true;
}

bool insert(LinkList* linklist,const int pos,const data_t data)
{
	if(isNull(linklist) || pos < 0 || pos > getLength(linklist)){
		printf("insert warn: linklist is NULL or pos is illegal\n");
		return false;
	}
	
	LinkList* p = linklist;
	for(int i=0;i<pos;++i){
		p = p->next;
	}

	LinkList* newNode = (LinkList*)malloc(sizeof(LinkList));
	if(newNode == NULL){
		printf("insert warn: newNode malloc failed\n");
		return false;
	}
	newNode->data = data;
	newNode->next = p->next;
	
	p->next = newNode;
	return true;
}

data_t findByPos(const LinkList* linklist,const int pos)
{
	assert(!isEmpty(linklist) && pos >= 0 && pos < getLength(linklist));
	
	LinkList* p = linklist->next;
	for(int i=0;i<pos;++i){
		p = p->next;
	}
	
	return p->data;
}

int findByData_L(const LinkList* linklist,const data_t data)
{
	if(isEmpty(linklist)){
		printf("findByData_L warn: linklist is empty\n");
		return -1;
	}
	
	LinkList* p = linklist->next;
	for(int i=0;p!=NULL;++i){
		if(p->data == data){
			return i;
		}
		p = p->next;
	}
	
	return -1;
}

int findByData_R(const LinkList* linklist,const data_t data)
{
	if(isEmpty(linklist)){
		printf("findByData_L warn: linklist is empty\n");
		return -1;
	}
	
	int pos;
	LinkList* p =NULL;
	for(int i=getLength(linklist)-1;i>=0;--i){		
		pos = i;
		p = linklist->next;
		
		while(pos--){
			p = p->next;
		}
		
		if(p->data == data){
			return i;
		}
	}
	
	return -1;
}

bool deleteByPos(LinkList* linklist,const int pos)
{
	if(isEmpty(linklist) || pos < 0 || pos >= getLength(linklist)){
		printf("deleteByPos warn: linklist is empty or pos is illegal\n");
		return false;
	}
	
	LinkList* p = linklist;
	LinkList* q = NULL;
	for(int i=0;i<pos;++i){
		p = p->next;
	}
	q = p->next->next;
	
	free(p->next);
	p->next = q;
	
	return true;
}

bool deleteByData(LinkList* linklist,const data_t data)
{
	if(isEmpty(linklist)){
		printf("deleteByData warn: linklist is empty\n");
		return false;
	}
	
	int index;
	bool flag = false;
	while((index = findByData_L(linklist,data)) != -1){
		deleteByPos(linklist,index);
		flag = true;
	}
	
	return flag;
}

bool removeFirst(LinkList* linklist)
{
	if(isEmpty(linklist)){
		printf("removeFirst warn: linklist is empty\n");
		return false;
	}
	
	LinkList* p = linklist->next;
	linklist->next = p->next;
	free(p);
	p = NULL;
	
	return true;
}

bool removeLast(LinkList* linklist)
{
	if(isEmpty(linklist)){
		printf("removeFirst warn: linklist is empty\n");
		return false;
	}
	
	LinkList* p = linklist;
	while(p->next->next != NULL){
		p = p->next;
	}
	
	free(p->next);
	p->next = NULL;
	
	return true;
}

bool changeByPos(LinkList* linklist,const int pos,const data_t data)
{
	if(isEmpty(linklist) || pos < 0 || pos >= getLength(linklist)){
		printf("changeByPos warn: linklist is empty or pos is illegal\n");
		return false;
	}
	
	LinkList* p = linklist->next;
	for(int i=0;i<pos;++i){
		p = p->next;
	}
	
	p->data = data;
	return true;	
}

bool changeByData(LinkList* linklist,const data_t n,const data_t m)
{
	if(isEmpty(linklist)){
		printf("changeByData warn: linklist is empty\n");
		return false;
	}
	
	int index;
	bool flag = false;
	while((index = findByData_L(linklist,n)) != -1){
		changeByPos(linklist,index,m);
		flag = true;
	}
	
	return flag;
}

void showLinkList(const LinkList* linklist)
{
	if(isEmpty(linklist)){
		printf("showList warn: linklist is empty\n");
		return ;
	}
	
	LinkList* p = linklist->next;
	while(p != NULL){
		printf("%d ",p->data);
		p = p->next;
	}
	printf("\n");
}