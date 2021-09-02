#include <iostream>

#define _CHANGE_WAY_
// #undef _CHANGE_WAY_

using namespace std;

class Empty{};      //空类的大小是1个字节

/*类中只要有虚函数，那么32位系统中就会增加4个字节大小的虚表指针，64位系统中会增加8个字节的虚表指针。
 *32位系统中指针大小位4个字节，64位系统中指针大小位8个字节。
 */
class Base
{
public:
#ifndef _CHANGE_WAY_
	~Base()
	{
		cout<<"Base destructor"<<endl;
	}
#else
	virtual ~Base()
	{
		cout<<"virtual Base destructor"<<endl;
	}
#endif
	
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
	~SubClass()
	{
		cout<<"SubClass destructor"<<endl;
	}
	
	
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
	cout<<"sizeof(Empty) ="<<sizeof(Empty)<<endl;
	cout<<"sizeof(Base) ="<<sizeof(Base)<<endl;
	
	{
		//Base父类指针q，指向子类SubClass
		Base *q = new SubClass;    //如果Base父类中没有虚析构函数，那么delete父类指针时，只调用父类的析构函数。
		delete q;                  //如果Base父类中有虚析构函数，那么delete父类指针时，就会动态调用到子类和父类的析构函数。
	}
	
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