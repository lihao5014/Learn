#include "animal.h"
#include <iostream>

using namespace std;

Animal::Animal()
	:m_age(0)
{
	
}

Animal::Animal(const std::string& name,int age)
	:m_name(name)
	,m_age(age)
{
	
}

Animal::Animal(const Animal& other)
	:m_name(other.m_name)
	,m_age(other.m_age)
{
	
}

void Animal::setName(const std::string& name)
{
	m_name = name;
}

const std::string& Animal::getName()const
{
	return m_name;
}

void Animal::setAge(int age)
{
	m_age = age;
}

int Animal::getAge()const
{
	return m_age;
}

void Animal::display()const
{
	cout<<m_name<<" , "<<m_age<<endl;
}