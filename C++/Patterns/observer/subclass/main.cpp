#include "subclass.h"
#include <iostream>

int main()
{
	Sample sample(10);
	Base* base = new Subclass(&sample);
	sample.display();
	base->setValue(17);
	base->show();
	sample.display();
	
	return 0;
}