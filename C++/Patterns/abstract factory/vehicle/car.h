#ifndef _ICAR_H
#define _ICAR_H

#include <iostream>

class Car
{
public:
	virtual ~Car(){}
	virtual void show() = 0;
};

class BenzCar:public Car
{
public:	
	virtual void show()
	{
		std::cout<<"Benz car"<<std::endl;
	}
};

class BmwCar:public Car
{
public:
	void show()override
	{
		std::cout<<"Bmw car"<<std::endl;
	}
};

class AudiCar:public Car
{
public:
	void show()final
	{
		std::cout<<"Audi car"<<std::endl;
	}
};

#endif //_CAR_H