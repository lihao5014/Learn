#include <iostream>

using namespace std;

class Point
{
public:
	Point(){x=0;y=0;}
	Point(int x,int y){this->x=x;this->y=y;}
	
	void setX(const int x){this->x=x;}
	int getX()const{return x;}
	void setY(const int y){this->y=y;}
	int getY()const{return y;}
	int area()const{return 0;}
	
	void display()const{cout<<"("<<x<<","<<y<<")"<<endl;}
	friend ostream& operator <<(ostream& os,const Point& point)
	{
		os<<"("<<point.x<<","<<point.y<<")";
		return os;
	}
private:	
	int x,y;
};

class Rectangle:public Point
{
public:
	Rectangle(){l=0;w=0;}
	Rectangle(int l,int w){this->l=l;this->w=w;}
	
	void setL(const int l){this->l=l;}
	int getL()const{return l;}
	void setW(const int w){this->w=w;}
	int getW()const{return w;}	
	int area()const{return l*w;}
	
	void display()const{Point::display();cout<<"["<<l<<","<<w<<"]"<<endl;}
	friend ostream& operator <<(ostream& os,const Rectangle& rect)
	{
		os<<(Point)rect;
		os<<"["<<rect.l<<","<<rect.w<<"]";
		return os;
	}
private:
	int l,w;
};

void showArea(const Point& p)
{
	cout<<"area="<<p.area()<<endl;
}

void showArea(const Point* p)
{
	cout<<"area="<<p->area()<<endl;
}

int main()
{
	Rectangle r(4,5);
	
	cout<<r<<endl;
	showArea(r);
	showArea(&r);
	
	Point* p;
	p = &r;
//	p->setL(5);
	p->display();						//¾²Ì¬Áª±à
	cout<<"area="<<p->area()<<endl;     //¾²Ì¬Áª±à
	
	return 0;
}