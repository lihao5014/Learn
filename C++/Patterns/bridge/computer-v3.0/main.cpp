#include "system.h"
#include "computer.h"

int main()
{
	System* system = new Windows();
	Computer* computer = new DellComputer(system);
	computer->installOS();
	
	system = new Linux();
	computer->setSystem(system);
	computer->installOS();
	delete system;
	delete computer;
	
	return 0;
}