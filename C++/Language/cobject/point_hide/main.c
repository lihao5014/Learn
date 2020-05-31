#include "point.h"
#include <stdio.h>

int main(void)
{
    Point* ppoint = Point_Ctor(10,20,30);
    display(ppoint);

    setX(ppoint,30);
    setY(ppoint,40);
    display(ppoint);

    Point_Dtor(&ppoint);
	
	Point* ppoint1 = Point_Ctor(30,20,10);
	display(ppoint1);
	Point_Dtor(&ppoint1);

	// getchar();
    return 0;
}