#ifndef _CONCRETE_DECORATOR_H
#define _CONCRETE_DECORATOR_H

#include "decorator.h"
#include <iostream>

class ConcreteDecoratorA:public Decorator
{
public:
	ConcreteDecoratorA(Component* component):Decorator(component){}
	void operation()final
	{
		addBehavior();
		Decorator::operation();
	}
private:
	void addBehavior()
	{
		std::cout<<"this is added behavior A"<<std::endl;
	}
};

class ConcreteDecoratorB:public Decorator
{
public:
	ConcreteDecoratorB(Component* component):Decorator(component){}
	void operation()final
	{
		addOperation();
		Decorator::operation();
	}
private:
	void addOperation()
	{
		std::cout<<"this is added operation B"<<std::endl;
	}
};

#endif //_CONCRETE_DECORATOR_H