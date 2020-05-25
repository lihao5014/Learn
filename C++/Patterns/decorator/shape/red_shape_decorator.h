#ifndef _RED_SHAPE_DECORATOR_H
#define _RED_SHAPE_DECORATOR_H

#include "shape_decorator.h"
#include <iostream>

class RedShapeDecorator:public ShapeDecorator
{
public:
	RedShapeDecorator(Shape* shape):ShapeDecorator(shape){}
	void draw()override
	{
		shape->draw();
		setRedBorder();
	}
private:
	void setRedBorder()
	{
		std::cout<<"Border Color: red"<<std::endl;
	}
};

#endif //_RED_SHAPE_DECORATOR_H