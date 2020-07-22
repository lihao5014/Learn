#ifndef _COMPONENT_H
#define _COMPONENT_H

#include <iostream>
#include <string>

using namespace std;

class Component
{
public:
	Component();
	Component(int id,const string& name);
	Component(const Component& other);       //不写拷贝构造函数，编译器会生成一个默认的浅拷贝构造函数
	
	void setID(const int id);
	int getID()const;
	
	void setName(const string& name);
	string getName()const;
	
	void show()const;
private:
	int id;
	string name;
};

Component::Component()
	:id(0),name("")
{
	
}

Component::Component(int id,const string& name)
	:id(id),name(name)
{
	
}

Component::Component(const Component& other)
	:id(other.id),name(other.name)
{
	
}

void Component::setID(const int id)
{
	this->id = id;
}

int Component::getID()const
{
	return id;
}

void Component::setName(const string& name)
{
	this->name = name;
}

string Component::getName()const
{
	return name;
}

void Component::show()const
{
	cout<<"id ="<<id<<" ,name ="<<name<<endl;
}

#endif //_COMPONENT_H