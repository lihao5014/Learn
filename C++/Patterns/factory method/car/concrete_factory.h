#ifndef _CONCRETE_FACTORY
#define _CONCRETE_FACTORY

#include "factory.h"
#include "concrete_car.h"

class BenzFactory:public Factory
{
public:
	virtual ICar* createCar()
	{
		return new BenzCar();
	}
};

class BmwFactory:public Factory
{
public:
	ICar* createCar()override
	{
		return new BmwCar();
	}
};

class AudiFactory:public Factory
{
public:
	ICar* createCar()final
	{
		return new AudiCar();
	}
};

#endif //_CONCRETE_FACTORY