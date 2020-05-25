#ifndef _LINKSTACK_H
#define _LINKSTACK_H

#include <stdbool.h>

typedef int data_t;

typedef struct Node{
	data_t data;
	struct Node* next;
}LinkStack;

LinkStack* createLinkStack();
void destroyLinkStack(LinkStack** linkstack);

LinkStack* initLinkStack(LinkStack* linkstack,unsigned int size,data_t data);
void clearLinkStack(LinkStack* linkstack);

bool isNull(const LinkStack* linkstack);
bool isEmpty(const LinkStack* linkstack);
int getLength(const LinkStack* linkstack);

bool pushLinkStack(LinkStack* linkstack,data_t data);
data_t popLinkStack(LinkStack* linkstack);

data_t getTop(const LinkStack* linkstack);
bool changeTop(LinkStack* linkstack,data_t data);

data_t findByPos(const LinkStack* linkstack,unsigned int pos);
int findByData(const LinkStack* linkstack,data_t data);

void showLinkStack(const LinkStack* linkstack);

#endif //_LINKSTACK_H