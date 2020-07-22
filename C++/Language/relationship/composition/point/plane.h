#ifndef _PLANE_H
#define _PLANE_H

#include "point.h"
#include <cstdlib>
#include <vector>
#include <iostream>

#define _CHANGE_WAY_
#undef _CHANGE_WAY_

using namespace std;

enum PlanePoint_t
{
	PLANE_POINT_A,
	PLANE_POINT_B,
	PLANE_POINT_C,
	PLANE_POINT_COUNT
};

class Plane
{
public:
	Plane();
	Plane(const Point& pointA,const Point& pointB,const Point& pointC);
	Plane(const Plane& other);
	
	void setPoint(const Point& point,int index);
	Point getPoint(int index)const;
	
	void setAllPoints(const Point arr[],int size);
	void setAllPoints(const vector<Point> &points);
	vector<Point> allPoints()const;
	
	void show()const;
private:
	vector<Point> points;
};

#ifndef _CHANGE_WAY_
Plane::Plane()
	:points(PLANE_POINT_COUNT,Point(0,0))
{
	points[PLANE_POINT_B] = Point(0,1);
	points.at(PLANE_POINT_C) = Point(1,0);
}
#else
Plane::Plane()
{
	points.push_back(Point(0,0));
	points.push_back(Point(0,1));
	points.push_back(Point(1,0));
}	
#endif

Plane::Plane(const Point& pointA,const Point& pointB,const Point& pointC)
	:points{pointA,pointB,pointC}
{
	
}

Plane::Plane(const Plane& other)
	:points(other.points)
{
	
}

void Plane::setPoint(const Point& point,int index)
{
	if(index < 0 || index > PLANE_POINT_COUNT)
	{
		cout<<"setPoint warn: index is't illegal"<<endl;
		return ;
	}
	
	points[index] = point;
}

Point Plane::getPoint(int index)const
{
	if(index <0 || index > PLANE_POINT_COUNT)
	{
		cout<<"setPoint warn: index is't illegal"<<endl;
		exit(-1);
	}
	
	return points.at(index);
}

void Plane::setAllPoints(const Point arr[],int size)
{
	if(size != PLANE_POINT_COUNT)
	{
		cout<<"setAllPoints error: plane just has three point"<<endl;
		return ;
	}
	
	vector<Point> tempPoints(arr,arr + size);
	points = tempPoints;
}

void Plane::setAllPoints(const vector<Point> &points)
{
	if(points.size() != PLANE_POINT_COUNT)
	{
		cout<<"setAllPoints error: plane just has three point"<<endl;
		return ;
	}
	
	this->points = points;
}

vector<Point> Plane::allPoints()const
{
	return points;
}

void Plane::show()const
{
	cout<<"A"<<points[PLANE_POINT_A]
		<<" , B"<<points[PLANE_POINT_B]
		<<" , C"<<points[PLANE_POINT_C]<<endl;
}

#endif //_PLANE_H