#ifndef _CONCRETE_FACTORY_H
#define _CONCRETE_FACTORY_H

#include "factory.h"

class BenzFactory:public Factory
{
public:
	virtual Car* createCar()
	{
		return new BenzCar();
	}
	
	virtual Bike* createBike()
	{
		return new BenzBike();
	}
};

class BmwFactory:public Factory
{
public:
	Car* createCar()override
	{
		return new BmwCar();
	}
	
	Bike* createBike()override
	{
		return new BmwBike();
	}
};

class AudiFactory:public Factory
{
public:
	Car* createCar()final
	{
		return new AudiCar();
	}
	
	Bike* createBike()final
	{
		return new AudiBike();
	}
};

#endif //_CONCRETE_FACTORY_H