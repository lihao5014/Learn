#ifndef _BLUE_H
#define _BLUE_H

#include "color.h"
#include <iostream>

class Blue:public Color
{
public:
	virtual void fill()final
	{
		std::cout<<"Inside Blue::fill() method."<<std::endl;
	}	
};

#endif //_BLUE_H