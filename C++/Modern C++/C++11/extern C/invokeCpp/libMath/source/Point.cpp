#include "Point.h"
#include <iostream>

using namespace std;

Point::Point()
	:m_x(0)
	,m_y(0)
{
	
}

Point::Point(double x,double y)
	:m_x(x)
	,m_y(y)
{
	
}

Point::Point(const Point& other)
	:m_x(other.m_x)
	,m_y(other.m_y)
{
	
}

void Point::setX(double x)
{
	m_x = x;
}

double Point::getX()const
{
	return m_x;
}

void Point::setY(double y)
{
	m_y = y;
}

double Point::getY()const
{
	return m_y;
}

void Point::display()const
{
	cout<<"("<<m_x<<","<<m_y<<")"<<endl;
}

Point Point::operator +(const Point& point)
{
	return Point(m_x + point.m_x,m_y + point.m_y);
}

Point Point::operator -(const Point& point)
{
	return Point(m_x - point.m_x,m_y - point.m_y);
}