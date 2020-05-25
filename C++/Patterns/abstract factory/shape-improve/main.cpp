#include "red_rectangle_factory.h"
#include "blue_circle_factory.h"

int main()
{
	AbstractFactory* factory = new RedRectangleFactory();
	Shape* shape = factory->createShape();
	Color* color = factory->createColor();
	shape->draw();
	color->fill();
	delete color;
	delete shape;
	delete factory;
	
	factory = new BlueCircleFactory();
	shape = factory->createShape();
	color = factory->createColor();
	shape->draw();
	color->fill();
	delete color;
	delete shape;
	delete factory;
	
	return 0;
}