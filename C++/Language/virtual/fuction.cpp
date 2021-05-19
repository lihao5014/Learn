#include <iostream>

using namespace std;

class Base
{
public:
	virtual void fun(int a)
	{
		cout<<"class Base: fun "<<a<<endl;
	}
	
	virtual void foo(int x)
	{
		cout<<"class Base: foo "<<x<<endl;
	}
};

class SubClass:public Base
{
public:
	void fun(int a)
	{
		cout<<"class SubClass: fun "<<a<<endl;
	}
	
	void foo(double x)
	{
		cout<<"class SubClass: foo "<<x<<endl;
	}
	
	void bar()
	{
		foo(2.71828);      //调用子类覆盖的foo()虚函数，即子类会优先调用自己实现的函数
		Base::foo(5);      //子类可以通过::作用域符访问到父类中被覆盖了的foo()虚函数
		cout<<"class SubClass: bar"<<endl;
	}
};

int main()
{
	Base a,*p = &a;
	SubClass b;
	
	(*p).fun(1);
	p->foo(1);
	
	p = &b;
	(*p).fun(2);
	p->foo(2);
	p->foo(3.1415);
	
	b.Base::foo(1.414);   //子类对象可以通过::作用域符访问父类中任意public函数，包括被覆盖了的虚函数
	b.foo(3.1415);
	b.bar();
}