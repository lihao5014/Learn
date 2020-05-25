#ifndef _RECTANGLE_H
#define _RECTANGLE_H

#include "shape.h"
#include <iostream>

class Rectangle:public Shape
{
public:
	void draw()override
	{
		std::cout<<"Inside Rectangle::draw() method."<<std::endl;
	}
};

#endif //_RECTANGLE_H