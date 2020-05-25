#include <iostream>

using namespace std;

class Base
{
public:
	Base(){cout<<"Base1 constructor"<<endl;}
	Base(const int val){this->val = val;cout<<"Base2 constructor"<<endl;}
	~Base(){cout<<"Base destructor"<<endl;}
	
	int getVal()const{return val;}
	void setVal(const int val){this->val = val;}
	void display()const{cout<<"val="<<val<<endl;}
private:
	int val;
};

template<typename T>
class Demo:public Base
{
public:
	Demo(int val=0,T num=0):Base(val){this->num = num;cout<<"Demo constructor"<<endl;}
	~Demo(){cout<<"Demo destructor"<<endl;}
	
	T getNum()const{return num;}
	void setNum(const T num){this->num = num;}
	void display()const{Base::display();cout<<"num="<<num<<endl;}
private:
	T num;
};

int main()
{
	Demo<int> d(10,15);   //默认参数的匹配从第一个参数，一直到最后一个参数。
	d.display();
	
	d.setNum(11);
	d.Base::display();
	d.setVal(20);
	d.display();

	
	Demo<char> d1(7,'a');
	d1.setNum('b');
	d1.Base::display();
	d1.setVal(10);
	d1.display();	
	
	return 0;
}