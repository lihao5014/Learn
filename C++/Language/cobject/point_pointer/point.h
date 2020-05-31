//使用在函数指针中再传入Point指针，可以实现c语言中的函数同名

#ifndef _POINT_H
#define _POINT_H

typedef int data_t;

typedef struct{
	data_t x;
    data_t y;
}Private_Data;

typedef struct Point
{
	Private_Data private_data;
	void (*setX)(struct Point *point,const data_t x);
	data_t (*getX)(const struct Point *point);
	void (*setY)(struct Point *point,const data_t x);
	data_t (*getY)(const struct Point *point);
	void (*setXY)(struct Point *point,const data_t x,const data_t y);
	void (*display)(const struct Point *point);	
}Point;

void Point_Ctor(Point *point,const data_t x,const data_t y);
void Point_Dtor(Point *point);

#endif //_POINT_H