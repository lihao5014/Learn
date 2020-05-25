#ifndef _CIRCLE_H
#define _CIRCLE_H

#include "shape.h"
#include <iostream>

class Circle:public Shape
{
public:
	Circle():r(0),x(0),y(0)
	{
		color = BLACK;
	}
		
	Circle(Color_t color,int r = 0,int x = 0,int y = 0)
		:r(r),x(x),y(y)
	{
		this->color = color;
	}
	
	void setColor(const Color_t color)
	{
		this->color = color;
	}
	
	Color_t getColor()const
	{
		return color;
	}
	
	void setR(const int r)
	{
		this->r = r;
	}
	
	int getR()const
	{
		return r;
	}

	void setX(const int x)
	{
		this->x = x;
	}
	
	int getX()const
	{
		return x;
	}

	void setY(const int y)
	{
		this->y = y;
	}
	
	int getY()const
	{
		return y;
	}
	
	virtual void draw()
	{
		std::cout<<"Circle :color ="<<color<<" , r ="<<r<<" , x="
			<<x<<" ,y ="<<y<<std::endl;
	}	
private:
	int r;
	int x;
	int y;
};


#endif //_CIRCLE_H