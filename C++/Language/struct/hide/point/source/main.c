#include "point.h"
#include <stdio.h>

int main(void)
{
	Point* ppoint = point_ctor(3,4);
	display(ppoint);
	
	putc('\n',stdout);
	setX(ppoint,10);
	setY(ppoint,20);
	display(ppoint);
	
	point_dtor(&ppoint);
	return 0;
}