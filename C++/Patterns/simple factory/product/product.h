#ifndef _PRODUCT_H
#define _PRODUCT_H

#include <iostream>

typedef enum ProductTypeTag
{
	TypeA,
	TypeB,
	TypeC
}ProductType;

struct Product
{
	virtual ~Product(){};		//必须要写虚析构函数，才能正常释放内存
	virtual void show() = 0;
};

class ProductA:public Product
{
public:	
	virtual ~ProductA(){std::cout<<"~ProductA()"<<std::endl;};
	virtual void show()
	{
		std::cout<<"I'm ProductA"<<std::endl;
	}
};

class ProductB:public Product
{
public:	
	virtual ~ProductB(){std::cout<<"~ProductB()"<<std::endl;};
	virtual void show()
	{
		std::cout<<"I'm ProductB"<<std::endl;
	}
};

class ProductC:public Product
{
public:	
	virtual ~ProductC(){std::cout<<"~ProductC()"<<std::endl;};
	virtual void show()
	{
		std::cout<<"I'm ProductC"<<std::endl;
	}
};

class Factory
{
public:
	Product* createProduct(ProductType type)
	{
		switch(type){
		case TypeA:
			return new ProductA();
		case TypeB:
			return new ProductB();
		case TypeC:
			return new ProductC();
		default:
			return NULL;
		}
	}
	
	void destroyProduct(Product* &product)
	{
		if(product != NULL){
			delete product;
			product = NULL;
		}
	}
};

#endif //_PRODUCT_H