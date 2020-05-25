#ifndef _RECTANGLE_H
#define _RECTANGLE_H

#include "shape.h"
#include <iostream>

class Rectangle:public Shape
{
	virtual void draw()override
	{
		std::cout<<"draw: Rectangle"<<std::endl;
	}
};

#endif //_RECTANGLE_H