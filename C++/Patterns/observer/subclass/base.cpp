#include "base.h"
#include "sample.h"
#include <iostream>

Base::Base(int value)
	:value(value)
{
	this->sample = nullptr;
}

Base::Base(Sample* sample,int value)
	:sample(sample),value(value)
{
	if(sample != nullptr)
		sample->setBase(this);
}

void Base::setSample(Sample* sample)
{
	this->sample = sample;
}

Sample* Base::getSample()
{
	return sample;
}

void Base::setValue(const int value)
{
	this->value = value;
}

int Base::getValue()const
{
	return value;
}

void Base::show()const
{
	std::cout<<"Base : value ="<<value<<std::endl;
}