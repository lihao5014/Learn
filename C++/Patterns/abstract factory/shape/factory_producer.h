#ifndef _FACTORY_PRODUCER_H
#define _FACTORY_PRODUCER_H

#include "shape_factory.h"
#include "color_factory.h"

typedef enum{
	SHAPE,
	COLOR
}Factory_t;

class FactoryProducer final
{
public:
	static AbstractFactory* createFactory(Factory_t type)
	{
		switch(type){
		case SHAPE:
			return new ShapeFactory();
		case COLOR:
			return new ColorFactory();
		default:
			return nullptr;
		}		
	}
};

#endif //_FACTORY_PRODUCER_H