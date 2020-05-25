#ifndef _CANIDAE_H
#define _CANIDAE_H

#include "animal.h"

class Canidae:public Animal
{
public:
	Canidae(const string& name,const int age);
	Canidae(const Canidae& other);
	virtual ~Canidae();
	
	void move()const final;
};

Canidae::Canidae(const string& name,const int age)
	:Animal(name,age)
{
	
}

Canidae::Canidae(const Canidae& other)
	:Animal(other)                            //Canidae隐式转换为了Animal类型
{
	
}

Canidae::~Canidae()
{
	
}

void Canidae::move()const
{
	cout<<"canidae can run"<<endl;
}

#endif //_CANIDAE_H