#ifndef _SHAPE_FACTORY_H
#define _SHAPE_FACTORY_H

#include "circle.h"
#include "rectangle.h"
#include "square.h"

class ShapeFactory
{
public:
	virtual ~ShapeFactory(){}
	virtual Shape* createShape(Color_t color) = 0;
};

class CircleFactory:public ShapeFactory
{
public:
	virtual Shape* createShape(Color_t color)
	{
		return new Circle(color);
	}
};

class RectangleFactory:public ShapeFactory
{
public:
	Shape* createShape(Color_t color)override
	{
		return new Rectangle(color);
	}
};

class SquareFactory:public ShapeFactory
{
public:
	Shape* createShape(Color_t color)final
	{
		return new Square(color);
	}
};

#endif //_SHAPE_FACTORY_H