#ifndef _FELIDAE_H
#define _FELIDAE_H

#include "animal.h"

class Felidae:public Animal
{
public:
	Felidae(const string& name,int age);
	Felidae(const Felidae& other);
	virtual ~Felidae();
	
	void move()const;
};

Felidae::Felidae(const string& name,int age)
	:Animal(name,age)
{
	
}

Felidae::Felidae(const Felidae& other)
	:Animal(other)
{
	
}

Felidae::~Felidae()
{
	
}

void Felidae::move()const
{
	cout<<"felidae can climb"<<endl;
}

#endif //_FELIDAE_H