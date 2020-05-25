#include "director.h"

int main()
{
	AppleBuilder apple;
	Director director(&apple);
	director.createComputer();
	Computer* computer = director.getComputer();
	computer->show();
	
	DellBuilder dell;
	director.setBuilder(&dell);
	director.createComputer();
	computer = director.getComputer();
	computer->show();	
	
	delete computer;
	return 0;
}