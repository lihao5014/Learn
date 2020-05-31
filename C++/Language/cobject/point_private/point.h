#ifndef _POINT_H
#define _POINT_H

typedef int data_t;

typedef struct
{
	data_t x;
    data_t y;
}Private_Data;

typedef struct
{
	data_t z;
	Private_Data private_data;
}Point;

void Point_Ctor(Point *point,const data_t x,const data_t y,const data_t z);
void Point_Dtor(Point *point);

void setX(Point *point,const data_t x);
data_t getX(const Point *point);

void setY(Point *point,const data_t y);
data_t getY(const Point *point);

void setZ(Point *point,const data_t Z);
data_t getZ(const Point *point);

void setXYZ(Point *point,const data_t x,const data_t y,const data_t Z);
void display(const Point *point);

#endif //_POINT_H