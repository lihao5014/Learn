#ifndef _POINT_H
#define _POINT_H

#include <iostream>

class Point
{
public:
	Point();
	Point(double x,double y,double z=0);
	Point(const Point& other);
	
	void setX(const double x);
	double getX()const;
	
	void setY(const double y);
	double getY()const;
	
	void setZ(const double z);
	double getZ()const;
	
	void print()const;
	friend std::istream& operator >>(std::istream& in,Point& point);
	friend std::ostream& operator <<(std::ostream& out,const Point& point);
private:
	double x;
	double y;
	double z;
};

Point::Point()
	:x(0),y(0),z(0)
{
	
}

Point::Point(double x,double y,double z)
	:x(x),y(y),z(0)
{
	
}

Point::Point(const Point& other)
	:x(other.x),y(other.y),z(other.z)
{
	
}

void Point::setX(const double x)
{
	this->x = x;
}

double Point::getX()const
{
	return x;
}

void Point::setY(const double y)
{
	this->y = y;
}

double Point::getY()const
{
	return y;
}

void Point::setZ(const double z)
{
	this->z = z;
}

double Point::getZ()const
{
	return z;
}

void Point::print()const
{
	std::cout<<"("<<x<<","<<y<<","<<z<<")"<<std::endl;
}

std::istream& operator >>(std::istream& in,Point& point)
{
	in>>point.x>>point.y>>point.z;
	return in;
}

std::ostream& operator <<(std::ostream& out,const Point& point)
{
	out<<"("<<point.x<<","<<point.y<<","<<point.z<<")";
	return out;
}

#endif //_POINT_H