#include "point.h"
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

typedef struct Point
{
	data_t x;
	data_t y;
}Point;

handle_t createPoint(data_t x,data_t y)
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

void destroyPoint(handle_t* handle)
{
	if(*handle != NULL)
	{
		free(*handle);
		*handle = NULL;
	}
}

void setX(handle_t handle,const data_t x)
{
	if(handle == NULL)
	{
		fputs("setX error: handle is null\n",stdout);
		return ;
	}
	
	Point* ppoint = (Point*)handle;
	ppoint->x = x;
}

data_t getX(const handle_t handle)
{
	assert(handle != NULL);
	
	Point* ppoint = (Point*)handle;
	return ppoint->x;
}

void setY(handle_t handle,const data_t y)
{
	if(handle == NULL)
	{
		fprintf(stdout,"setX error: handle is null\n");
		return ;
	}
	
	Point* ppoint = (Point*)handle;
	ppoint->y = y;	
}

data_t getY(const handle_t handle)
{
	assert(handle != NULL);
	
	Point* ppoint = (Point*)handle;
	return ppoint->y;	
}

void display(const handle_t handle)
{
	if(handle == NULL)
	{
		printf("display error: handle is null\n");
		return ;
	}
	
	Point* ppoint = (Point*)handle;
	printf("(%d,%d)\n",ppoint->x,ppoint->y);
}