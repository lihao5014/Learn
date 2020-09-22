#include <iostream>
#include "feather.h"

Feather::Feather(const std::string& color)
	:color(color)
{
	
}

Feather::Feather(const Feather& other)
	:color(other.color)
{
	
}

Feather& Feather::operator =(const Feather& other)
{
	color = other.color;
	return *this;
}

bool Feather::operator ==(const Feather& other)
{
	return color == other.color;
}

bool Feather::operator !=(const Feather& other)
{
	return !(*this == other);
}
	
void Feather::setColor(const std::string& color)
{
	this->color = color;
}

std::string Feather::getColor()const
{
	return color;
}

void Feather::print()const
{
	std::cout<<"feather color is: "<<color<<std::endl;
}