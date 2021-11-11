#pragma message("compile foo.cpp")

#include "foo.h"
#include <iostream>

void foo(const char* str)
{
	if(str == nullptr)
	{
		return ;
	}
	std::cout<<"foo(): "<<str<<std::endl;
}