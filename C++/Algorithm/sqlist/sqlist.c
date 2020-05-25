#include "sqlist.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

SqList* createSqlist()
{
	SqList* sqlist = (SqList*)malloc(sizeof(SqList));
	if(sqlist == NULL){
		printf("createSqlist warn: sqlist malloc failed!\n");
		return NULL;
	}
	
	memset(sqlist->list,0,sizeof(sqlist->list));
	sqlist->last = -1;
	
	return sqlist;
}

void destroySqlist(SqList** sqlist)
{
	if(sqlist == NULL || *sqlist == NULL){
		return ;
	}
	
	free(*sqlist);
	*sqlist = NULL;
}

SqList* initSqlist(SqList* sqlist,const data_t data)
{
	if(sqlist == NULL){
		printf("initSqlist warn: sqlist=NULL\n");
		return NULL;
	}
	
	for(int i=0;i<SIZE;++i){
		sqlist->list[i] = data;
	}
	sqlist->last = SIZE-1;
	
	return sqlist;
}

void clearSqlist(SqList* sqlist)
{
	if(sqlist == NULL){
		printf("clearSqlist warn: sqlist=NULL\n");
		return ;
	}
	
	memset(sqlist->list,0,sizeof(sqlist->list));
	sqlist->last = -1;
}

bool isEmpty(const SqList* sqlist)
{
	if(sqlist == NULL){
		printf("isEmpty warn: sqlist=NULL\n");
		return true;
	}
	
	return sqlist->last == -1 ? true : false;
}

bool isFull(const SqList* sqlist)
{
	if(sqlist == NULL){
		printf("isFull warn: sqlist=NULL\n");
		return false;
	}
	
	return sqlist->last == SIZE -1 ? true : false;
}

int getSize(const SqList* sqlist)
{
	if(sqlist == NULL){
		printf("getSize warn: sqlist=NULL\n");
		return -1;
	}
	
	return SIZE;
}

int getLength(const SqList* sqlist)
{
	if(sqlist == NULL){
		printf("getLength warn: sqlist=NULL\n");
		return -1;
	}
	
	return sqlist->last + 1;
}

bool append(SqList* sqlist,const data_t data)
{
	if(sqlist == NULL || isFull(sqlist)){
		printf("append warn: sqlist=NULL or sqlist is full\n");
		return false;
	}
	
	sqlist->last++;
	sqlist->list[sqlist->last] = data;
	
	return true;
}

bool prepend(SqList* sqlist,const data_t data)
{
	if(sqlist == NULL || isFull(sqlist)){
		printf("prepend warn: sqlist=NULL or sqlist is full\n");
		return false;
	}
	
	sqlist->last++;
	for(int i=sqlist->last;i>0;--i){
		sqlist->list[i] = sqlist->list[i-1];
	}
	sqlist->list[0] = data;
	
	return true;
}

bool insert(SqList* sqlist,const int pos,const data_t data)
{
	if(sqlist == NULL || pos < 0 || pos > sqlist->last+1 || isFull(sqlist)){
		printf("insert warn: sqlist=NULL or pos is illegal or sqlist is full\n");
		return false;
	}
	
	sqlist->last++;
	for(int i=sqlist->last;i>pos;--i){
		sqlist->list[i] = sqlist->list[i-1];
	}
	sqlist->list[pos] = data;
	
	return true;
}

data_t findByPos(const SqList* sqlist,const int pos)
{
	assert(sqlist != NULL && pos >= 0 && pos <= sqlist->last);
	
	return sqlist->list[pos];
}

int findByData_L(const SqList* sqlist,const data_t data)
{
	if(sqlist == NULL || isEmpty(sqlist)){
		printf("findByData_R warn: sqlist=NULL or sqlist is empty\n");
		return -1;
	}
	
	for(int i=0;i<=sqlist->last;++i){
		if(sqlist->list[i] == data){
			return i;
		}
	}
	
	return -1;
}

int findByData_R(const SqList* sqlist,const data_t data)
{
	if(sqlist == NULL || isEmpty(sqlist)){
		printf("findByData_R warn: sqlist=NULL or sqlist is empty\n");
		return -1;
	}
	
	for(int i=sqlist->last;i>=0;--i){
		if(sqlist->list[i] == data){
			return i;
		}
	}
	
	return -1;
}

bool deleteByPos(SqList* sqlist,const int pos)
{
	if(sqlist == NULL || pos < 0 || pos > sqlist->last || isEmpty(sqlist)){
		printf("deleteByPos warn: sqlist=NULL or pos is illegal or sqlist is empty\n");
		return false;
	}
	
	for(int i=pos;i<sqlist->last;++i){
		sqlist->list[i] = sqlist->list[i+1];
	}
	sqlist->list[sqlist->last] = 0;
	sqlist->last--;
	
	return true;
}

bool deleteByData(SqList* sqlist,const data_t data)
{
	if(sqlist == NULL || isEmpty(sqlist)){
		printf("deleteByData warn: sqlist=NULL or sqlist is empty\n");
		return false;
	}
	
	int index;
	bool flag = false;
	while((index = findByData_L(sqlist,data)) != -1){
		deleteByPos(sqlist,index);
		flag = true;
	}
	
	return flag;
}

bool removeFirst(SqList* sqlist)
{
	return deleteByPos(sqlist,0);
}

bool removeLast(SqList* sqlist)
{
	if(sqlist == NULL || isEmpty(sqlist)){
		printf("removeLast warn: sqlist=NULL or sqlist is empty\n");
		return false;
	}
	
	sqlist->list[sqlist->last] = 0;
	sqlist->last--;
	
	return true;
}

bool changeByPos(SqList* sqlist,const int pos,const data_t data)
{
	if(sqlist == NULL || pos < 0 || pos > sqlist->last || isEmpty(sqlist)){
		printf("changeByPos warn: sqlist=NULL or pos is illegal or sqlist is empty\n");
		return false;
	}
	
	sqlist->list[pos] = data;
	return true;
}

bool changeByData(SqList* sqlist,const data_t n,const data_t m)
{
	if(sqlist == NULL || isEmpty(sqlist)){
		printf("changeByData warn: sqlist=NULL or sqlist is empty\n");
		return false;
	}
	
	if(n == m){
		return true;
	}
	
	int index;
	bool flag = false;
	while((index = findByData_L(sqlist,n)) != -1){
		changeByPos(sqlist,index,m);
		flag = true;
	}
	
	return flag;
}

void showSqlist(const SqList* sqlist)
{
	if(sqlist == NULL || isEmpty(sqlist)){
		return ;
	}
	
	for(int i=0;i<=sqlist->last;++i){
		printf("%d ",sqlist->list[i]);
	}
	printf("\n");
}