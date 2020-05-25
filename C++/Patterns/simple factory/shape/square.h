#ifndef _SQUARE_H
#define _SQUARE_H

#include "shape.h"
#include <iostream>

class Square:public Shape
{
public:
	virtual void draw()
	{
		std::cout<<"Inside Square::draw() method."<<std::endl;
	}
};

#endif //_SQUARE_H