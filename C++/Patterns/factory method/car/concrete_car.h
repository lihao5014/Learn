#ifndef _CONCRETE_CAR_H
#define _CONCRETE_CAR_H

#include "icar.h"
#include <iostream>

class BenzCar:public ICar
{
public:
	std::string getName()const
	{
		return "Benz car";
	}
	
	virtual void show()
	{
		std::cout<<"Benz car"<<std::endl;
	}
};

class BmwCar:public ICar
{
public:
	std::string getName()const
	{
		return std::string("Bmw car");
	}
	
	void show()override
	{
		std::cout<<"Bmw car"<<std::endl;
	}
};

class AudiCar:public ICar
{
public:
	std::string getName()const
	{
		return std::string("Audi car");
	}
	
	void show()final
	{
		std::cout<<"Audi car"<<std::endl;
	}
};

#endif //_CONCRETE_CAR_H