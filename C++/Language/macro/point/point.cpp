#include "point.h"

Point::Point(data_t x,data_t y,data_t z)
	:x(x),y(y),z(z)
{
		
}

Point::Point(const Point& other)
	:x(other.x)
	,y(other.y)
	,z(other.z)
{
	
}

Point::~Point()
{
	std::cout<<"Point destructor"<<std::endl;
}
	
void Point::showPoint()const
{
	std::cout<<"("<<x<<","<<y<<","<<z<<")"<<std::endl;
}

std::ostream& operator <<(std::ostream& os,const Point& point)
{
	os<<"("<<point.x<<","<<point.y<<","<<point.z<<")";
	return os;
}
