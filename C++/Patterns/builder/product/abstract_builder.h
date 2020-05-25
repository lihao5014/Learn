#ifndef _ABSTRACT_BUILDER_H
#define _ABSTRACT_BUILDER_H

#include "product.h"

class AbstractBuilder
{
public:
	virtual ~AbstractBuilder(){}
	void createProduct(){product = new Product();}
	Product* getProduct(){return product;}
	virtual void buildPartA() = 0;
	virtual void buildPartB() = 0;
	virtual void buildPartC() = 0;
protected:
	Product* product;
};

#endif //_ABSTRACT_BUILDER_H