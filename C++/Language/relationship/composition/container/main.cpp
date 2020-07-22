#include "container.h"
#include "subassembly.h"

int main()
{
	Container container(10,007,"part");
	container.display();
	
	container.setSize(20);
	container.display();
	
	{
		Subassembly subassembly(50.567,123456,"unit");
		subassembly.print();	
	}
	
	Component component(8751,"element");
	Subassembly subassembly(48.45,component);
	subassembly.print();
	
	return 0;
}