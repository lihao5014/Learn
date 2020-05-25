#include "point.h"

int main(int argc,char *argv[])
{
	Point point(3,4,5);
	
	point.showPoint();
	point.set_x(7);
	point.setz(8);
	std::cout<<point<<" ,x ="<<point.get_x()<<" ,z ="<<point.getz()<<std::endl;
	
	return 0;
}