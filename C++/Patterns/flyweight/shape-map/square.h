#ifndef _SQUARE_H
#define _SQUARE_H

#include "shape.h"
#include <iostream>

class Square:public Shape
{
public:
	Square():w(0),x(0),y(0)
	{
		color = BLACK;
	}
		
	Square(Color_t color,int w=0,int x=0,int y=0)
		:w(w),x(x),y(y)
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
	
	void draw()final
	{
		std::cout<<"Square :color ="<<color<<" , w ="<<w<<" ,x ="
			<<x<<" ,y ="<<y<<std::endl;
	}	
private:
	int w;
	int x;
	int y;
};

#endif //_SQUARE_H