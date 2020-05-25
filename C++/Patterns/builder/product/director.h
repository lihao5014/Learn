#ifndef _DIRECTOR_H
#define _DIRECTOR_H

#include "builder.h"

class Director
{
public:
	Director(AbstractBuilder* buider):buider(buider)
	{

	}
	
	void setBuilder(AbstractBuilder* buider)
	{
		this->buider = buider;
	}
	
	void createProduct()
	{
		if(buider != nullptr){
			buider->createProduct();
			buider->buildPartA();
			buider->buildPartB();
			buider->buildPartC();			
		}
	}
	
	Product* getProduct()
	{
		return buider->getProduct();
	}
protected:
	AbstractBuilder* buider;
};

#endif //_DIRECTOR_H