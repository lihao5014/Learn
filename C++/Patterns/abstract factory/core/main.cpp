#include "core_factory.h"

int main()
{
	CoreFactory* factory = new  CoreFactoryA();
	SingleCore* single_core = factory->createSingleCore();
	MultiCore* multi_core = factory->createMultiCore();
	single_core->show();
	multi_core->display();
	delete single_core;
	delete multi_core;
	delete factory;
	
	
	factory = new  CoreFactoryB();
	single_core = factory->createSingleCore();
	multi_core = factory->createMultiCore();
	single_core->show();
	multi_core->display();
	delete single_core;
	delete multi_core;
	delete factory;
	
	return 0;
}