#include "point.h"
#include <stdlib.h>
#include <stdio.h>

static Private_Data *private_data;

static void setX(const data_t x);
static data_t getX();

static void setY(const data_t y);
static data_t getY();

static void setXY(const data_t x,const data_t y);
static void display();

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

    private_data = &point->private_data;
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

void setX(const data_t x)
{
    private_data->x = x;
}

data_t getX(const Point *point)
{
    return private_data->x;
}

void setY(const data_t y)
{
    private_data->y = y;
}

data_t getY(const Point *point)
{
    return private_data->y;    
}

void setXY(const data_t x,const data_t y)
{
    private_data->x = x;
    private_data->y = y;
}

void display()
{
    printf("x=%d, y=%d\n",private_data->x,private_data->y);
}