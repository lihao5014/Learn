#include "concrete_factory.h"

int main()
{
	Factory* factory = new BenzFactory();
	ICar* car = factory->createCar();
	car->show();
	std::cout<<car->getName()<<std::endl;
	factory->destroyCar(car);
	delete factory;
	
	factory = new BmwFactory();
	car = factory->createCar();
	car->show();
	std::cout<<car->getName()<<std::endl;
	factory->destroyCar(car);
	delete factory;
	
	return 0;
}