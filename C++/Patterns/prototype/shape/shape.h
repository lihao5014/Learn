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
	void setArea(const int area);
	int getArea()const;
	virtual Shape* clone() = 0;
	virtual void draw() = 0;
protected:
	char m_name[SIZE];
	int m_area;
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

void Shape::setArea(const int area)
{
	m_area = area;
}

int Shape::getArea()const
{
	return m_area;
}

#endif //_SHAPE_H