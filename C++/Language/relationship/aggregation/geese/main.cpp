#include <iostream>
#include "geese.h"
#include "feather.h"

using namespace std;

int main(int argc,char* argv[])
{
	Goose goose1("001");
	goose1.addFeather(new Feather("red"));
	
	Goose goose2("002");
	goose2.addFeather(new Feather("green"));
	goose2.addFeather(new Feather("green"));
	
	Goose goose3("003");
	goose3.addFeather(new Feather("blue"));
	goose3.addFeather(new Feather("blue"));
	goose3.addFeather(new Feather("blue"));
	
	Goose goose4("004");
	Feather* pfeather = new Feather("black");
	goose4.addFeather(pfeather);
	goose4.addFeather(new Feather("black"));
	goose4.addFeather(new Feather("black"));
	goose4.addFeather(new Feather("black"));

	goose4.show();
	cout<<endl;
	
	Geese geese("north","south");
	geese.addGoose(goose1);
	geese.addGoose(goose2);
	geese.addGoose(goose3);
	geese.addGoose(goose4);
	
	geese.display();
	cout<<endl;
	
	geese.removeGoose(goose2);
	geese.removeGoose(goose4);
	geese.display();
	cout<<endl;
	
	Goose goose5(goose2);
	goose5.show();
	
	goose5 = goose4;
	goose5.show();
	
	goose4.removeFeather(pfeather);     //goose4中移除了pfeather指针，那个Goose类的析构函数就不能释放
	goose4.show();
	
	if(pfeather != nullptr)
	{
		delete pfeather;
		pfeather = nullptr;
	}
	
	return 0;
}