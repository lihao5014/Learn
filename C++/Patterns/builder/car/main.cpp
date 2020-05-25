#include "factory.h"

int main()
{
	Assemble* assemble = new AssembleCarA();
	Factory factoryA(assemble);
	factoryA.assembleCar();
	Car* car = factoryA.getCar();
	car->show();
	delete car;
	delete assemble;
	
	assemble = new AssembleCarB();
	Factory factoryB(assemble);
	factoryB.assembleCar();	
	car = factoryB.getCar();
	car->show();
	delete car;
	delete assemble;
	
	return 0;
}