#include "point.h"
#include <stdlib.h>
#include <stdio.h>

struct Private_Data
{
	data_t x;
    data_t y;
};

Point* Point_Ctor(const data_t x,const data_t y,const data_t z)
{
	Point* ppoint = (Point*)malloc(sizeof(Point));
    if(ppoint == NULL)
	{
        printf("Point_Ctor error: ppoint malloc failed\n");
        return NULL;
    }
	
	ppoint->private_data = (Private_Data*)malloc(sizeof(Private_Data));
	if(ppoint->private_data == NULL)
	{
		puts("Point_Ctor error: ppoint->private_data malloc failed");
		free(ppoint);
		ppoint = NULL;
		return NULL;
	}
	
    ppoint->private_data->x = x;
    ppoint->private_data->y = y;
	ppoint->z = z;
	
	return ppoint;
}

void Point_Dtor(Point **pppoint)
{
    if(*pppoint != NULL)
	{
		free(*pppoint);
		*pppoint = NULL;
    }
}

void setX(Point *ppoint,const data_t x)
{
    if(ppoint == NULL || ppoint->private_data == NULL)
	{
        printf("setX error: ppoint or ppoint->private_data is null\n");
        return ;
    }

    ppoint->private_data->x = x;
}

data_t getX(const Point *ppoint)
{
    if(ppoint == NULL || ppoint->private_data == NULL)
	{
        printf("getX error: ppoint or ppoint->private_data is null\n");
        return -1;
    }

    return ppoint->private_data->x;
}

void setY(Point *ppoint,const data_t y)
{
    if(ppoint == NULL || ppoint->private_data == NULL)
	{
        printf("setY error: ppoint or ppoint->private_data is null\n");
        return ;
    }

    ppoint->private_data->y = y;
}

data_t getY(const Point *ppoint)
{
    if(ppoint == NULL || ppoint->private_data == NULL)
	{
        printf("getY error: ppoint or ppoint->private_data is null\n");
        return -1;
    }

    return ppoint->private_data->y;    
}

void setZ(Point *ppoint,const data_t z)
{
	if(ppoint == NULL)
	{
		printf("setZ error: ppoint = NULL\n");
		return ;
	}
	
	ppoint->z = z;
}

data_t getZ(const Point *ppoint)
{
	if(ppoint == NULL)
	{
		printf("getZ error: ppoint = NULL\n");
		return -1;
	}
	
	return ppoint->z;
}

void setXYZ(Point *ppoint,const data_t x,const data_t y,const data_t z)
{
    if(ppoint == NULL || ppoint->private_data == NULL)
	{
        printf("setXY error: ppoint or ppoint->private_data is null\n");
        return ;
    }

    ppoint->private_data->x = x;
    ppoint->private_data->y = y;
	ppoint->z = z;
}

void display(const Point *ppoint)
{
    if(ppoint == NULL || ppoint->private_data == NULL)
	{
        printf("display error: ppoint or ppoint->private_data is null\n");
        return ;
    }

    printf("x=%d, y=%d,z=%d\n",ppoint->private_data->x,ppoint->private_data->y,ppoint->z);
}