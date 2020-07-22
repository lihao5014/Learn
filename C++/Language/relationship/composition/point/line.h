#ifndef _LINE_H
#define _LINE_H

#include "point.h"
#include <list>
#include <iostream>
#include <stdlib.h>

#define CHANGE_WAY
#undef CHANGE_WAY

using std::list;
using std::cout;
using std::endl;

//匿名枚举，相当于一个定义了三个宏
enum
{
	LINE_POINT_START,
	LINE_POINT_END,
	LINE_POINT_COUNT
};

class Line
{
public:
	Line();
	Line(const Point& start,const Point& end);
	Line(const Line& other);
	
	void setPoint(const Point& point,int index);
	Point getPoint(int index)const;
	
	void display()const;
private:
	list<Point> points;
};

#ifndef CHANGE_WAY
Line::Line()
	:points(LINE_POINT_COUNT,Point(0,0))
{
	list<Point>::reverse_iterator iter = points.rbegin();
	*iter = Point(0,1);
}
#else
Line::Line()
{
	points.push_back(Point(0,0));
	points.push_back(Point(0,1));
}
#endif

Line::Line(const Point& start,const Point& end)
	:points{start,end}
{
	
}

Line::Line(const Line& other)
	:points(other.points)
{
	
}

void Line::setPoint(const Point& point,int index)
{
	if(index < 0 || index > LINE_POINT_COUNT)
	{
		cout<<"setPoint error: index is out of range"<<endl;
		return ;
	}
	
	list<Point>::iterator iter = points.begin();
	while(iter != points.end())
	{
		if(0 == index--)
		{
			break;
		}
		iter++;
	}
	
	*iter = point;
}

Point Line::getPoint(int index)const
{
	if(index < 0 || index > LINE_POINT_COUNT)
	{
		cout<<"getPoint error: index is illegal"<<endl;
		abort();
	}
	
	for(const auto& point: points)
	{
		if(0 == index--)
		{
			return point;
		}
	}
	return Point(0,0);
}

void Line::display()const
{
	cout<<"start"<<points.front()<<" , end"<<points.back()<<endl;
}	

#endif //_LINE_H