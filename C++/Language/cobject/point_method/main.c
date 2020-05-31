#include "point.h"
#include <stdio.h>

int main()
{
    Point point,point1;

    Point_Ctor(&point,10,20);
    point.display();

    point.setX(30);
    point.setY(40);
    point.display();

    Point_Dtor(&point);
	
	Point_Ctor(&point1,30,20);
	point1.display();
	
	point1.setXY(40,50);
	point1.display();
	
	Point_Dtor(&point1);

	getchar();
    return 0;
}