#ifndef _TRIANGLE_H
#define _TRIANGLE_H

#include "shape.h"
#include <cmath>

static double triangleArea(double a,double b,double c);

class Triangle:public Shape
{
public:
	Triangle(double a,double b,double c);
	Triangle(const Triangle& other);
	
	void draw()const final;
private:
	double a;
	double b;
	double c;
};

Triangle::Triangle(double a,double b,double c)
	:Shape(a+b+c,triangleArea(a,b,c))
	,a(a)
	,b(b)
	,c(c)
{
	
}

Triangle::Triangle(const Triangle& other)
	:Shape(other.a+other.b+other.c,triangleArea(other.a,other.b,other.c))
	,a(other.a)
	,b(other.b)
	,c(other.c)
{
	
}

void Triangle::draw()const
{
	cout<<"a ="<<a<<" ,b ="<<b<<" ,c ="<<c<<endl;
	Shape::draw();
}

//已知三边求三角形面积的海伦公式
double triangleArea(double a,double b,double c)
{
	double p = (a+b+c)/2;
	return sqrt(p*(p-a)*(p-b)*(p-c));
}

#endif //_TRIANGLE_H