#include "mymath.h"

static data_t min_callback(const data_t x,const data_t y);
static data_t max_callback(const data_t x,const data_t y);

int main()
{
	data_t x=11,y=15;
	
	min(x,y,min_callback);
	max(x,y,max_callback);
	
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