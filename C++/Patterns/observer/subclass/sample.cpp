#include "sample.h"
#include "base.h"
#include <iostream>

Sample::Sample(int data)
	:data(data)
{
	this->base = nullptr;
}


Sample::Sample(Base* base,int data)
	:base(base),data(data)
{
	if(base != nullptr)
		base->setSample(this);
}

void Sample::setBase(Base* base)
{
	this->base = base;
}

Base* Sample::getBase()
{
	return base;
}

void Sample::setData(const int data)
{
	this->data = data;
}

int Sample::getData()const
{
	return data;
}

void Sample::display()const
{
	if(base != nullptr)
		base->show();
	std::cout<<"Sample : data ="<<data<<std::endl;
}