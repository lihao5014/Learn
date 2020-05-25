#ifndef _COMMODITY_H
#define _COMMODITY_H

#include <iostream>

class Commodity
{
public:
	virtual ~Commodity(){}
	virtual void display() = 0;
};

class CommodityA:public Commodity
{
public:
	virtual void display()
	{
		std::cout<<"I'm CommodityA"<<std::endl;
	}
};

class CommodityB:public Commodity
{
public:
	void display()final
	{
		std::cout<<"I'm CommodityB"<<std::endl;
	}
};

#endif //_COMMODITY_H