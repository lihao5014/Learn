#include "sample.h"
#include <iostream>

Sample::Sample(const int num):num(num)
{
	
}

Sample::Sample(const Sample& other)
	:num(other.num)
{
	
}

Sample::~Sample()
{
	std::cout<<"sample destructor"<<std::endl;
}
	
void Sample::setNum(const int num)
{
	Sample::num = num;
}

int Sample::getNum()const
{
	return num;
}

void Sample::display()const
{
	std::cout<<"num ="<<num<<std::endl;
}