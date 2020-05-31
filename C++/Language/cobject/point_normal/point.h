#ifndef _POINT_H
#define _POINT_H

typedef int data_t;

typedef struct
{
    data_t x;
    data_t y;    
}Point;

void Point_Ctor(Point *point,const data_t x,const data_t y);
void Point_Dtor(Point *point);

void setX(Point *point,const data_t x);
data_t getX(const Point *point);

void setY(Point *point,const data_t y);
data_t getY(const Point *point);

void setXY(Point *point,const data_t x,const data_t y);
void display(const Point *point);

#endif //_POINT_H