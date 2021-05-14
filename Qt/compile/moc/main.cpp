#include "sample.h"

int main(void)
{
	Sample sample(5);
	sample.display();
	
	sample.setValue(10);
	sample.display();
	
	return 0;
}