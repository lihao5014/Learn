#include "container.h"

int main()
{
	Container container(10,007,"part");
	container.display();
	
	container.setSize(20);
	container.display();
	
	return 0;
}