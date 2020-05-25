#ifndef _DECORATOR_H
#define _DECORATOR_H

#include "component.h"
#include <iostream>

class Decorator:public Component
{
public:
	Decorator(Component* component):component(component){}
	void operation()override
	{
		if(component != nullptr)
			component->operation();
	}
private:
	Component* component;
};

#endif //_DECORATOR_H