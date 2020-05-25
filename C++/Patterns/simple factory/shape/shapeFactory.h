#ifndef _SHAPEFACTORY_H
#define _SHAPEFACTORY_H

#include "square.h"
#include "rectangle.h"
#include "circle.h"

typedef enum ShapeType
{
	SQUARE,
	RECTANGLE,
	CIRCLE
}Shape_t;

class ShapeFactory
{
public:
	Shape* createShape(Shape_t type)
	{
		if(type == SQUARE){
			return new Square();
		}else if(type == RECTANGLE){
			return new Rectangle();
		}else if(type == CIRCLE){
			return new Circle();
		}else{
			return nullptr;
		}
	}
	
	void destroyShape(Shape* &shape)
	{
		if(shape != nullptr){
			delete shape;
			shape = nullptr;
		}
	}
};


#endif //_SHAPEFACTORY_H