#ifndef _LINKLIST_H
#define _LINKLIST_H

#include <stdbool.h>

typedef int data_t;

typedef struct Node
{
	data_t data;
	struct Node *next;
}LinkList;

LinkList* createLinkList();
void destroyLinkList(LinkList** linklist);

LinkList* initLinkList(LinkList* linklist,const int size,const data_t data);
void clearLinkList(LinkList* linklist);

bool isNull(const LinkList* linklist);
bool isEmpty(const LinkList* linklist);
int getLength(const LinkList* linklist);

bool append(LinkList* linklist,const data_t data);
bool prepend(LinkList* linklist,const data_t data);
bool insert(LinkList* linklist,const int pos,const data_t data);

data_t findByPos(const LinkList* linklist,const int pos);
int findByData_L(const LinkList* linklist,const data_t data);
int findByData_R(const LinkList* linklist,const data_t data);

bool deleteByPos(LinkList* linklist,const int pos);
bool deleteByData(LinkList* linklist,const data_t data);
bool removeFirst(LinkList* linklist);
bool removeLast(LinkList* linklist);

bool changeByPos(LinkList* linklist,const int pos,const data_t data);
bool changeByData(LinkList* linklist,const data_t n,const data_t m);

void showLinkList(const LinkList* linklist);

#endif  //_LINKLIST_H