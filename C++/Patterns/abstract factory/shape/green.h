#ifndef _GREEN_H
#define _GREEN_H

#include "color.h"
#include <iostream>

class Green:public Color
{
public:
	virtual void fill()override
	{
		std::cout<<"Inside Green::fill() method."<<std::endl;
	}	
};

#endif //_GREEN_H