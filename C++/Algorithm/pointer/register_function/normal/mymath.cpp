#include "mymath.h"
#include <stdio.h>
#include <assert.h>

static pFunc min_callback = NULL;
static pFunc max_callback = NULL;

data_t min(const data_t x,const data_t y)
{
	assert(min_callback != NULL);
	
	data_t min;
	min = min_callback(x,y);
	printf("%d and %d min: %d\n",x,y,min);
	return min;
}

data_t max(const data_t x,const data_t y)
{
	assert(max_callback != NULL);
	
	data_t max;
	max = max_callback(x,y);
	printf("%d and %d max: %d\n",x,y,max);
	return max;
}

bool register_min(pFunc pfunc)
{
	if(pfunc == NULL){
		return false;
	}
	
	min_callback = pfunc;
	return true;
}

bool register_max(pFunc pfunc)
{
	if(pfunc == NULL){
		return false;
	}
	
	max_callback = pfunc;
	return true;
}