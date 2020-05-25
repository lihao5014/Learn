#ifndef _RED_H
#define _RED_H

#include "color.h"
#include <iostream>

class Red:public Color
{
public:
	virtual void fill()
	{
		std::cout<<"Inside Red::fill() method."<<std::endl;
	}
};


#endif //_RED_H