#include "concrete_factory.h"

int main()
{
	Factory* factory = new BenzFactory();
	Car* car = factory->createCar();
	Bike* bike = factory->createBike();
	car->show();
	bike->display();
	delete car;	
	delete bike;
	delete factory;
	
	factory = new BmwFactory();
	car = factory->createCar();
	bike = factory->createBike();
	car->show();
	bike->display();
	delete car;	
	delete bike;
	delete factory;
	
	factory = Factory::createFactory(Factory::AUDI_FACTORY);
	car = factory->createCar();
	bike = factory->createBike();
	car->show();
	bike->display();
	delete car;	
	delete bike;
	delete factory;
	
	return 0;
}