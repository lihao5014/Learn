#include "sample.h"            //必须包含ample.h头文件，且包含的顺序为在sampleproxy.h头文件以前。
                               //否则会因缺少Sample类型而导致main.cpp编译不通过
#include "sampleproxy.h"

int main()
{
	Sample *psample = new Sample(10);
	SampleProxy proxy(psample);
	
	proxy.setNum(20);
	proxy.display();
	
	return 0;
}