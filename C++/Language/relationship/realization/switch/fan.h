#ifndef _FAN_H
#define _FAN_H

#include "turn.h"
#include <iostream>

class Fan:public Turn
{
public:
	virtual ~Fan()
	{
		std::cout<<"Fan destruction"<<std::endl;
	}

	void turnUp()override
	{
		std::cout<<"Fan turnUp()"<<std::endl;
	}
	
	void turnDown()final
	{
		std::cout<<"Fan turnDown()"<<std::endl;
	}
	
	void display()
	{
		std::cout<<"this is Fan class"<<std::endl;
	}
};

#endif //_FAN_H