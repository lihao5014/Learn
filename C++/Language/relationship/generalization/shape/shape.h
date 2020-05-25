#ifndef _SHAPE_H
#define _SHAPE_H

#include <iostream>

#define EPS 0.000001

using std::cout;
using std::endl;

class Shape
{
public:
	Shape(double perimeter,double area);
	Shape(const Shape& other);
	virtual ~Shape();
	
	virtual void draw()const;
protected:
	double perimeter;
	double area;
};

Shape::Shape(double perimeter,double area)
	:perimeter(perimeter)
	,area(area)
{
	
}

Shape::Shape(const Shape& other)
	:perimeter(other.perimeter)
	,area(other.area)
{
	
}

Shape::~Shape()
{
	
}

void Shape::draw()const
{
	cout<<"perimeter ="<<perimeter<<" ,area ="<<area<<endl;
}

#endif //_SHAPE_H