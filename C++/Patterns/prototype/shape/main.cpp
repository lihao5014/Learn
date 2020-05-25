#include "rectangle.h"
#include "square.h"
#include "circle.h"

int main()
{
	Shape* shape = new Rectangle("rectangle",20);
	shape->draw();
	Shape* shape1 = shape->clone();
	shape1->draw();
	delete shape1;
	delete shape;
	
	shape = new Square("square",20);
	shape->draw();
	shape1 = shape->clone();
	shape1->draw();
	delete shape1;
	delete shape;
	
	shape = new Circle("circle",20);
	shape->draw();
	shape1 = shape->clone();
	shape1->draw();
	delete shape1;
	delete shape;
	
	return 0;
}