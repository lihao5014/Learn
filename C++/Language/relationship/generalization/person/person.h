#ifndef _PERSON_H
#define _PERSON_H

#include <string>
#include <iostream>

using std::cout;
using std::endl;

class Person
{
public:
	Person(const std::string name = "");
	Person(const Person& other);
	virtual ~Person();
	
	void setName(const std::string name);
	std::string getName()const;
	
	virtual void show();
protected:
	std::string name;
};

Person::Person(const std::string name)
	:name(name)
{
	
}

Person::Person(const Person& other)
	:name(other.name)
{
	
}

Person::~Person()
{
	
}
	
void Person::setName(const std::string name)
{
	this->name = name;
}

std::string Person::getName()const
{
	return name;
}

void Person::show()
{
	cout<<"name ="<<name<<endl;
}

#endif //_PERSON_H