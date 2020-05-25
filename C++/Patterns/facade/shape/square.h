#ifndef _SQUARE_H
#define _SQUARE_H

#include "shape.h"
#include "shape.h"

class Square final:public Shape
{
public:
	void draw()override
	{
		std::cout<<"Square  :draw()"<<std::endl;
	}	
};

#endif //_SQUARE_H