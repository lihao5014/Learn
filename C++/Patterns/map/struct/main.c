#include "math.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc,char* argv[])
{
	printf("argv[1] =%f, argv[2] =%c, argv[3] =%f\n",atof(argv[1]),strToChar(argv[2]),atof(argv[3]));
	
	if(argc != 4)
	{
		puts("input parameter is illegal");
		return 0;
	}

	initMath();
	calculate(atof(argv[1]),atof(argv[3]),strToChar(argv[2]));

	return 0;
}