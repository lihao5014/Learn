#include <iostream>
#include <cmath>

using namespace std;

#define PI 3.14

class IShape
{
public:	
	virtual void setValue(int x,int y=0){this->x=x;this->y=y;}
	virtual void display()const = 0;
protected:
	virtual double area()const = 0;
protected:
	int x,y;
};

class Rectangle:public IShape
{
public:
	virtual void display()const
	{
		cout<<"x="<<x<<" ,y="<<y<<" : ";
		cout<<"Rectangle area="<<area()<<endl;
	}
protected:
	double area()const
	{
		return x*y;
	}
};

class Circle:public IShape
{
public:
	virtual void display()const
	{
		cout<<"r="<<x<<" : ";
		cout<<"Circle arar="<<area()<<endl;
	}
protected:
	double area()const
	{
		return PI*x*x;
	}
};

int main(int argc,char* argv[])
{
	IShape *p[2];
	
	Rectangle rect;
	Circle circle;
	p[0] = &rect;
	p[1] = &circle;
	
	p[0]->setValue(2,3);
	p[0]->display();
	
	p[1]->setValue(4);
	p[1]->display();
	
	return 0;
}