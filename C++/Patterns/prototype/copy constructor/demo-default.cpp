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
protected:
	int data;
};

class Demo:public Base
{
public:
	Demo()
	{
		cout<<"Demo(int,int)"<<endl;
		data = 0;
		value = 0;
	}
	
	Demo(int data)
	{
		cout<<"Demo(int)"<<endl;
		this->data = data;
		value = 0;
	}
	
	Demo(int data,int value):value(value)
	{
		cout<<"Demo(int,int)"<<endl;
		this->data = data;
	}

	Demo(const Demo& demo)
	{
		cout<<"Demo(const Demo&)"<<endl;
		data =demo.data;
		value = demo.value;
	}

	Demo(Demo& demo):value(demo.value)
	{
		cout<<"Demo(Demo&)"<<endl;
		data =demo.data;	
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