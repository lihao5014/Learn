#ifndef _SUBASSEMBLY_H
#define _SUBASSEMBLY_H

#include "component.h"

class Subassembly
{
public:
	Subassembly(double weight,const Component& component);
	Subassembly(double weight,int id,const string& name);
	Subassembly(const Subassembly& other);
	virtual ~Subassembly();
	
	void setWeight(const double weight);
	double getWeight()const;
	
	void print()const;
private:
	double weight;
	Component *pcomponent;     //类中有成员指针，所以需要写析构函数
};

Subassembly::Subassembly(double weight,const Component& component)
	:weight(weight)
	,pcomponent(new Component(component))
{
	
}

Subassembly::Subassembly(double weight,int id,const string& name)
	:weight(weight)
	,pcomponent(new Component(id,name))
{
	
}

Subassembly::Subassembly(const Subassembly& other)
	:weight(other.weight)
	,pcomponent(new Component(*(other.pcomponent)))
{
	
}

Subassembly::~Subassembly()
{
	if(pcomponent != nullptr)
	{
		delete pcomponent;
		pcomponent = nullptr;
	}
}

void Subassembly::setWeight(const double weight)
{
	this->weight = weight;
}

double Subassembly::getWeight()const
{
	return weight;
}

void Subassembly::print()const
{
	if(pcomponent != nullptr)
	{
		pcomponent->show();
	}
	cout<<"weight ="<<weight<<endl;
}

#endif //_SUBASSEMBLY_H