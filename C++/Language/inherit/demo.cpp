#include <iostream>

using namespace std;

class Sample
{
public:
	Sample(){cout<<"Sample1 constructor"<<endl;}
	Sample(const int data){this->data = data;cout<<"Sample2 constructor"<<endl;}
	Sample(const Sample& s){data = s.data;cout<<"Sample3 constructor"<<endl;}
	~Sample(){cout<<"Sample destructor"<<endl;}
	
	void setData(const int data){this->data = data;}
	int getDate()const{return data;}
	void display()const{cout<<"data="<<data<<endl;}
private:
	int data;
};

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
private:
	int val;
};

class Demo:public Base
{
public:
	Demo(const Sample& s=Sample(0),int val=0,int num=0):Base(val),s(s){this->num = num;cout<<"Demo constructor"<<endl;}
	~Demo(){cout<<"Demo destructor"<<endl;}
	
	int getNum()const{return num;}
	void display()const{cout<<"num="<<num<<endl;}
	
	void setSample(const Sample& s){this->s = s;}
	Sample& getSample(){return s;}
	
	void setVal(const int val){Base::setVal(val);}
protected:
	void setNum(const int num){this->num = num;}
private:
	int num;
	Sample s;               //成员变量先于基类构造
};

int main()
{
	Demo d(10);   //默认参数的匹配从第一个参数，一直到最后一个参数。
	
	d.display();
	d.Base::display();
	cout<<"data="<<(d.getSample().getDate())<<endl;
//	d.setNum(11);      //protected成员是不能直接访问的
//  d.Base::setVal(12);
	d.setVal(7);
	d.Base::display();
	cout<<"val="<<d.getVal()<<endl;
	
	return 0;
}