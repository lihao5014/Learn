#include "vector.h"
#include <stdio.h>
#include <stdlib.h>

BOOL vectorInit(vector_t *pvector,data_t x,data_t y)
{
	if(pvector == NULL)
	{
		fputs("vectorInit warn: pvector is null\n",stdout);
		return FALSE;
	}
	
	(*pvector)[0] = x;
	(*pvector)[1] = y;
	return TRUE;
}

data_t vectorX(const vector_t vector)
{
	return vector[0];
}

data_t vectorY(const vector_t vector)
{
	return *(vector + 1);
}

BOOL vectorAdd(const vector_t vector1,const vector_t vector2,vector_t *ret)
{
	if(ret == NULL)
	{
		return FALSE;
	}
	
	(*ret)[0] = vector1[0] + vector2[0];
	(*ret)[1] = vector1[1] + vector2[1];
	return TRUE;
}

BOOL vectorSub(const vector_t vector1,const vector_t vector2,vector_t *ret)
{
	if(ret == NULL)
	{
		return FALSE;
	}
	
	(*ret)[0] = *vector1 - *vector2;
	(*ret)[1] = *(vector1 + 1) - *(vector2 + 1);
	return TRUE;
}

data_t vectorMult(const vector_t vector1,const vector_t vector2)
{
	return vector1[0] * vector2[0] + *(vector1 + 1) * (*(vector2 + 1));
}

void printVector(const vector_t vector)
{
	for(int i=0;i<SIZE;++i)
	{
		printf("%d ",vector[i]);
	}
	putchar('\n');
}