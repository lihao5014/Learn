#ifndef _POINT_H
#define _POINT_H

typedef int data_t;

typedef struct{
	data_t x;
    data_t y;
}Private_Data;

typedef struct
{
	Private_Data private_data;
	void (*setX)(const data_t x);
	data_t (*getX)();
	void (*setY)(const data_t x);
	data_t (*getY)();
	void (*setXY)(const data_t x,const data_t y);
	void (*display)();	
}Point;

void Point_Ctor(Point *point,const data_t x,const data_t y);
void Point_Dtor(Point *point);

#endif //_POINT_H