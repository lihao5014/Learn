#include <iostream>
#include <cmath>

using namespace std;

class Base
{
public:	
	virtual void setXY(int x,int y=0){this->x=x;this->y=y;}
	virtual void display()const = 0;
protected:
	int x,y;
};

class Square:public Base
{
public:
	virtual void display()const
	{
		cout<<"x="<<x<<" : ";
		cout<<"x square="<<x*x<<endl;
	}
};

class Cube:public Base
{
public:
	virtual void display()const
	{
		cout<<"x="<<x<<" : ";
		cout<<"x cube="<<x*x*x<<endl;
	}
};

class Chpow:public Base
{
public:
	virtual void display()const
	{
		cout<<"x="<<x<<" ,y="<<y<<" : ";
		cout<<"pow(x,y)="<<pow(double(x),double(y))<<endl;
	}	
};

int main(int argc,char* argv[])
{
	Base* p;
	
	Square square;
	square.setXY(2);
	square.display();
	
	p = &square;
	p->setXY(4);
	p->display();
	
	Cube cube;
	cube.setXY(3);
	cube.display();
	
	p = &cube;
	p->setXY(5);
	p->display();	
	
	Chpow chpow;
	chpow.setXY(3,2);
	chpow.display();
	
	p = &chpow;
	p->setXY(4,3);
	p->display();		
	
	return 0;
}