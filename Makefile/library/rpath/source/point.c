#include "point.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

PointPtr createPoint(data_t x,data_t y)
{
	PointPtr ppoint = (PointPtr)malloc(sizeof(Point));
	if(ppoint == NULL)
	{
		puts("createPoint error: ppoint malloc failed");
		return NULL;
	}
	ppoint->m_x = x;
	ppoint->m_y = y;
	
	return ppoint;
}

void destroyPoint(PointPtr* pppoint)
{
	if(*pppoint != NULL)
	{
		free(*pppoint);
		*pppoint = NULL;
	}
}

void setPointX(PointPtr ppoint,const data_t x)
{
	if(ppoint == NULL)
	{
		fputs("setX error: ppoint is null\n",stdout);
		return ;
	}
	ppoint->m_x = x;
}

data_t getPointX(const PointPtr ppoint)
{
	assert(ppoint != NULL);
	return ppoint->m_x;
}

void setPointY(PointPtr ppoint,const data_t y)
{
	if(ppoint == NULL)
	{
		fprintf(stdout,"setX error: ppoint is null\n");
		return ;
	}
	
	ppoint->m_y = y;	
}

data_t getPointY(const PointPtr ppoint)
{
	assert(ppoint != NULL);
	return ppoint->m_y;	
}

void showPoint(const PointPtr ppoint)
{
	if(ppoint == NULL)
	{
		printf(" showPoint warn: ppoint is null\n");
		return ;
	}
	
	printf("(%d,%d)\n",ppoint->m_x,ppoint->m_y);
}