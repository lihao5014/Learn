#ifndef _FACTORY_PRODUCER_H
#define _FACTORY_PRODUCER_H

#include "abstract_factory.h"
#include "circle.h"
#include "blue.h"

class BlueCircleFactory:public AbstractFactory
{
public:
	Shape* createShape()override
	{
		return new Circle();
	}
	
	Color* createColor()override
	{
		return new Blue();
	}
};

#endif //_FACTORY_PRODUCER_H