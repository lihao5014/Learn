#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

List* createList(const int size)
{
	if(size <= 0){
		printf("createList warn: size<=0\n");
		return NULL;
	}
	
	List* list = (List*)malloc(sizeof(List));
	if(list == NULL){
		printf("createList warn: list malloc failed\n");
		return NULL;
	}
	
	list->addr = (data_t*)malloc(sizeof(data_t)*size);
	if(list->addr == NULL){
		printf("createList warn: list->addr malloc failed\n");
		return NULL;	
	}
	memset(list->addr,0,sizeof(data_t)*size);
	list->size = size;
	list->last = -1;
	
	return list;
}

void destroyList(List** list)
{
	if(*list == NULL){
		return ;
	}

	(*list)->size = -1;
	(*list)->last = -1;
	if((*list)->addr != NULL){
		free((*list)->addr);
		(*list)->addr = NULL;
	}
	
	free(*list);
	*list = NULL;
}

List* initList(List* list,const data_t data)
{
	if(list == NULL || list->addr == NULL){
		printf("initList warn: list=NULL or list->addr=NULL");
		return NULL;
	}
	
	for(int i=0;i<list->size;++i){
		list->addr[i] = data;
	}
	list->last = list->size -1;
	
	return list;
}

void clearList(List* list)
{
	if(list == NULL || list->addr == NULL){
		return ;
	}
	
	memset(list->addr,0,sizeof(data_t)*list->size);
	list->last = -1;
}

bool isNull(const List* list)
{
	if(list == NULL || list->addr == NULL){
		return true;
	}
	
	return false;
}

bool isEmpty(const List* list)
{
	if(isNull(list)){
		return true;
	}
	
	return list->last == -1 ? true : false;
}

bool isFull(const List* list)
{
	if(list == NULL || list->addr == NULL){
		return false;
	}
	
	return list->last == list->size-1 ? true : false;
}

int getSize(const List* list)
{
	if(isNull(list)){
		printf("getSize warn: list is null\n");
		return -1;
	}
	
	return list->size;
}

int getLength(const List* list)
{
	if(isEmpty(list)){
		printf("getSize warn: list is empty\n");
		return -1;
	}
	
	return list->last+1;
}

bool reSize(List* list,const int size)
{
	if(isNull(list) || size <= 0)
		printf("reSize warn: list is null or size is illegal\n");
		return false;
	}
	
	if(size == list->size){
		return true;
	}
	
	data_t *newAddr = (data_t*)malloc(sizeof(data_t)*size);
	if(newAddr == NULL){
		printf("reSize warn: newAddr is null\n");
		return false;		
	}
	memset(newAddr,0,sizeof(data_t)*size);
	
	if(size >= list->size){
		memcpy(newAddr,list->addr,sizeof(data_t)*(list->last+1));		
	}else{
		if(list->last > size-1){
			list->last = size -1;
		}
		memcpy(newAddr,list->addr,sizeof(data_t)*(list->last+1));
	}
	
	list->size = size;
	free(list->addr);
	list->addr = newAddr;
	
	return true;
}

bool append(List* list,const data_t data)
{
	if(isNull(list) || isFull(list)){
		printf("append warn: list is null or full\n");
		return false;
	}
	
	list->last++;
	list->addr[list->last] = data;
	
	return true;
}

bool prepend(List* list,const data_t data)
{
	if(isNull(list) || isFull(list)){
		printf("prepend warn: list is null or full\n");
		return false;
	}
	
	list->last++;
	for(int i=list->last;i>0;--i){
		list->addr[i] = list->addr[i-1];
	}
	list->addr[0] = data;
	
	return true;
}

bool insert(List* list,const int pos,const data_t data)
{
	if(isNull(list) || isFull(list) || pos < 0 || pos > list->last+1){
		printf("insert warn: list is null or list is full or pos is illegal\n");
		return false;
	}
	
	list->last++;
	for(int i=list->last;i>pos;--i){
		list->addr[i] = list->addr[i-1];
	}
	list->addr[pos] = data;
	
	return true;
}

data_t findByPos(const List* list,const int pos)
{
	assert(!isEmpty(list) && pos >=0 && pos <= list->last);
	
	return list->addr[pos];	
}

int findByData_L(const List* list,const data_t data)
{
	if(isEmpty(list)){
		printf("findByData_L warn: list is empty\n");		
		return false;
	}
	
	for(int i=0;i<=list->last;++i){
		if(list->addr[i] == data){
			return i;
		}
	}
	
	return -1;
}

int findByData_R(const List* list,const data_t data)
{
	if(isEmpty(list)){
		printf("findByData_R warn: list is empty\n");
		return false;
	}	
	
	for(int i=list->last;i>=0;--i){
		if(list->addr[i] == data){
			return i;
		}
	}
	
	return -1;
}

bool deleteByPos(List* list,const int pos)
{
	if(isEmpty(list) || pos < 0 || pos > list->last){
		printf("deleteByPos warn: list is empty or pos is illegal\n");
		return false;
	}

	for(int i=pos;i<list->last;++i){
		list->addr[i] = list->addr[i+1];
	}
	list->addr[list->last] = 0;
	list->last--;
	
	return true;
}

bool deleteByData(List* list,const data_t data)
{
	if(isEmpty(list)){
		printf("deleteByPos warn: list is empty\n");
		return false;
	}
	
	int index;
	bool flag = false;
	while((index = findByData_L(list,data)) != -1){
		deleteByPos(list,index);
		flag = true;
	}
	
	return flag;
}

bool removeFirst(List* list)
{
	return deleteByPos(list,0);
}

bool removeLast(List* list)
{
	return deleteByPos(list,list->last);
}

bool changeByPos(List* list,const int pos,const data_t data)
{
	if(isEmpty(list) || pos < 0 || pos > list->last){
		printf("changeByPos warn: list is empty or pos is illegal\n");
		return false;
	}
	
	list->addr[pos] = data;
	return true;
}

bool changeByData(List* list,const data_t n,const data_t m)
{
	if(isEmpty(list)){
		printf("changeByData warn: list is empty \n");
		return false;
	}
	
	int index;
	bool flag = false;
	while((index = findByData_L(list,n)) != -1){
		changeByPos(list,index,m);
		flag = true;
	}
	
	return flag;
}

void showList(const List* list)
{
	if(isEmpty(list)){
		printf("showList warn: list is empty \n");
		return ;
	}
	
	for(int i=0;i<=list->last;++i){
		printf("%d ",list->addr[i]);
	}
	printf("\n");
}