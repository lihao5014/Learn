#include <iostream>

using namespace std;

class Base
{
public:
	Base():data(0)
	{
		cout<<"Base()"<<endl;
	}
	
	Base(int date):data(data)
	{
		cout<<"Base(int)"<<endl;
	}
	
	Base(const Base& base)
	{
		cout<<"Base(const Base&)"<<endl;
		data = base.data;
	}
	
	Base(Base& base)
	{
		cout<<"Base(Base&)"<<endl;
		data = base.data;		
	}
	
	virtual void show()
	{
		cout<<"data ="<<data<<endl;
	}
private:
	int data;
};

class Demo:public Base
{
public:
	Demo():Base(0)
	{
		value = 0;
	}
	
	Demo(int data):Base(data)
	{
		value = 0;
	}
	
	Demo(int data,int value):Base(data),value(value)
	{
		cout<<"Demo(int,int)"<<endl;
	}

	Demo(const Demo& demo):Base(demo)
	{
		cout<<"Demo(const Demo&)"<<endl;
		value = demo.value;
	}

	Demo(Demo& demo):Base(demo)
	{
		cout<<"Demo(Demo&)"<<endl;
		value = demo.value;		
	}
	
	virtual void show()
	{
		Base::show();
		cout<<"value ="<<value<<endl;
	}
private:
	int value;
};

int main()
{
	Demo demo(4,5);
	Demo demo1(demo);
	demo1.show();
	
	return 0;
}