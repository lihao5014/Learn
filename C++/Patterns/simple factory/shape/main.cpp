#include "shapeFactory.h"

int main()
{
	ShapeFactory factory;
	Shape* shape = factory.createShape(SQUARE);
	shape->draw();
	factory.destroyShape(shape);
	
	shape = factory.createShape(RECTANGLE);
	shape->draw();
	factory.destroyShape(shape);
	
	shape = factory.createShape(CIRCLE);
	shape->draw();
	factory.destroyShape(shape);
	
	return 0;
}