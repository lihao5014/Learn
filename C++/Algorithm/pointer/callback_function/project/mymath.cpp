#include "mymath.h"
#include <stdio.h>

void min(const data_t x,const data_t y,pFunc pfunc)
{
	printf("%d and %d min: %d\n",x,y,pfunc(x,y));
}

void max(const data_t x,const data_t y,pFunc pfunc)
{
	printf("%d and %d max: %d\n",x,y,pfunc(x,y));
}