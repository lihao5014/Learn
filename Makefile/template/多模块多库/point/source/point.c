#include "point.h"
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

typedef struct Point
{
	union {
		Point public_point;
		data_t m_x;
	};
	data_t m_y;
}PointPrivate;

Point* createPoint(data_t x,data_t y)
{
	PointPrivate *private_point = (PointPrivate*)malloc(sizeof(PointPrivate));
	if(private_point == NULL)
	{
		puts("createPoint error: private_point malloc failed");
		return NULL;
	}
	private_point->m_x = x;
	private_point->m_y = y;
	
	return &(private_point->public_point);
}

void destroyPoint(Point** pPointPtr)
{
	if(*pPointPtr != NULL)
	{
		free(*pPointPtr);
		*pPointPtr = NULL;
	}
}

void setPointX(Point* pointPtr,const data_t x)
{
	if(pointPtr == NULL)
	{
		fputs("setX error: pointPtr is null\n",stdout);
		return ;
	}
	
	PointPrivate* private_point = (PointPrivate*)pointPtr;
	private_point->m_x = x;
}

data_t getPointX(const Point* pointPtr)
{
	assert(pointPtr != NULL);
	
	PointPrivate* private_point = (PointPrivate*)pointPtr;
	return private_point->m_x;
}

void setPointY(Point* pointPtr,const data_t y)
{
	if(pointPtr == NULL)
	{
		fprintf(stdout,"setX error: pointPtr is null\n");
		return ;
	}
	
	PointPrivate* private_point = (PointPrivate*)pointPtr;
	private_point->m_y = y;	
}

data_t getPointY(const Point* pointPtr)
{
	assert(pointPtr != NULL);
	
	PointPrivate* private_point = (PointPrivate*)pointPtr;
	return private_point->m_y;	
}

void displayPoint(const Point* pointPtr)
{
	if(pointPtr == NULL)
	{
		printf("display error: pointPtr is null\n");
		return ;
	}
	
	PointPrivate* private_point = (PointPrivate*)pointPtr;
	printf("(%f,%f)\n",private_point->m_x,private_point->m_y);
}