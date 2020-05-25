#include "processor.h"
#include "factory.h"

int main()
{
	Factory* factory = new SingleCoreFactory();
	Processor* core = factory->createProcessor();
	core->show();
	factory->destroyProcessor(&core);
	delete factory;
	
	factory = new MultiCoreFactory();
	core = factory->createProcessor();
	core->show();
	factory->destroyProcessor(&core);
	delete factory;
	
	return 0;
}