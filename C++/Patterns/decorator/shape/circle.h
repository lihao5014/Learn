#ifndef _CIRCLE_H
#define _CIRCLE_H

#include "shape.h"
#include <iostream>

class Circle:public Shape
{
public:
	void draw()
	{
		std::cout<<"draw: Circle"<<std::endl;
	}
};

#endif //_CIRCLE_H