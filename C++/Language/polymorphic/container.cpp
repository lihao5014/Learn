#include <iostream>

using namespace std;

#define PI 3.14

class Container
{
public:
	Container(const double r){redius=r;}
	virtual ~Container(){}
	
	virtual double area()const = 0;
	virtual double volume()const = 0;
	virtual void display()const{cout<<"area="<<area()<<" ,volume="<<volume()<<endl;}
protected:	
	double redius;
};

class Cube:public Container
{
public:
	Cube(const double l):Container(l){}
	virtual ~Cube(){}
	
	virtual double area()const{return 6*redius*redius;}
	double volume()const{return redius*redius*redius;}
};

class Sphere:public Container
{
public:
	Sphere(const double r):Container(r){}
	virtual ~Sphere(){}
	
	virtual double area()const{return 4*PI*redius*redius;}
	double volume()const{return 4/3*PI*redius*redius*redius;}
};

class Cylinder:public Container
{
public:
	Cylinder(const double r,const double h):Container(r){height=h;}
	virtual ~Cylinder(){}
	
	virtual double area()const{return 2*PI*redius*height;}
	double volume()const{return PI*redius*redius*height;}
private:
	double height;
};


int main(int argc,char* argv[])
{
	Container *p;
	Cube cube(4);
	Sphere sphere(5);
	Cylinder cylinder(4,6);
	
	p = &cube;
	p->display();
	
	p = &sphere;
	p->display();
	
	p = &cylinder;
	p->display();	
	
	return 0;
}