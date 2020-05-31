#include "point.h"
#include <stdio.h>

int main()
{
    Point point,point1;

    Point_Ctor(&point,10,20);
    point.display(&point);

    point.setX(&point,30);
    point.setY(&point,40);
    point.display(&point);

    Point_Dtor(&point);
	
	Point_Ctor(&point1,30,20);
	point1.display(&point1);
	
	point1.setXY(&point1,50,10);
	point1.display(&point1);
	
	Point_Dtor(&point1);

	getchar();
    return 0;
}