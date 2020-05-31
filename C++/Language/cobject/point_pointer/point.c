#include "point.h"
#include <stdlib.h>
#include <stdio.h>

static void setX(Point *point,const data_t x);
static data_t getX(const Point *point);

static void setY(Point *point,const data_t y);
static data_t getY(const Point *point);

static void setXY(Point *point,const data_t x,const data_t y);
static void display(const Point *point);

void Point_Ctor(Point *point,const data_t x,const data_t y)
{
    if(point == NULL){
        printf("Point_Ctor error: point=NULL !\n");
        return ;
    }
	
	point->setX = setX;
	point->getX = getY;
	point->setY = setY;
	point->getY = getY;
	point->setXY = setXY;
	point->display = display;

	point->private_data.x = x;
	point->private_data.y = y;
}

void Point_Dtor(Point *point)
{
    if(point == NULL){
        printf("Point_Dtor error: point=NULL !\n");
        return ;
    }

	point->setX = NULL;
	point->getX = NULL;
	point->setY = NULL;
	point->getY = NULL;
	point->setXY = NULL;
	point->display = NULL;
	
    point->private_data.x = 0;
    point->private_data.y = 0;
}

void setX(Point *point,const data_t x)
{
    point->private_data.x = x;
}

data_t getX(const Point *point)
{
    return point->private_data.x;
}

void setY(Point *point,const data_t y)
{
    point->private_data.y = y;
}

data_t getY(const Point *point)
{
    return point->private_data.y;    
}

void setXY(Point *point,const data_t x,const data_t y)
{
    point->private_data.x = x;
    point->private_data.y = y;
}

void display(const Point *point)
{
    printf("x=%d, y=%d\n",point->private_data.x,point->private_data.y);
}