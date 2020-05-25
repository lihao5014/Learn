#ifndef _CIRCLE_H
#define _CIRCLE_H

#include "shape.h"

#define PI 3.14159

class Circle:public Shape
{
public:
	Circle(const double radius);
	Circle(const Circle& other);
	
	virtual void draw()const;
private:
	double radius;
};

Circle::Circle(const double radius)
	:Shape(2*PI*radius,PI*radius*radius)
	,radius(radius)
{
	
}

Circle::Circle(const Circle& other)
	:Shape(other)
	,radius(other.radius)
{
	
}

void Circle::draw()const
{
	cout<<"radius ="<<radius<<endl;
	Shape::draw();
}

#endif //_CIRCLE_H