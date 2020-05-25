#include <stdio.h>

typedef int data_t;

typedef data_t (*pFunc)(const data_t x,const data_t y);

void min(const data_t x,const data_t y,pFunc pfunc);
void max(const data_t x,const data_t y,pFunc pfunc);

static data_t min_callback(const data_t x,const data_t y);
static data_t max_callback(const data_t x,const data_t y);

int main()
{
	data_t x=11,y=15;
	
	min(x,y,min_callback);
	max(x,y,max_callback);
	
	return 0;
}

void min(const data_t x,const data_t y,pFunc pfunc)
{
	printf("%d and %d min: %d\n",x,y,pfunc(x,y));
}

void max(const data_t x,const data_t y,pFunc pfunc)
{
	printf("%d and %d max: %d\n",x,y,pfunc(x,y));
}

data_t min_callback(const data_t x,const data_t y)
{
	return x < y ? x : y;
}

data_t max_callback(const data_t x,const data_t y)
{
	return x > y ? x : y;
}