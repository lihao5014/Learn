#include "foobar.h"
#include <stdio.h>

int var = 5;
const double pi = 3.141596;

void foo()
{
	printf("call foo(): var =%d\n",var);
}

void bar()
{
	fprintf(stdout,"call bar(): pi =%f\n",pi);
}
