#include "foo.h"
#include <stdio.h>

void foo(pFun pfun)
{
	puts("---foo start---");
	pfun();
	puts("---foo start---");
}