#ifndef _ABSTRACT_FACTORY_H
#define _ABSTRACT_FACTORY_H

#include "shape.h"
#include "color.h"

class AbstractFactory
{
public:
	virtual ~AbstractFactory(){}
	virtual Shape* createShape() = 0;
	virtual Color* createColor() = 0;
};

#endif //_ABSTRACT_FACTORY_H