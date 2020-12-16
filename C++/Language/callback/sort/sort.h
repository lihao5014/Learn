//C语言中宏和回调函数是实现软件框架的两种重要技术，框架或库开发程序员必须精通这两种技术。
//而对于一般的应用程序开发人员来说，对宏和回调函数的使用要求没有那么高。

//C++中开发软件框架的技术有宏、回调函数和多态。

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