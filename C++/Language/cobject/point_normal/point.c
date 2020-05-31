#include "point.h"
#include <stdlib.h>
#include <stdio.h>

void Point_Ctor(Point *point,const data_t x,const data_t y)
{
    if(point == NULL){
        printf("Point_Ctor error: point=NULL !\n");
        return ;
    }

    point->x = x;
    point->y = y;
}

void Point_Dtor(Point *point)
{
    if(point == NULL){
        printf("Point_Dtor error: point=NULL !\n");
        return ;
    }

    point->x = 0;
    point->y = 0;
}

void setX(Point *point,const data_t x)
{
    if(point == NULL){
        printf("setX error: point=NULL !\n");
        return ;
    }

    point->x = x;
}

data_t getX(const Point *point)
{
    if(point == NULL){
        printf("getX error: point=NULL !\n");
        return -1;
    }

    return point->x;
}

void setY(Point *point,const data_t y)
{
    if(point == NULL){
        printf("setY error: point=NULL !\n");
        return ;
    }

    point->y = y;
}

data_t getY(const Point *point)
{
    if(point == NULL){
        printf("getY error: point=NULL !\n");
        return -1;
    }

    return point->y;    
}

void setXY(Point *point,const data_t x,const data_t y)
{
    if(point == NULL){
        printf("setXY error: point=NULL !\n");
        return ;
    }

    point->x = x;
    point->y = y;
}

void display(const Point *point)
{
    if(point == NULL){
        printf("display error: point=NULL !\n");
        return ;
    }

    printf("x=%d, y=%d\n",point->x,point->y);
}