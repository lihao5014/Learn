#include <iostream>

using namespace std;

class A
{
public:
	A(int i){a = i;cout<<"A costructor"<<endl;}
	~A(){cout<<"A destructor"<<endl;}
	void display()const{cout<<"a="<<a<<endl;}
private:
	int a;
};

class B:virtual public A
{
public:
	B(int i):A(i+1){b = i;cout<<"B costructor"<<endl;}
	~B(){cout<<"B destructor"<<endl;}
	void display()const{cout<<"b="<<b<<endl;}
private:
	int b;
};

class C:virtual public A
{
public:
	C(int i):A(i-1){c = i;cout<<"C costructor"<<endl;}
	~C(){cout<<"C destructor"<<endl;}
	void display()const{cout<<"c="<<c<<endl;}
private:
	int c;
};

//虚基类的构造函数在非虚基类之前调用
class D:public B,/*virtual*/ public C
{
public:
	D(int i):B(i+2),C(i-2),A(i){d = i;cout<<"D costructor"<<endl;}
	~D(){cout<<"D destructor"<<endl;}
	void display()const{A::display();B::display();C::display();cout<<"d="<<d<<endl;}
private:
	int d;
};

int main()
{
	D obj(10);
	obj.display();
	
	return 0;
}