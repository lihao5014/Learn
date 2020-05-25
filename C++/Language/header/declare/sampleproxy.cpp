#include "sampleproxy.h"
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