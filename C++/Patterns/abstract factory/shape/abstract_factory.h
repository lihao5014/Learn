#ifndef _ABSTRACT_FACTORY_H
#define _ABSTRACT_FACTORY_H

#include "shape.h"
#include "color.h"

typedef enum
{
	RECTANGLE,
	SQUARE,
	CIRCLE	
}Shape_t;

typedef enum ColorType
{
	RED,
	GREEN,
	BLUE
}Color_t;

class AbstractFactory
{
public:
	virtual ~AbstractFactory(){}
	virtual Shape* createShape(Shape_t type) = 0;
	virtual Color* createColor(Color_t type) = 0;
};

#endif //_ABSTRACT_FACTORY_H