#ifndef _PARENT_H
#define _PARENT_H

#include "person.h"

class Parent:public Person
{
public:
	Parent(const std::string name = "",int age = 0);
	Parent(const Parent& other);
	virtual ~Parent();
	
	void setAge(const int age);
	int getAge()const;
	
	void show();
protected:
	int age;
};

Parent::Parent(const std::string name,const int age)
	:Person(name)
	,age(age)
{
	
}

Parent::Parent(const Parent& other)
	:Person(other.name)
	,age(other.age)
{
	
}

Parent::~Parent()
{
	
}

void Parent::setAge(const int age)
{
	this->age = age;
}

int Parent::getAge()const
{
	return age;
}

void Parent::show()
{
	Person::show();
	cout<<"age ="<<age<<endl;
}

#endif //_PARENT_H