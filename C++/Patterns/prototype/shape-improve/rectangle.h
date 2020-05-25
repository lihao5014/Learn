#ifndef _RECTANGLE_H
#define _RECTANGLE_H

#include "shape.h"

class Rectangle:public Shape
{
public:
	Rectangle(const char* name,const int id)
	{
		if(name == nullptr || strlen(name) >= SIZE){
			throw "name is illegal!";
		}
		
		memset(m_name,0,SIZE);
		strcpy(m_name,name);
		m_id = id;
	}
	
	Rectangle(const Rectangle& rectangle)
	{
		memset(m_name,0,SIZE);
		strcpy(m_name,rectangle.m_name);
		m_id = rectangle.m_id;
	}
	
	virtual Shape* clone()override
	{
		return new Rectangle(*this);
	}
	
	virtual void draw()final
	{
		std::cout<<"this is rectangle"<<std::endl;
	}
};

#endif //_RECTANGLE_H