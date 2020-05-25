#include "concrete_component.h"
#include "concrete_decorator.h"

#ifndef _FREE_PTR_
#define FREE_PTR(p)             \
    do{                         \
		if((p) != nullptr){     \
			delete (p);         \
			(p) = nullptr;      \
		}                       \
	}while(0)
#endif //_FREE_PTR_

int main()
{
	Component* component = new ConcreteComponent();
	Decorator* decorator = new ConcreteDecoratorA(component);
	component->operation();
	decorator->operation();
	FREE_PTR(decorator);
	
	decorator = new ConcreteDecoratorB(component);
	component->operation();
	decorator->operation();
	FREE_PTR(decorator);
	FREE_PTR(component);
	
	ConcreteComponent component1;
	{
		ConcreteDecoratorA decoratorA(&component1);
		component1.operation();
		decoratorA.operation();
	}
	ConcreteDecoratorB decoratorB(&component1);
	component1.operation();
	decoratorB.operation();	
	
	return 0;
}