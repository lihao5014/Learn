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

class B
{
public:
	B(int i){b = i;cout<<"B costructor"<<endl;}
	~B(){cout<<"B destructor"<<endl;}
	void display()const{cout<<"b="<<b<<endl;}
private:
	int b;
};

class C:public B,public A
{
public:
	C(int i):A(i+2),B(i-2){c = i;cout<<"C costructor"<<endl;}
	~C(){cout<<"C destructor"<<endl;}
	void display()const{A::display();B::display();cout<<"c="<<c<<endl;}
private:
	int c;
};

int main()
{
	C obj(10);
	
	obj.display();
	
	return 0;
}