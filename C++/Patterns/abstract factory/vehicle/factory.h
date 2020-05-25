#ifndef _FACTORY_H
#define _FACTORY_H

#include "car.h"
#include "bike.h"

class Factory
{
public:
	enum Factory_t
	{
		BENZ_FACTORY,
		BWM_FACTORY,
		AUDI_FACTORY
	};
	
	virtual ~Factory(){}
	virtual Car* createCar() = 0;
	virtual Bike* createBike() = 0;
	
	static Factory* createFactory(Factory_t type);
};

#endif //_FACTORY_H