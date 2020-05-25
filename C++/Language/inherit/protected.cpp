#include <iostream>

using namespace std;

class Base
{
public:
	Base(){cout<<"Base1 constructor"<<endl;}
	Base(const int val){this->val = val;cout<<"Base2 constructor"<<endl;}
	~Base(){cout<<"Base destructor"<<endl;}
	
	int getVal()const{return val;}
	void display()const{cout<<"val="<<val<<endl;}
protected:
	void setVal(const int val){this->val = val;}
protected:
	int val;
};

class Demo:public Base
{
public:
	Demo(int val=0,int num=0):Base(val),num(num){cout<<"Demo constructor"<<endl;}
	~Demo(){cout<<"Demo destructor"<<endl;}
	
	int getNum()const{return num;}
	void display()const{cout<<"num="<<num<<endl;}	
	void setVal(const int val){Base::setVal(val);}
protected:
	void setNum(const int num){this->num = num;}
private:
	int num;
};

int main()
{
	Demo d(10,15);   //默认参数的匹配从第一个参数，一直到最后一个参数。
	
	d.display();
	d.Base::display();
//	d.setNum(11);      //protected成员是不能直接访问的
//  d.Base::setVal(12);
	d.setVal(7);
	d.Base::display();
	cout<<"val="<<d.getVal()<<endl;
	
	return 0;
}