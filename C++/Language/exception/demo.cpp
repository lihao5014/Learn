#include <iostream>

using namespace std;

class Expt
{
public:
	Expt(){cout<<"Expt constructor1"<<endl;};
	Expt(const Expt& e){*this = e;cout<<"Expt constructor2"<<endl;}
	~Expt(){cout<<"Expt destructor"<<endl;};
	void show(){cout<<"调用show成员函数"<<endl;}	
};

class Demo
{
public:
	Demo(){cout<<"Demo constructor1"<<endl;}
	Demo(int n){Demo::n = n;cout<<"Demo constructor2"<<endl;}
	~Demo(){cout<<"Demo destructor"<<endl;}
private:	
	int n;
};

void fun()
{
	Demo d1;
	Demo d2(10);
	
	cout<<"在函数fun中抛出Expt类异常"<<endl;
	throw Expt();
}

int main()
{
	cout<<"main start"<<endl;
	
	try{
		Demo d3;
		fun();		
	}catch(Expt e){
		e.show();		//在try语句中检查到抛出异常以后，其抛出异常点前面构造的对象都将被析构。
	}catch(...){
		cout<<"默认捕获异常"<<endl;
	}
	
	cout<<"main end"<<endl;
	
	return 0;
}