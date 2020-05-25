#include <stdio.h>

typedef int data_t;

typedef data_t (*pFunc)(const data_t x,const data_t y);

static data_t min(const data_t x,const data_t y);
static data_t max(const data_t x,const data_t y);

int main()
{
	data_t x=10,y=15;
	pFunc pfunc;

#if 1	
	pfunc = &min;
#else
    pfunc = min;
#endif
	printf("%d and %d min: %d\n",x,y,pfunc(x,y));

	pfunc = max;
	printf("%d and %d max: %d\n",x,y,pfunc(x,y));
	
	getchar();
	return 0;
}

static data_t min(const data_t x,const data_t y)
{
	return x < y ? x : y;
}
static data_t max(const data_t x,const data_t y)
{
	return x > y ? x : y;
}