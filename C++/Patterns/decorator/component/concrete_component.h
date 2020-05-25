#ifndef _CONCRETE_COMPONENT_H
#define _CONCRETE_COMPONENT_H

#include "component.h"
#include <iostream>

class ConcreteComponent final:public Component
{
public:
	void operation()final
	{
		std::cout<<"I am no decoratored ConcreteComponent"<<std::endl;
	}
};

#endif //_CONCRETE_COMPONENT_H