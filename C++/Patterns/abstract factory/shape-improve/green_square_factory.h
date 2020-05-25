#ifndef _SHAPE_FACTORY_H
#define _SHAPE_FACTORY_H

#include "abstract_factory.h"
#include "square.h"
#include "green.h"

class GreenSquareFactory:public AbstractFactory
{
public:
	Shape* createShape()final
	{
		return new Square();
	}
	
	Color* createColor()final
	{
		return new Green();
	}
};

#endif //_SHAPE_FACTORY_H