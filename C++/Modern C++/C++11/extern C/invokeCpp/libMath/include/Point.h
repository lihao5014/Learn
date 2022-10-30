#ifndef _POINT_H_
#define _POINT_H_

// #include "libMath_global.h"

class /*LIB_MATH_EXPORT*/ Point
{
public:
	Point();
	Point(double x,double y);
	Point(const Point& other);
	
	void setX(double x);
	double getX()const;
	
	void setY(double y);
	double getY()const;
	
	void display()const;
	
	Point operator +(const Point& point);
	Point operator -(const Point& point);
	
private:
	double m_x;
	double m_y;
};

#endif  //_POINT_H_