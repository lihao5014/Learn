#ifndef _COFFEE_H
#define _COFFEE_H

#include "ibeverage.h"

class HouseBlend:public IBeverage
{
public:
	virtual std::string name()override
	{
		return std::string("House Blend");
	}
	virtual double cost()final
	{
		return 30.0;
	}
};

class DarkRoast:public IBeverage
{
public:
	std::string name()override
	{
		return "Dark Roast";     //存在const char*到string的隐式类型转换
	}
	double cost()final
	{
		return 28.5;
	}	
};

#endif //_COFFEE_H