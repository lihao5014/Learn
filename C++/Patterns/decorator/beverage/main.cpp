#include "coffee.h"
#include "concrete_condiment.h"

int main()
{
	IBeverage* coffee = new HouseBlend();
	Condiment* cream = new Cream(coffee);
	coffee->display();
	cream->display();
	if(cream != nullptr)
	{
		delete cream;
		cream = nullptr;
	}
	
	Condiment* mocha = new Mocha(coffee);
	coffee->display();
	mocha->display();
	if(mocha != nullptr)
	{
		delete mocha;
		mocha = nullptr;
	}
	
	if(coffee != nullptr)
	{
		delete coffee;
		coffee = nullptr;
	}
	
	HouseBlend coffee1;
	Cream cream1(&coffee1);
	coffee1.display();
	cream1.display();

	return 0;
}