#ifndef _CONTAINER_H
#define _CONTAINER_H

#include "component.h"

class Container
{
public:
	Container(int size=0,const int id=-1,const string& name="");
	Container(const Container& other);
	
	void setSize(const int size);
	int getSize()const;
	
	void display()const;
private:
	int size;
	Component component;        //类中没有成员指针，所以不需要写析构函数
};

Container::Container(int size,const int id,const string& name)
	:size(size)
	,component(id,name)
{
	
}

Container::Container(const Container& other)
	:size(other.size)
	,component(other.component)
{
	
}

void Container::setSize(const int size)
{
	this->size = size;
}

int Container::getSize()const
{
	return size;
}

void Container::display()const
{
	component.show();
	cout<<"size ="<<size<<endl;
}

#endif //_CONTAINER_H