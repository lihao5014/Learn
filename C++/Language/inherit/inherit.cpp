#include <iostream>

using namespace std;

template<typename T>
class Base
{
public:
	Base(){cout<<"Base1 constructor"<<endl;}
	Base(const T val){this->val = val;cout<<"Base2 constructor"<<endl;}
	~Base(){cout<<"Base destructor"<<endl;}
	
	T getVal()const{return val;}
	void setVal(const T val){this->val = val;}
	void display()const{cout<<"val="<<val<<endl;}
private:
	T val;
};

class Demo:public Base<int>
{
public:
	Demo(int val=0,int num=0):Base<int>(val){this->num = num;cout<<"Demo constructor"<<endl;}
	~Demo(){cout<<"Demo destructor"<<endl;}
	
	int getNum()const{return num;}
	void setNum(const int num){this->num = num;}
	void display()const{Base::display();cout<<"num="<<num<<endl;}
private:
	int num;
};

class Sample:public Base<char>
{
public:
	Sample(char val='a',int num=0):Base<char>(val){this->num = num;cout<<"Sample constructor"<<endl;}
	~Sample(){cout<<"Sample destructor"<<endl;}
	
	int getNum()const{return num;}
	void setNum(const int num){this->num = num;}
	void display()const{Base::display();cout<<"num="<<num<<endl;}
private:
	int num;
};

int main()
{
	Demo d(10,15);   //默认参数的匹配从第一个参数，一直到最后一个参数。
	d.display();
	
	d.setNum(11);
	d.Base::display();
	d.setVal(20);
	d.display();

	
	Sample s1('a',7);
	s1.setNum(8);
	s1.Base::display();
	s1.setVal('b');
	s1.display();	
	
	return 0;
}