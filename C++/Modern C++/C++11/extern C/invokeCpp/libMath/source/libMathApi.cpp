#include "libMathApi.h"
#include <stdio.h>
#include <stdlib.h>
#include "tools.h"
#include "Point.h"

typedef struct
{
	union{
		Point_t public_point;
		Point* m_pointClassPtr;
	};
}PointInternal;

PointPtr point_create(double x,double y)
{
	PointInternal* private_point = (PointInternal*)malloc(sizeof(PointInternal));
	if(private_point == NULL)
	{
		puts("point_create error: malloc private_point failed!");
		return NULL;
	}
	
	private_point->m_pointClassPtr = new Point(x,y);
	return &private_point->public_point;
}

void point_destroy(PointPtr* ppointPtr)
{
	if(*ppointPtr == NULL)
	{
		return;
	}
	
	PointInternal* private_point = (PointInternal*)(*ppointPtr);
	if(private_point->m_pointClassPtr != nullptr)
	{
		delete private_point->m_pointClassPtr;
		private_point->m_pointClassPtr = nullptr;
	}
	
	free(private_point);
	*ppointPtr = NULL;
}

void point_setX(PointPtr pointPtr,double x)
{
	if(pointPtr == NULL)
	{
		puts("point_setX error: pointPtr is null!");
		return;
	}
	
	PointInternal* private_point = (PointInternal*)(pointPtr);
	if(private_point->m_pointClassPtr == nullptr)
	{
		puts("point_setX error: private_point->m_pointClassPtr is null!");
		return;
	}
	private_point->m_pointClassPtr->setX(x);
}

double point_getX(const PointPtr pointPtr)
{
	if(pointPtr == NULL)
	{
		puts("point_getX error: pointPtr is null!");
		abort();
	}
	
	PointInternal* private_point = (PointInternal*)(pointPtr);
	if(private_point->m_pointClassPtr == nullptr)
	{
		puts("point_getX error: private_point->m_pointClassPtr is null!");
		exit(-1);
	}
	return private_point->m_pointClassPtr->getX();	
}

void point_setY(PointPtr pointPtr,double y)
{
	if(pointPtr == NULL)
	{
		puts("point_setY error: pointPtr is null!");
		return;
	}
	
	PointInternal* private_point = (PointInternal*)(pointPtr);
	if(private_point->m_pointClassPtr == nullptr)
	{
		puts("point_setY error: private_point->m_pointClassPtr is null!");
		return;
	}
	private_point->m_pointClassPtr->setY(y);	
}

double point_getY(const PointPtr pointPtr)
{
	if(pointPtr == NULL)
	{
		puts("point_getY error: pointPtr is null!");
		abort();
	}
	
	PointInternal* private_point = (PointInternal*)(pointPtr);
	if(private_point->m_pointClassPtr == nullptr)
	{
		puts("point_getY error: private_point->m_pointClassPtr is null!");
		exit(-1);
	}
	return private_point->m_pointClassPtr->getY();		
}

void point_display(const PointPtr pointPtr)
{
	if(pointPtr == NULL)
	{
		puts("point_display error: pointPtr is null!");
		return;
	}
	
	PointInternal* private_point = (PointInternal*)(pointPtr);
	if(private_point->m_pointClassPtr == nullptr)
	{
		puts("point_display error: private_point->m_pointClassPtr is null!");
		return;
	}
	private_point->m_pointClassPtr->display();
}

void point_add(const PointPtr point1,const PointPtr point2,PointPtr pointRet)
{
	if(point1 == NULL || point2 == NULL || pointRet == NULL)
	{
		puts("point_add error: point1 or point2 is null!");
		return;
	}
	
	PointInternal* private_point1 = (PointInternal*)(point1);
	PointInternal* private_point2 = (PointInternal*)(point2);
	PointInternal* private_pointRet = (PointInternal*)(pointRet);
	if(private_point1->m_pointClassPtr == nullptr
		|| private_point2->m_pointClassPtr == nullptr
		|| private_pointRet->m_pointClassPtr == nullptr)
	{
		puts("point_add error: private_point1->m_pointClassPtr,private_point2->m_pointClassPtr or private_pointRet->m_pointClassPtr is null!");
		return;
	}
	
	*(private_pointRet->m_pointClassPtr) = *(private_point1->m_pointClassPtr) + *(private_point2->m_pointClassPtr);
}

void point_sub(const PointPtr point1,const PointPtr point2,PointPtr pointRet)
{
	if(point1 == NULL || point2 == NULL || pointRet == NULL)
	{
		puts("point_sub error: point1 or point2 is null!");
		return;
	}
	
	PointInternal* private_point1 = (PointInternal*)(point1);
	PointInternal* private_point2 = (PointInternal*)(point2);
	PointInternal* private_pointRet = (PointInternal*)(pointRet);
	if(private_point1->m_pointClassPtr == nullptr
		|| private_point2->m_pointClassPtr == nullptr
		|| private_pointRet->m_pointClassPtr == nullptr)
	{
		puts("point_sub error: private_point1->m_pointClassPtr,private_point2->m_pointClassPtr or private_pointRet->m_pointClassPtr is null!");
		return;
	}
	
	*(private_pointRet->m_pointClassPtr) = *(private_point1->m_pointClassPtr) - *(private_point2->m_pointClassPtr);	
}

int abs_int(int n)
{
	return absolute(n);
}

double abs_float(double n)
{
	return absolute(n);
}

bool intToString(int n,char* str)
{
	return toString(n,str);
}

bool floatToString(double n,char* str)
{
	return toString(n,str);
}

int min_2i(int x,int y)
{
	return min(x,y);
}

int min_3int(int x,int y,int z)
{
	return min(x,y,z);
}

double min_2f(double x,double y)
{
	return min(x,y);
}

double min_3float(double x,double y,double z)
{
	return min(x,y,z);
}

int max_2i(int x,int y)
{
	return max(x,y);
}

int max_3int(int x,int y,int z)
{
	return max(x,y,z);
}

double max_2f(double x,double y)
{
	return max(x,y);
}

double max_3float(double x,double y,double z)
{
	return max(x,y,z);
}
