#include "mymath.h"
#include <cstdio>

data_t add(data_t x,data_t y)
{
	printf("add: %d + %d =%d\n",x,y,x + y);
	return x + y;
}

DLL_EXPORT data_t sub(data_t x,data_t y)
{
	fprintf(stdout,"sub: %d - %d =%d\n",x,y,x - y);
	return x - y;
}