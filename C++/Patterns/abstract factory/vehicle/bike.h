#ifndef _BIKE_H
#define _BIKE_H

#include <iostream>

class Bike
{
public:
	virtual ~Bike(){}
	virtual void display() = 0;
};

class BenzBike:public Bike
{
public:	
	virtual void display()
	{
		std::cout<<"Benz bike"<<std::endl;
	}
};

class BmwBike:public Bike
{
public:
	void display()override
	{
		std::cout<<"Bmw bike"<<std::endl;
	}
};

class AudiBike:public Bike
{
public:
	void display()final
	{
		std::cout<<"Audi bike"<<std::endl;
	}
};

#endif //_BIKE_H