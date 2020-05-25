#include <iostream>

using namespace std;

const double PI = 3.14;

class Shape
{
public:
	Shape(int x,int y=0){Shape::x=x;Shape::y=y;}
	virtual ~Shape(){}
#if 0
	virtual double area()const{return 0;}
	virtual void display()const{cout<<"这个类没有面积："<<endl;}
#else
	virtual double area()const = 0;
	virtual void display()const = 0;	
#endif
protected:	
	int x,y;
};

class Triangle:public Shape
{
public:
	Triangle(int x,int y):Shape(x,y){}
	virtual ~Triangle(){}
	double area()const{return x*y*0.5;}
	void display()const{cout<<"x="<<x<<" ,y="<<y<<" :area="<<area()<<endl;}
};

class Rectangle:public Shape
{
public:
	Rectangle(int x,int y):Shape(x,y){}
	virtual ~Rectangle(){}
	double area()const{return x*y;}
	void display()const{cout<<"x="<<x<<" ,y="<<y<<" :area="<<area()<<endl;}
};

class Circle:public Shape
{
public:
	Circle(int x):Shape(x){}
	virtual ~Circle(){}
	double area()const{return PI*x*x;}
	void display()const{cout<<"r="<<x<<" :area="<<area()<<endl;}
};

int main(int argc,char** argv)
{
	Shape *p;
	Triangle t(3,4);
	Rectangle r(3,4);
	Circle c(5);
	
	p = &t;
	p->display();
	
	p = &r;
	p->display();
	
	p = &c;
	p->display();
	
	return 0;
}