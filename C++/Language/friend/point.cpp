#include <iostream>
#include <cmath>

using namespace std;

class Point;
class Distance;

//直线的方程：ax+by+c=0;
class Line
{
public:
	Line(int a,int b,int c)
	{
		this->a = a;
		this->b = b;
		this->c = c;
		cout<<a<<"x"<<"+"<<b<<"y"<<"+"<<c<<"=0"<<endl;
	}
	
	friend double distance(const Line &l,const Point &p);     //distance函数有Line和Point两个类型参数，所有需要设置为Line和Point两个类的有元函数
	friend class Distance;
private:
	int a,b,c;
};

class Point
{
public:
	Point(int x=0,int y=0)
	{
		this->x = x;
		this->y = y;
		cout<<"点("<<x<<","<<y<<")"<<endl;
	}
	
	friend double distance(const Point &a,const Point &b);
	
	friend double distance(const Line &l,const Point &p)
	{
		return abs(l.a*p.x+l.b*p.y+l.c)/sqrt(l.a*l.a+l.b+l.b);
	}
	
	friend class Distance;
private:
	int x;
	int y;
};

class Distance
{
public:
	Distance(const Point& a,const Point& b)
	{
		dis = sqrt((a.x-b.x)*(a.y-b.y)+(a.y-b.y)*(a.y-b.y));		
	}
	
	Distance(const Line& l,const Point& p)
	{
		dis = abs(l.a*p.x+l.b*p.y+l.c)/sqrt(l.a*l.a+l.b+l.b);
	}
	
	double getDistance()const
	{
		return dis;
	}
private:
	double dis;
};

double distance(const Point &a,const Point &b)
{
	return sqrt((a.x-b.x)*(a.y-b.y)+(a.y-b.y)*(a.y-b.y));
}

int main()
{
	Point a(2,2),b(5,5);
	cout<<"point1: distance ="<<distance(a,b)<<endl;
	
	Line l(3,4,5);
	cout<<"line1: distance ="<<distance(l,a)<<endl;
	
	Distance d1(a,b);
	cout<<"point2: distance ="<<d1.getDistance()<<endl;
	
	Distance d2(l,a);
	cout<<"line2: distance ="<<d2.getDistance()<<endl;
	
	return 0;
}