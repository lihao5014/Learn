#ifndef _CONCRETE_STRATEGY_H
#define _CONCRETE_STRATEGY_H

#include "istrategy.h"
#include <iostream>

class BikeStrategy:public IStrategy
{
public:
	virtual void travel()override
	{
		std::cout << "Travel by bike" << std::endl;
	}
};

class CarStrategy:public IStrategy
{
public:	
	virtual void travel()override
	{
		std::cout << "Travel by Car" << std::endl;
	}
};

class TrainStrategy:public IStrategy
{
public:	
	virtual void travel()override
	{
		std::cout << "Travel by Train" << std::endl;
	}
};

#endif //_CONCRETE_STRATEGY_H