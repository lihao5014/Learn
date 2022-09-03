#include <cstdio>
#include "mymath.h"

extern "C" 
{
#include "point.h"	
}

int main(void)
{
	data_t ret = add(3.14,2.718);
	printf("3.14 + 2.718 =%f\n",ret);
	
	ret = sub(9.78,0.618);
	printf("9.78 - 0.618 =%f\n",ret);	
	
	PointPtr ppoint = createPoint(6.5,7.5);
	showPoint(ppoint);
	
	int y = getPointY(ppoint);
	setPointY(ppoint,y + 10);
	setPointY(ppoint,15.05);
	showPoint(ppoint);
	
	return 0;
}