#include <iostream>

using namespace std;

enum Color_t{RED,GREEN,BLUE};

int main()
{
#if 0
	enum Color_t color;
#else
	Color_t color;
#endif
	color = RED;
	cout<<"color ="<<color<<endl;
	
	color = GREEN;
	cout<<"color ="<<color<<endl;	
	
	switch(color){
	case RED:
		cout<<"red"<<endl;
		break;
	case GREEN:
		cout<<"green"<<endl;
		break;
	case BLUE:
		cout<<"blue"<<endl;
		break;
	default:
		cout<<"default"<<endl;
	}
	
	return 0;
}