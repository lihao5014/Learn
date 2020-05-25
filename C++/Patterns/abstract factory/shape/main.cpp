#include "factory_producer.h"

int main()
{
	AbstractFactory* factory = FactoryProducer::createFactory(SHAPE);
	Shape* shape = factory->createShape(RECTANGLE);
	shape->draw();
	delete shape;
	
	shape = factory->createShape(SQUARE);
	shape->draw();
	delete shape;
	delete factory;
	
	factory = FactoryProducer::createFactory(COLOR);
	Color* color = factory->createColor(RED);
	color->fill();
	delete color;
	
	color = factory->createColor(GREEN);
	color->fill();
	delete color;
	delete factory;	
	
	return 0;
}