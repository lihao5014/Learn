#include "geese.h"
#include <iostream>

using namespace std;

int main(int argc,char* argv[])
{
	Goose goose1("001");
	Goose goose2("002");
	Goose goose3("003");
	Goose goose4("004");
	Goose goose5("005");
	
	goose5.show();
	cout<<endl;
	
	Geese geese("north","south");
	geese.addGoose(goose1);
	geese.addGoose(goose2);
	geese.addGoose(goose3);
	geese.addGoose(goose4);
	geese.addGoose(goose5);
	geese.display();
	cout<<endl;
	
	geese.removeGoose(goose2);
	geese.removeGoose(goose4);
	geese.display();
	cout<<endl;
	
	return 0;
}