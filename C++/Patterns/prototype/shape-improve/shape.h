#ifndef _SHAPE_H
#define _SHAPE_H

#include <string.h>
#include <iostream>

#define SIZE 32

class Shape
{
public:
	virtual ~Shape();
	void setName(const char* name);
	char* getName();
	void setID(const int id);
	int getID()const;
	virtual Shape* clone() = 0;
	virtual void draw() = 0;
protected:
	char m_name[SIZE];
	int m_id;
};

Shape::~Shape()
{
	
}

void Shape::setName(const char* name)
{
	if(name == nullptr || strlen(name) >= SIZE){
		std::cout<<"name is illegal!"<<std::endl;
		return ;
	}
	
	memset(m_name,0,SIZE);
	strcpy(m_name,name);
}
char* Shape::getName()
{
	return m_name;
}

void Shape::setID(const int id)
{
	m_id = id;
}

int Shape::getID()const
{
	return m_id;
}

#endif //_SHAPE_H