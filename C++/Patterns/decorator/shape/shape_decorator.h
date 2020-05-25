#ifndef _SHAPE_DECORATOR_H
#define _SHAPE_DECORATOR_H

#include "shape.h"

class ShapeDecorator:public Shape
{
public:
	ShapeDecorator(Shape* shape):shape(shape){}
	virtual ~ShapeDecorator(){}
	virtual void draw(){
		if(shape != nullptr)
			shape->draw();
	}
protected:
	Shape* shape;
};

#endif //_SHAPE_DECORATOR_H