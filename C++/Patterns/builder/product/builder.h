#ifndef _BUILDER_H
#define _BUILDER_H

#include "abstract_builder.h"

class BuilderA:public AbstractBuilder
{
public:
	virtual void buildPartA()
	{
		if(product != nullptr)
			product->setPartA(1);
	}
	
	virtual void buildPartB() 
	{
		if(product != nullptr)
			product->setPartB(2);		
	}
	
	virtual void buildPartC()
	{
		if(product != nullptr)
			product->setPartC(3);		
	}
};

class BuilderB:public AbstractBuilder
{
public:
	virtual void buildPartA()
	{
		if(product != nullptr)
			product->setPartA(4);
	}
	
	virtual void buildPartB() 
	{
		if(product != nullptr)
			product->setPartB(5);		
	}
	
	virtual void buildPartC()
	{
		if(product != nullptr)
			product->setPartC(6);		
	}
};

#endif //_BUILDER_H