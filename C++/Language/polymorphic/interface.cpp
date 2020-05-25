#include <iostream>
#include <cmath>

using namespace std;

struct Base
{
	virtual void setData(const int x,const int y=0)=0;
	virtual void display()const = 0;
};

class Square:public Base
{
public:
	void setData(const int x,const int y=0)
	{
		this->x=x;
	}

	virtual void display()const
	{
		cout<<"x="<<x<<" : ";
		cout<<"x square="<<x*x<<endl;
	}
private:
	int x;
};

class Cube:public Base
{
public:
	void setData(const int x,const int y=0)
	{
		this->x=x;
	}
	
	virtual void display()const
	{
		cout<<"x="<<x<<" : ";
		cout<<"x cube="<<x*x*x<<endl;
	}
private:
	int x;
};

class Chpow:public Base
{
public:
	void setData(const int x,const int y=0)
	{
		this->x=x;
		this->y=y;
	}
	
	virtual void display()const
	{
		cout<<"x="<<x<<" ,y="<<y<<" : ";
		cout<<"pow(x,y)="<<pow(double(x),double(y))<<endl;
	}
private:
	int x,y;
};

void show(Base* p)
{
	p->display();			//display为虚函数，所以可以实现动态联编
}

int main(int argc,char* argv[])
{
	Square square;
	square.setData(2);
	square.display();
	show(&square);
	
	Cube cube;
	cube.setData(3);
	cube.display();
	show(&cube);
	
	Chpow chpow;
	chpow.setData(3,2);
	chpow.display();
	show(&chpow);
	
	return 0;
}