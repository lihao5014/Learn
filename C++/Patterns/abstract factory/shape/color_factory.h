#ifndef _COLOR_FACTORY_H
#define _COLOR_FACTORY_H

#include "abstract_factory.h"
#include "rectangle.h"
#include "square.h"
#include "circle.h"
#include "red.h"
#include "green.h"
#include "blue.h"

class ColorFactory:public AbstractFactory
{
public:
	Shape* createShape(Shape_t type)
	{
		throw (char*)"color factory isn't implemented";
	}
	
	Color* createColor(Color_t type)
	{
		switch(type){
		case RED:
			return new Red();
		case GREEN:
			return new Green();
		case BLUE:
			return new Blue();
		default:
			return nullptr;
		}
	}
};

#endif //_COLOR_FACTORY_H