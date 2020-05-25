#ifndef _POINT_H
#define _POINT_H

struct Point;                     //前置声明Point结构体，在源文件中定义Point结构体，已到达隐藏Point结构体实现的目的

typedef int data_t;
typedef struct Point Point;

Point* point_ctor(data_t x,data_t y);        //创建Point对象，并返回Point指针，或Point句柄
void point_dtor(Point** pppoint);            //根据Point句柄去销毁Point对象

void setX(Point* ppoint,const data_t x);
data_t getX(const Point* ppoint);

void setY(Point* ppoint,const data_t y);
data_t getY(const Point* ppoint);

void display(const Point* ppoint);

#endif //_POINT_H