#ifndef _CUBE_H
#define _CUBE_H

#include "point.h"
#include <array>
#include <iostream>
#include <stdlib.h>

using std::array;
using std::cout;
using std::endl;

typedef enum
{
	CUBE_POINT_A,
	CUBE_POINT_B,
	CUBE_POINT_C,
	CUBE_POINT_D,
	CUBE_POINT_COUNT
}CubePoint_t;

class Cube
{
public:
	Cube();
	Cube(const Point& pntA,const Point& pntB,const Point& pntC,const Point& pntD);
	Cube(const Cube& other);
	
	void setPoint(const Point& point,int index);
	Point getPoint(int index)const;
	
	void setAllPoints(const array<Point,CUBE_POINT_COUNT> &points);
	array<Point,CUBE_POINT_COUNT> allPoints()const;
	
	void detail()const;
private:
	array<Point,CUBE_POINT_COUNT> points;
};

Cube::Cube()
	:points{Point(0,0,0),Point(0,0,1),Point(0,1,0),Point(1,0,0)}
{
	
}

Cube::Cube(const Point& pntA,const Point& pntB,const Point& pntC,const Point& pntD)
	:points{pntA,pntB,pntC,pntD}
{
	
}

Cube::Cube(const Cube& other)
	:points(other.points)                //array数组的默认拷贝构造是浅拷贝
{
	
}

void Cube::setPoint(const Point& point,int index)
{
	if(index <0 || index > CUBE_POINT_COUNT)
	{
		cout<<"setPoint warn: index is't illegal"<<endl;
		return ;
	}
	
	points[index] = point;
}

Point Cube::getPoint(int index)const
{
	if(index <0 || index > CUBE_POINT_COUNT)
	{
		cout<<"getPoint warn: index is't illegal"<<endl;
		exit(-1);
	}
	
	return points.at(index);
}

void Cube::setAllPoints(const array<Point,CUBE_POINT_COUNT> &points)
{
	this->points = points;
}

array<Point,CUBE_POINT_COUNT> Cube::allPoints()const
{
	return points;
}

void Cube::detail()const
{
	for(int i=0;i<CUBE_POINT_COUNT;++i)
	{
		cout<<points[i]<<" ";
	}
	cout<<endl;
}

#endif //_CUBE_H