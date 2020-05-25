#ifndef _MESSAGE_QUEUE_H
#define _MESSAGE_QUEUE_H

#include "action.h"
#include <stdbool.h>

#define SIZE 5

#define DEBUG_FLAG printf("[%s %s] line:%d\n",__FILE__,__func__,__LINE__);

typedef struct Signal_t
{
	double x;
	double y;
	Action_t action;
}Signal_t;

extern Signal_t msgQueue[SIZE];         //头文件中extern定义的全局变量可以不指定大小。

extern void initMsg(const Signal_t msgArr[],int size);
extern void inputMsg();
extern void clearMsg();

extern bool isEmpty();
extern bool isFull();

extern bool pushMsg(const Signal_t msg);
extern Signal_t popMsg();

extern int countMsg();
extern void processMsg();

extern void showMsg();
extern void msgLoop();

#endif  //_MESSAGE_QUEUE_H