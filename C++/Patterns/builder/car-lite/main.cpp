#include "assemble.h"

int main()
{
	Assemble* assemble = new AssembleCarA();
	assemble->assembleCar();
	Car* car = assemble->getCar();
	car->show();
	delete car;
	delete assemble;
	
	assemble = new AssembleCarB();
	assemble->assembleCar();
	car = assemble->getCar();
	car->show();
	delete car;
	delete assemble;
	
	return 0;
}