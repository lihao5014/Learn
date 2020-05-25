#include "circle.h"
#include "square.h"
#include "rectangle.h"
#include "triangle.h"
#include <stdio.h>

int main(int argc,char** argv)
{
	Circle circle(5);
	circle.draw();
	puts("");
	
	Square square(10);
	square.draw();
	puts("");
	
	Rectangle rectangle(3,4);
	rectangle.draw();
	putc('\n',stdout);
	
	Triangle triangle(3,4,5);
	triangle.draw();
	
	return 0;
}