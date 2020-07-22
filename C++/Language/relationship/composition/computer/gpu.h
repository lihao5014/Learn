#ifndef _GPU_H
#define _GPU_H

#include <iostream>

class Gpu
{
public:
	Gpu(const double frequency);
	Gpu(const Gpu& other);
	
	void setFrequency(const double frequency);
	double getFrequency()const;
	
	void display()const;
private:
	double frequency;
};

Gpu::Gpu(const double frequency)
	:frequency(frequency)
{
	
}

Gpu::Gpu(const Gpu& other)
	:frequency(other.frequency)
{
	
}

void Gpu::setFrequency(const double frequency)
{
	this->frequency = frequency;
}

double Gpu::getFrequency()const
{
	return frequency;
}

void Gpu::display()const
{
	std::cout<<"gpu frequency is: "<<frequency<<"MHz"<<std::endl;
}

#endif //_GPU_H