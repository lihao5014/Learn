#include <assert.h>

const double EPSINON = 0.00001;

int add(int x,int y)
{
	return x+y;
}

int sub(int x,int y)
{
	return x-y;
}

static int mutl(int x,int y)
{
	return x*y;
}

double div(int x,int y)
{
	assert(y != 0);
	
	return (double)x/y;
}

/*
double div(double x,double y)
{
	if((y > -EPSINON && y < EPSINON))
	{
		return -1;
	}
	
	return x/y;
}
*/