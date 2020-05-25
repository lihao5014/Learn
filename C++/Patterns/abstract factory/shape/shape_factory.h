#ifndef _SHAPE_FACTORY_H
#define _SHAPE_FACTORY_H

#include "abstract_factory.h"
#include "rectangle.h"
#include "square.h"
#include "circle.h"
#include "red.h"
#include "green.h"
#include "blue.h"

class ShapeFactory:public AbstractFactory
{
public:
	Shape* createShape(Shape_t type)
	{
		switch(type){
		case RECTANGLE:
			return new Rectangle();
		case SQUARE:
			return new Square();
		case CIRCLE:
			return new Circle();
		default:
			return nullptr;
		}
	}
	
	Color* createColor(Color_t type)
	{
		throw const_cast<char*>("shape factory isn't implemented");
	}
};

#endif //_SHAPE_FACTORY_H