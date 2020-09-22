#include <iostream>
#include "sample.h"

void Sample::setValue(const data_t value)
{
	this->value = value;
}

data_t Sample::getValue()const
{
	return value;
}

void Sample::show()const
{
	std::cout<<"value ="<<value<<std::endl;
}