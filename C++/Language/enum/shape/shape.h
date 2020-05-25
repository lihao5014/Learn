#ifndef _SHAPE_H
#define _SHAPE_H

#include <iostream>

typedef enum Shape_t
{
	SQUARE,
	RECTANGLE,
	TRIANGLE,
	CIRCLE,
	ELLIPSE,
	SHAPE_COUNT         //记录形状的种类
}Shape_t;

class Shape
{
public:
	virtual ~Shape(){}
	virtual void draw() = 0;
};

class Square:public Shape
{
public:
	void draw()
	{
		std::cout<<"draw Square"<<std::endl;
	}
};

class Rectangle:public Shape
{
public:
	virtual void draw()
	{
		std::cout<<"draw rectangle"<<std::endl;
	}
};

class Triangle:public Shape
{
public:
	void draw()override
	{
		std::cout<<"draw triangle"<<std::endl;
	}
};

class Circle:public Shape
{
public:
	void draw()final
	{
		std::cout<<"draw Circle"<<std::endl;
	}
};

class Ellipse:public Shape
{
public:
	virtual void draw()override
	{
		std::cout<<"draw Ellipse"<<std::endl;
	}
};

#endif //_SHAPE_H