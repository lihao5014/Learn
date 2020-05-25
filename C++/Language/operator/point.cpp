//一般来说：单目运算符最好重载为成员函数，双目运算符最好重载为友元函数

#include <iostream>

using namespace std;

class Point
{
public:
	Point(){}
	Point(int x,int y):x(x),y(y){}
	void display()const
	{
		cout<<"("<<x<<","<<y<<")"<<endl;
	}
	
	Point operator+(const Point &p)
	{
		return Point(x+p.x,y+p.y);
	}
	
	friend ostream& operator<<(ostream &os,const Point &p);
private:
	int x,y;
};

ostream& operator<<(ostream &os,const Point &p)
{
	os<<"("<<p.x<<","<<p.y<<")";
	return os;
}

int main()
{
	Point p1(1,2),p2(1,3),p3;
	
	p1.display();
	p2.display();
	p3.display();
	
	p3 = p1 + p2;
	p3.display();
	cout<<p3<<endl;
	
	return 0;
}