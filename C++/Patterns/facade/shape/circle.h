#ifndef _CIRCLE_H
#define _CIRCLE_H

#include "shape.h"
#include <iostream>

class Circle final:public Shape
{
public:
	void draw()final
	{
		std::cout<<"Circle :draw()"<<std::endl;
	}	
};


#endif //_CIRCLE_H