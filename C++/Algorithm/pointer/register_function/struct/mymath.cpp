#include "mymath.h"
#include <stdio.h>
#include <assert.h>

static CallBack callBack = {NULL};

data_t min(const data_t x,const data_t y)
{
	assert(callBack.min_callback != NULL);
	
	data_t min;
	min = callBack.min_callback(x,y);
	printf("%d and %d min: %d\n",x,y,min);
	return min;
}

data_t max(const data_t x,const data_t y)
{
	assert(callBack.max_callback != NULL);
	
	data_t max;
	max = callBack.max_callback(x,y);
	printf("%d and %d max: %d\n",x,y,max);
	return max;
}

bool register_callback(CallBack callback)
{	
	if(callback.min_callback == NULL || callback.max_callback == NULL){
		return false;
	}
	
	callBack.min_callback = callback.min_callback;
	callBack.max_callback = callback.max_callback;
	return true;
}
