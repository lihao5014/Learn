#ifndef _ANIMAL_H
#define _ANIMAL_H

#include <string>
#include <iostream>

using std::cout;
using std::endl;

using std::string;

class Animal
{
public:
	Animal(const string& name,int age);
	Animal(const Animal& other);
	virtual ~Animal();
	
	void setName(const string& name);
	string getName()const;
	
	virtual void move()const;
	void display()const;
protected:
	string name;
	int age;
};

Animal::Animal(const string& name,int age)
	:name(name)
	,age(age)
{
	
}

Animal::Animal(const Animal& other)
	:name(other.name)
	,age(other.age)
{
	
}

Animal::~Animal()
{
	
}
	
void Animal::setName(const string& name)
{
	this->name = name;
}

string Animal::getName()const
{
	return name;
}

void Animal::move()const
{
	cout<<"animal can move"<<endl;
}

void Animal::display()const
{
	cout<<"name ="<<name<<" age ="<<age<<endl;
}

#endif //_ANIMAL_H