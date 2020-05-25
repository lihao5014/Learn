#include "sampleapi.h"    //使用sample.h头文件包裹一下sample.h与sampleproxy.h头文件的目的是防止头文件包含顺序错误，而导致编译不通过bug

int main()
{
	Sample *psample = new Sample(10);
	SampleProxy proxy(psample);
	
	proxy.setNum(20);
	proxy.display();
	
	return 0;
}