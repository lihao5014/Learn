#ifndef _RECTANGLE_H
#define _RECTANGLE_H

#include "shape.h"

class Rectangle:public Shape
{
public:
	Rectangle(const double width,const double height);
	Rectangle(const Rectangle& other);
	
	void draw()const override;
private:
	double width;
	double height;
};

Rectangle::Rectangle(double width,double height)
	:Shape(2*width+2*height,width*height)
	,width(width)
	,height(height)
{
	
}

Rectangle::Rectangle(const Rectangle& other)
	:Shape(2*(other.width+other.height),other.width * other.height)
	,width(width)
	,height(height)
{
	
}

void Rectangle::draw()const
{
	cout<<"width ="<<width<<" ,height ="<<height<<endl;
	Shape::draw();
}

#endif //_RECTANGLE_H