#include "point.h"
#include <stdlib.h>
#include <stdio.h>

void Point_Ctor(Point *point,const data_t x,const data_t y,const data_t z)
{
    if(point == NULL){
        printf("Point_Ctor error: point=NULL !\n");
        return ;
    }

    point->private_data.x = x;
    point->private_data.y = y;
	point->z = z;
}

void Point_Dtor(Point *point)
{
    if(point == NULL){
        printf("Point_Dtor error: point=NULL !\n");
        return ;
    }

    point->private_data.x = 0;
    point->private_data.y = 0;
	point->z = 0;
}

void setX(Point *point,const data_t x)
{
    if(point == NULL){
        printf("setX error: point=NULL !\n");
        return ;
    }

    point->private_data.x = x;
}

data_t getX(const Point *point)
{
    if(point == NULL){
        printf("getX error: point=NULL !\n");
        return -1;
    }

    return point->private_data.x;
}

void setY(Point *point,const data_t y)
{
    if(point == NULL){
        printf("setY error: point=NULL !\n");
        return ;
    }

    point->private_data.y = y;
}

data_t getY(const Point *point)
{
    if(point == NULL){
        printf("getY error: point=NULL !\n");
        return -1;
    }

    return point->private_data.y;    
}

void setZ(Point *point,const data_t z)
{
	if(point == NULL){
		printf("setZ error: point=NULL !\n");
		return ;
	}
	
	point->z = z;
}

data_t getZ(const Point *point)
{
	if(point == NULL){
		printf("getZ error: point=NULL !\n");
		return -1;
	}
	
	return point->z;
}

void setXYZ(Point *point,const data_t x,const data_t y,const data_t z)
{
    if(point == NULL){
        printf("setXY error: point=NULL !\n");
        return ;
    }

    point->private_data.x = x;
    point->private_data.y = y;
	point->z = z;
}



void display(const Point *point)
{
    if(point == NULL){
        printf("display error: point=NULL !\n");
        return ;
    }

    printf("x=%d, y=%d,z=%d\n",point->private_data.x,point->private_data.y,point->z);
}