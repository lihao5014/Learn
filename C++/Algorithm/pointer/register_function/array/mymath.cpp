#include "mymath.h"
#include <stdio.h>
#include <assert.h>

static pFunc callBack[2] = {NULL};

data_t min(const data_t x,const data_t y)
{
	assert(callBack[0] != NULL);
	
	data_t min;
	min = callBack[0](x,y);
	printf("%d and %d min: %d\n",x,y,min);
	return min;
}

data_t max(const data_t x,const data_t y)
{
	assert(callBack[1] != NULL);
	
	data_t max;
	max = callBack[1](x,y);
	printf("%d and %d max: %d\n",x,y,max);
	return max;
}

bool register_callback(pFunc callback[],const int n)
{	
	if(callback[0] == NULL || callback[1] == NULL || n != 2){
		return false;
	}
	
	callBack[0] = callback[0];
	callBack[1] = callback[1];
	return true;
}
