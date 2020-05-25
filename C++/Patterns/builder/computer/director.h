#ifndef _DIRECTOR_H
#define _DIRECTOR_H

#include "concrete_builder.h"

class Director
{
public:
	Director(IBuilder* builder):builder(builder)
	{
		
	}
	
	void setBuilder(IBuilder* builder)
	{
		this->builder = builder;
	}
	
	void createComputer()
	{
		if(builder != nullptr)
		{
			builder->buildCpu();
			builder->buildGpu();
			builder->buildRam();
			builder->buildBoard();			
		}
	}
	
	Computer* getComputer()
	{
		return builder->getComputer();
	}
private:
	IBuilder* builder;
};

#endif //_DIRECTOR_H