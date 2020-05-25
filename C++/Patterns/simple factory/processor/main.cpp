#include "processor.h"
#include "factory.h"

int main()
{
	Factory factory;
	Processor* core = factory.createProcessor(SINGLE);
	core->show();
	factory.destroyProcessor(&core);
	
	core = new MultiCore();
	core->show();
	factory.destroyProcessor(&core);
	
	return 0;
}