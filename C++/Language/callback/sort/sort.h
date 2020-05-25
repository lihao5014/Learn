#ifndef _SORT_H
#define _SORT_H

#define FALSE 0
#define TRUE 1
typedef char BOOL;

typedef BOOL (*pFun)(int x,int y);

BOOL ascend(const int x,const int y);         //升续规则
BOOL descend(const int x,const int y);        //降续规则

extern void sort(int arr[],int size,const pFun pfun);
extern void display(const int arr[],const int size);

#endif //_SORT_H