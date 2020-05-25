#ifndef _DIRECTOR_H
#define _DIRECTOR_H

#include "person_builder.h"

class Director
{
public:
	Director(PersonBuilder* builder):builder(builder)
	{
		
	}
	
	void setBuilder(PersonBuilder* builder)
	{
		this->builder = builder;
	}
	
	void createPerson()
	{
		if(builder != nullptr){
			builder->buildHead();
			builder->buildBody();
			builder->buildFoot();
			builder->buildHand();
		}
	}
	
	Person* getPerson()
	{
		return builder->getPerson();
	}
	
private:
	PersonBuilder* builder;
};

#endif //_DIRECTOR_H
