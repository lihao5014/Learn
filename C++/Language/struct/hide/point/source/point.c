#include "point.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct Point
{
	data_t x;
	data_t y;
};

Point* point_ctor(data_t x,data_t y)
{
	Point* ppoint = (Point*)malloc(sizeof(Point));
	if(ppoint == NULL)
	{
		puts("point_ctor error: ppoint malloc failed");
		return NULL;
	}
	ppoint->x = x;
	ppoint->y = y;
	
	return ppoint;
}

void point_dtor(Point** pppoint)
{
	if(*pppoint != NULL)
	{
		free(*pppoint);
		*pppoint = NULL;
	}
}

void setX(Point* ppoint,const data_t x)
{
	if(ppoint == NULL)
	{
		fputs("setX error: ppoint is null\n",stdout);
		return ;
	}
	
	ppoint->x = x;
}

data_t getX(const Point* ppoint)
{
	assert(ppoint != NULL);
	return ppoint->x;
}

void setY(Point* ppoint,const data_t y)
{
	if(ppoint == NULL)
	{
		printf("setY error: ppoint is null\n");
		return ;
	}
	
	ppoint->y = y;	
}

data_t getY(const Point* ppoint)
{
	if(ppoint == NULL)
	{
		fprintf(stdout,"getY error: ppoint is null\n");
		exit(-1);
	}
	
	return ppoint->y;
}

void display(const Point* ppoint)
{
	if(ppoint == NULL)
	{
		puts("display error: ppoint is null\n");
		return ;
	}
	
	printf("(%d,%d)\n",ppoint->x,ppoint->y);
}