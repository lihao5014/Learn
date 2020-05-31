#ifndef _POINT_H
#define _POINT_H

struct Private_Data;                             //前置声明Private_Data结构体
typedef struct Private_Data Private_Data;

typedef int data_t;

typedef struct
{
	data_t z;
	Private_Data* private_data;                  //定义为Private_Data*指针类型，目的是实现私有数据的隐藏
}Point;

Point* Point_Ctor(const data_t x,const data_t y,const data_t z);
void Point_Dtor(Point **pppoint);

void setX(Point *ppoint,const data_t x);
data_t getX(const Point *ppoint);

void setY(Point *ppoint,const data_t y);
data_t getY(const Point *ppoint);

void setZ(Point *ppoint,const data_t Z);
data_t getZ(const Point *ppoint);

void setXYZ(Point *ppoint,const data_t x,const data_t y,const data_t Z);
void display(const Point *ppoint);

#endif //_POINT_H