#ifndef _PRODUCT_H
#define _PRODUCT_H

#include <iostream>

class Product
{
public:
	virtual ~Product(){}
	virtual Product* clone() = 0;
	virtual void show() = 0;
};

class ConcreteProductA:public Product
{
public:
	ConcreteProductA(int data = 0):data(data)
	{
		
	}
	
	ConcreteProductA(const ConcreteProductA& product)
	{
		data = product.data;
	}
	
	Product* clone()override
	{
		return new ConcreteProductA(*this);
	}
	
	virtual void show()
	{
		std::cout<<"data ="<<data<<std::endl;
	}
	
private:
	int data;
};

class ConcreteProductB:public Product
{
public:
	ConcreteProductB(int value = 0):value(value)
	{
		
	}
	
	ConcreteProductB(const ConcreteProductB& product)
	{
		value = product.value;
	}
	
	Product* clone()final
	{
		return new ConcreteProductB(*this);
	}
	
	virtual void show()
	{
		std::cout<<"value ="<<value<<std::endl;
	}
	
private:
	int value;
};

#endif //_PRODUCT_H