#include "point.h"
#include <stdio.h>

int main()
{
    Point point,point1;

    Point_Ctor(&point,10,20,30);
    display(&point);

    setX(&point,30);
    setY(&point,40);
    display(&point);

    Point_Dtor(&point);
    display(&point);
	
	Point_Ctor(&point1,30,20,10);
	display(&point);
	display(&point1);

	getchar();
    return 0;
}