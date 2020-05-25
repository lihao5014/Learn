#ifndef _LINKQUEUE_H
#define _LINKQUEUE_H

#include <stdbool.h>

typedef int data_t;

typedef struct node
{
	data_t data;
	struct node *next;
}Node;

typedef struct
{
	Node *rear;
	Node *front;
}LinkQueue;

LinkQueue* createLinkQueue();
void destroyLinkQueue(LinkQueue** linkqueue);

LinkQueue* initLinkQueue(LinkQueue* linkqueue,unsigned int size,data_t data);
void clearLinkQueue(LinkQueue* linkqueue);

bool isNull(const LinkQueue* linkqueue);
bool isEmpty(const LinkQueue* linkqueue);
int getLength(const LinkQueue* linkqueue);

bool pushLinkQueue(LinkQueue* linkqueue,data_t data);
data_t popLinkQueue(LinkQueue* linkqueue);

data_t getFront(const LinkQueue* linkqueue);
data_t getRear(const LinkQueue* linkqueue);

bool changeFront(LinkQueue* linkqueue,data_t data);
bool changeRear(LinkQueue* linkqueue,data_t data);

data_t findByPos(const LinkQueue* linkqueue,unsigned int pos);
int findByData(const LinkQueue* linkqueue,data_t data);

void showLinkQueue(const LinkQueue* linkqueue);

#endif //_LINKQUEUE_H