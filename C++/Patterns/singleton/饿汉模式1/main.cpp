#include "singleton.h"

using namespace std;

int main()
{
	Singleton *single = Singleton::getInstance(5);
	single->display();
	single->setData(10);
	single->display();	
	Singleton::destroyInstance();
	
	return 0;
}