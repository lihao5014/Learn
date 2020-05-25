#ifndef _SQLIST_H
#define _SQLIST_H

#include <stdbool.h>

#define SIZE 20

typedef int data_t;

typedef struct
{
	data_t list[SIZE];
	int last;
}SqList;

SqList* createSqlist();
void destroySqlist(SqList** sqlist);

SqList* initSqlist(SqList* sqlist,const data_t data);
void clearSqlist(SqList* sqlist);

bool isEmpty(const SqList* sqlist);
bool isFull(const SqList* sqlist);
int getSize(const SqList* sqlist);
int getLength(const SqList* sqlist);

bool append(SqList* sqlist,const data_t data);
bool prepend(SqList* sqlist,const data_t data);
bool insert(SqList* sqlist,const int pos,const data_t data);

data_t findByPos(const SqList* sqlist,const int pos);
int findByData_L(const SqList* sqlist,const data_t data);
int findByData_R(const SqList* sqlist,const data_t data);

bool deleteByPos(SqList* sqlist,const int pos);
bool deleteByData(SqList* sqlist,const data_t data);
bool removeFirst(SqList* sqlist);
bool removeLast(SqList* sqlist);

bool changeByPos(SqList* sqlist,const int pos,const data_t data);
bool changeByData(SqList* sqlist,const data_t n,const data_t m);

void showSqlist(const SqList* sqlist);

#endif  //_SQLIST_H