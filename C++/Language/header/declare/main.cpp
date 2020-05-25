#include "sampleproxy.h"

int main()
{
	Sample *psample = new Sample(10);
	SampleProxy proxy(psample);
	
	proxy.setNum(20);
	proxy.display();
	
	return 0;
}