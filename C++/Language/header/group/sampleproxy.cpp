#include "sampleapi.h"     //使用sample.h头文件包裹一下sample.h与sampleproxy.h头文件的目的是防止头文件包含顺序错误，而导致编译不通过bug
#include <assert.h>
#include <iostream>

SampleProxy::SampleProxy(Sample* psample)
	:psample(psample)
{
	
}

SampleProxy::~SampleProxy()
{
	if(psample != nullptr)
	{
		delete psample;
		psample = nullptr;
	}
	
	std::cout<<"SampleProxy destructor"<<std::endl;
}
	
void SampleProxy::setNum(const int num)
{
	if(psample != nullptr)
	{
		psample->setNum(num);
	}
}

int SampleProxy::getNum()const
{
	assert(psample != nullptr);
	return psample->getNum();
}

void SampleProxy::display()const
{
	if(psample != nullptr)
	{
		psample->display();
	}
}