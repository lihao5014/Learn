#ifndef _CIRCLE_H
#define _CIRCLE_H

#include "shape.h"
#include "drawAPI.h"
#include <iostream>

class Circle:public Shape
{
public:
	Circle(int r,int x,int y,DrawAPI* drawAPI)
		:r(r),x(x),y(y),Shape(drawAPI){}
	
	void display()const
	{
		std::cout<<"this is Circle :redius =r , ("<<x<<","<<y<<")"<<std::endl;
	}
		
	void draw()
	{
		if(drawAPI != nullptr)
			drawAPI->drawCircle(r,x,y);
	}
private:
	int r;
	int x,y;
};

#endif //_CIRCLE_H