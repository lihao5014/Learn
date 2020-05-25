#ifndef _DECORATOR_H
#define _DECORATOR_H

#include "shape.h"

class Decorator:public Shape
{
public:
	Decorator(Shape* shape):shape(shape){}
	virtual ~Decorator(){}
	virtual void draw(){
		if(shape != nullptr)
			shape->draw();
		setRedBorder();
	}
protected:
	void setRedBorder()
	{
		std::cout<<"Border Color: red"<<std::endl;
	}
	
	Shape* shape;
};

#endif //_SHAPE_DECORATOR_H