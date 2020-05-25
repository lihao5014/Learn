#ifndef _CONCRETE_CONDIMENT_H
#define _CONCRETE_CONDIMENT_H

#include "condiment.h"

class Cream:public Condiment
{
public:
	Cream(IBeverage* beverage):Condiment(beverage){}
	
	std::string name()override
	{
		return beverage->name()+" Cream";
	}
	
	double cost()final{
		return beverage->cost()+3.5;
	}
};

class Mocha:public Condiment
{
public:
	Mocha(IBeverage* beverage):Condiment(beverage){}
	
	std::string name()override
	{
		return beverage->name()+" Mocha";
	}
	
	double cost()final{
		return beverage->cost()+2.5;
	}
};

class Syrup:public Condiment
{
public:
	Syrup(IBeverage* beverage):Condiment(beverage){}
	
	std::string name()override
	{
		return beverage->name()+" Syrup";
	}
	
	double cost()final{
		return beverage->cost()+3.0;
	}
};

#endif //_CONCRETE_CONDIMENT_H