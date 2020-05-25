#ifndef _FACTORY_H
#define _FACTORY_H

#include "product.h"

class Factory
{
public:
	virtual ~Factory(){}
	virtual Product* createProduct() = 0;
	void destroyProduct(Product*& product)
	{
		if(product != nullptr){
			delete product;
			product = nullptr;
		}
	}
};

class ProductAFactory:public Factory
{
public:
	Product* createProduct()
	{
		return new ProductA();
	}
};

class ProductBFactory:public Factory
{
public:
	Product* createProduct()
	{
		return new ProductB();
	}
};

class ProductCFactory:public Factory
{
public:
	Product* createProduct()
	{
		return new ProductC();
	}
};

#endif //_FACTORY_H