#include "point.h"
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

typedef struct Point
{
	data_t x;
	data_t y;
}Point;

void* createPoint(data_t x,data_t y)
{
	Point *ppoint = (Point*)malloc(sizeof(Point));
	if(ppoint == NULL)
	{
		puts("createPoint error: ppoint malloc failed");
		return NULL;
	}
	ppoint->x = x;
	ppoint->y = y;
	
	return ppoint;
}

void destroyPoint(void** handle)
{
	if(*handle != NULL)
	{
		free(*handle);
		*handle = NULL;
	}
}

void setX(void* handle,const data_t x)
{
	if(handle == NULL)
	{
		fputs("setX error: handle is null\n",stdout);
		return ;
	}
	
	Point* ppoint = (Point*)handle;
	ppoint->x = x;
}

data_t getX(const void* handle)
{
	assert(handle != NULL);
	
	Point* ppoint = (Point*)handle;
	return ppoint->x;
}

void setY(void* handle,const data_t y)
{
	if(handle == NULL)
	{
		fprintf(stdout,"setX error: handle is null\n");
		return ;
	}
	
	Point* ppoint = (Point*)handle;
	ppoint->y = y;	
}

data_t getY(const void* handle)
{
	assert(handle != NULL);
	
	Point* ppoint = (Point*)handle;
	return ppoint->y;	
}

void display(const void* handle)
{
	if(handle == NULL)
	{
		printf("display error: handle is null\n");
		return ;
	}
	
	Point* ppoint = (Point*)handle;
	printf("(%d,%d)\n",ppoint->x,ppoint->y);
}