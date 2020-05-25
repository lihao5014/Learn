#include <iostream>

using namespace std;

class Sample
{
public:
	Sample(){x = 0;y = 0;}
	Sample(int x,int y){this->x = x;this->y = y;}
	Sample(int x,int y,int z){this->x = x;this->y = y ;this->z = z;}
	Sample(/*const*/ Sample &s);
	~Sample();
	
	void setX(int x);
	int getX()/*const*/;
	
	void setY(int y);
	int getY()const;
	
	void setZ(int z);
	int getZ()const;
	
	Sample copy();
	
	static void display(const Sample &s);
	
	int y;
	static int z;
private:
	int x;
};

int Sample::z = 0;		 //static成员是类公有的，可以通过类名和对象名调用。

Sample::Sample(/*const*/ Sample &s)        //const对象只能调用const修饰的函数
{
	x = s.x;					//成员函数中可以直接访问对象的私有成员
	y = s.getY();
}

Sample::~Sample()
{
	cout << "Sample destroy"<<endl;
}

void Sample::setX(int x)
{
	this->x = x;
}

int Sample::getX()/*const*/
{
	return x;
}

void Sample::setY(int y)
{
	this->y = y;
}

int Sample::getY()const
{
	return y;
}

void Sample::setZ(int z)
{
	Sample::z = z;
}

int Sample::getZ()const
{
	return z;
}

void Sample::display(const Sample &s)
{
	cout << "x ="<<s.x<<" ,y="<<s.y<<" ,z="<<z<<endl;     //static成员函数只能直接访问static成员
}

Sample Sample::copy()
{
	return *this;
}

int main(int argc,char** argv)
{
	int Sample::*p = NULL;
	void (Sample::*pFun)(int);
	
	Sample s(5,7,9);
	s.display(s);
	
	p = &Sample::y;
	s.*p = 10;
	s.display(s);
	
	int *q = &Sample::z;
	*q = 20;
	s.display(s);	
	
	pFun = Sample::setX;
	(s.*pFun)(11);
	s.display(s);
	
	pFun = Sample::setY;
	(s.*pFun)(12);
	s.display(s);
	
	Sample t(14,17);
	t.display(t);
	t = s.copy();
	t.display(t);
	
	return 0;
}