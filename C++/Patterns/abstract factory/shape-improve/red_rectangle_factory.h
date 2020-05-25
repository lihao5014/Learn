#ifndef _COLOR_FACTORY_H
#define _COLOR_FACTORY_H

#include "abstract_factory.h"
#include "rectangle.h"
#include "red.h"


class RedRectangleFactory:public AbstractFactory
{
public:
	virtual Shape* createShape()
	{
		return new Rectangle();
	}
	
	virtual Color* createColor()
	{
		return new Red();
	}
};

#endif //_COLOR_FACTORY_H