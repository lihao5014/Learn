#ifndef _RECTANGLE_H
#define _RECTANGLE_H

#include "shape.h"
#include <iostream>

class Rectangle:public Shape
{
public:
	Rectangle():w(0),h(0),x(0),y(0)
	{
		color = BLACK;
	}
		
	Rectangle(Color_t color,int w=0,int h=0,int x=0,int y=0)
		:w(w),h(h),x(x),y(y)
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

	void setW(const int w)
	{
		this->w = w;
	}
	
	int getW()const
	{
		return w;
	}
	
	void setH(const int h)
	{
		this->h = h;
	}
	
	int getH()const
	{
		return h;
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
	
	void draw()override
	{
		std::cout<<"Rectangle :color ="<<color<<" , w ="<<w<<" , h="
			<<h<<" ,x ="<<x<<" ,y ="<<y<<std::endl;
	}	
private:
	int w;
	int h;
	int x;
	int y;
};

#endif //_RECTANGLE_H