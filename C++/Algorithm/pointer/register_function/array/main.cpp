#include "mymath.h"

static data_t min_callback(const data_t x,const data_t y);
static data_t max_callback(const data_t x,const data_t y);

int main()
{
	data_t x=10,y=15;
	
	pFunc callback[] = {
		min_callback,
		max_callback
	};
	
	register_callback(callback,sizeof(callback)/sizeof(callback[0]));
	
	min(x,y);
	max(x,y);
	
	return 0;
}

data_t min_callback(const data_t x,const data_t y)
{
	return x < y ? x : y;
}

data_t max_callback(const data_t x,const data_t y)
{
	return x > y ? x : y;
}