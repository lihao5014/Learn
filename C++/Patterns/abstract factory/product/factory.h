#ifndef _FACTORY_H
#define _FACTORY_H

#include "product.h"
#include "commodity.h"

class Factory
{
public:
	virtual ~Factory(){}
	virtual Product* createProduct() = 0;
	virtual Commodity* createCommodity() = 0;
};

class FactoryA:public Factory
{
public:
	Product* createProduct()
	{
		return new ProductA();
	}
	
	Commodity* createCommodity()
	{
		return new CommodityA();
	}	
};

class FactoryB:public Factory
{
public:
	Product* createProduct()
	{
		return new ProductB();
	}
	
	Commodity* createCommodity()
	{
		return new CommodityB();
	}	
};

#endif //_FACTORY_H