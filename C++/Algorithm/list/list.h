#ifndef _lIST_H
#define _LIST_H

#include <stdbool.h>

typedef int data_t;

typedef struct
{
	int size;
	int last;
	data_t *addr;
}List;

List* createList(const int size);
void destroyList(List** list);

List* initList(List* list,const data_t data);
void clearList(List* list);

bool isNull(const List* list);
bool isEmpty(const List* list);
bool isFull(const List* list);
int getSize(const List* list);
int getLength(const List* list);

bool reSize(List* list,const int size);

bool append(List* list,const data_t data);
bool prepend(List* list,const data_t data);
bool insert(List* list,const int pos,const data_t data);

data_t findByPos(const List* list,const int pos);
int findByData_L(const List* list,const data_t data);
int findByData_R(const List* list,const data_t data);

bool deleteByPos(List* list,const int pos);
bool deleteByData(List* list,const data_t data);
bool removeFirst(List* list);
bool removeLast(List* list);

bool changeByPos(List* list,const int pos,const data_t data);
bool changeByData(List* list,const data_t n,const data_t m);

void showList(const List* list);

#endif //_LIST_H