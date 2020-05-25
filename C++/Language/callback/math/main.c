#include "math.h"

int main()
{
	int x = 4;
	int y = 5;
	
	calculate(x,y,add);
	calculate(x,y,sub);
	calculate(x,y,mult);
	calculate(x,y,divi);
	
	process(x,y,add);
	process(x,y,max);
	
	return 0;
}