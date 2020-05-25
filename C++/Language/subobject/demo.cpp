#include <iostream>

using namespace std;

class Sample
{
public:
	Sample(int n){this->n = n;}
	Sample(const Sample& Sample){this->n = Sample.n;}
	~Sample(){cout<<"sample destroy"<<endl;}
	void setN(const int n){this->n = n;}
	int getN()const{return n;}
	void display(){cout<<"n="<<n<<endl;}
private:
	int n;
};

class Demo
{
public:
	Demo():s(0),x(0),y(0){}
	Demo(int x,int y,int n):s(n){this->x = x;this->y = y;}
	Demo(const Demo &demo);
	~Demo();
	
	void setX(const int x);
	int getX()const;
	
	void setY(const int y);
	int getY()const;
	
	void setS(const Sample& s);
	Sample getS()const;
	
	void display();
	
	Demo& operator+(const Demo& demo);
	
	int y;
private:
	int x;
	Sample s;
};

Demo::Demo(const Demo &demo):s(demo.s)
{
	this->x = demo.x;
	this->y = demo.y;
}

Demo::~Demo()
{
	cout<<"demo destroy"<<endl;
}

void Demo::setX(const int x)
{
	this->x = x;
}

int Demo::getX()const
{
	return x;
}

void Demo::setY(const int y)
{
	this->y = y;
}

int Demo::getY()const
{
	return y;
}

void Demo::setS(const Sample& s)
{
	this->s = s;
}

Sample Demo::getS()const
{
	return s;
}

void Demo::display()
{
	cout<<"x="<<x<<" ,y="<<y<<endl;
}

inline Demo& 
Demo::operator+(const Demo& demo)
{
	this->x += demo.x;
	this->y += demo.y;
	
	return (*this);
}

inline ostream& 
operator<<(ostream &os,const Demo& demo)
{
	os<<"x="<<demo.getX()<<" ,y="<<demo.y;
	return os;
}

int main()
{
	Demo demo(4,5,6);
	demo.display();
	demo.getS().display();
	
	Demo d(demo);
	Sample s(20);
	d.setX(11);
	d.setY(12);
	d.setS(s);
	cout<<d<<endl;
	d.getS().display();
	
	cout<<(demo+d)<<endl;
	
	return 0;
}