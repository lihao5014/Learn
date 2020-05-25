#ifndef _PRODUCT_H
#define _PRODUCT_H

#include <iostream>

class Product
{
public:
	virtual ~Product(){}
	virtual void show() = 0;
};

class ProductA:public Product
{
public:
	virtual void show()
	{
		std::cout<<"I'm ProductA"<<std::endl;
	}
};

class ProductB:public Product
{
public:
	void show()override
	{
		std::cout<<"I'm ProductB"<<std::endl;
	}
};

#endif //_PRODUCT_H