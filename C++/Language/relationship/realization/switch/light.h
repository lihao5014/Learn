#ifndef _LIGHT_H
#define _LIGHT_H

#include "turn.h"
#include <iostream>

class Light:public Turn
{
public:
	~Light()
	{
		std::cout<<"Light destruction"<<std::endl;
	}

	void turnUp()
	{
		std::cout<<"Light turnUp()"<<std::endl;
	}
	
	virtual void turnDown()
	{
		std::cout<<"Light turnDown()"<<std::endl;
	}
	
	void show()
	{
		std::cout<<"this is Light class"<<std::endl;
	}
};

#endif //_LIGHT_H