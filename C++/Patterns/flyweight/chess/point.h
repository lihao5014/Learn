#ifndef _POINT_H
#define _POINT_H

#include <iostream>

class Point
{
public:
	Point():x(0),y(0){}
	Point(int x,int y):x(x),y(y){}
	Point(const Point& point):x(point.x),y(point.y){}
	Point(Point& point):x(point.x),y(point.y){}
	
	void setX(const int x){this->x = x;}
	int getX()const{return x;}
	
	void setY(const int y){this->y = y;}
	int getY()const{return y;}
	
	void display()const
	{
		std::cout<<"("<<x<<","<<y<<")"<<std::endl;
	}
	
	Point operator =(const Point& point)
	{
		x = point.x;
		y = point.y;
		return *this;
	}
	
	bool operator <(const Point& point)const
	{
		if(x < point.x)
		{
			return true;
		}else if(x == point.x){
			return y < point.y;
		}
		return false;
	}
	
	bool operator >(const Point& point)const
	{
		if(x > point.x)
		{
			return true;
		}else if(x == point.x){
			return y > point.y;
		}
		return false;
	}
	
	bool operator ==(const Point& point)const
	{
		return (x == point.x && y == point.y) ? true : false;
	}
	
	friend std::ostream& operator <<(std::ostream& os,const Point& point)
	{
		os<<"("<<point.x<<","<<point.y<<")";
		return os;
	}
	
	friend std::istream& operator >>(std::istream& is,Point& point)
	{
		is>>point.x>>point.y;
		return is;
	}	
private:
	int x,y;
};

#endif //_POINT_H