#ifndef _FACTORY_H
#define _FACTORY_H

#include "icar.h"

class Factory
{
public:
	virtual ~Factory(){}
	virtual ICar* createCar() = 0;
	void destroyCar(ICar*& car)
	{
		if(car != nullptr){
			delete car;
			car = nullptr;
		}
	}
};

#endif //_FACTORY_H