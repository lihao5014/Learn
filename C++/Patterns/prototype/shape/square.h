#ifndef _SQUARE_H
#define _SQUARE_H

#include "shape.h"

class Square:public Shape
{
public:
	Square(const char* name,const int area)
	{
		if(name == nullptr || strlen(name) >= SIZE){
			throw "name is illegal!";
		}
		
		memset(m_name,0,SIZE);
		strcpy(m_name,name);
		m_area = area;
	}
	
	Square(const Square& square)
	{
		memset(m_name,0,SIZE);
		strcpy(m_name,square.m_name);
		m_area = square.m_area;
	}
	
	Shape* clone()
	{
		return new Square(*this);
	}
	
	void draw()
	{
		std::cout<<"this is square"<<std::endl;
	}
};

#endif //_SQUARE_H