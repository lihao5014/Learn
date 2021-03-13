#include "point.h"

#define UNUSED(x) (void)x

int main(int argc,char* argv[])
{
	UNUSED(argc);
	UNUSED(argv);
	
	Point point(3,4,5);
	point.display();
	
	return 0;
}