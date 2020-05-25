#include <iostream>

using namespace std;

class Demo
{
public:
	Demo(int x,int y):x(x),y(y){}
	
	void show(){
		cout<<"x ="<<x<<" y ="<<y<<endl;
	}
	
	int y;
private:
	int x;
};

int main()
{
	Demo demo(4,8);
	
	int *p = reinterpret_cast<int*>(&demo);    //使用reinterpret——cast可以打破类的封装
	cout<<*p<<endl;
	
	int Demo::*q = &Demo::y;
	cout<<demo.*q<<endl;
	
	void (Demo::*fun)() = Demo::show;
	(demo.*fun)();
	
	return 0;
}