#pragma message("compile bar.cpp")

#include "foo.h"
#include "bar.h"
#include <cstdio>

void bar(const char* str)
{
	if(str != nullptr)
	{
		printf("call foo()\n");
		foo(str);
		
		printf("bar(): %s\n",str);
	}
}