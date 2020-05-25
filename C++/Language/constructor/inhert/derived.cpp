#include <iostream>

#define _ERROR_
#undef _ERROR_

using std::cout;
using std::endl;

class Base
{
public:
	Base():num(0),data(0){}
	Base(int num):num(num),data(0){}
	Base(int num,double data):Base(num){this->data = data;}            //委托构造
	Base(const Base& other){new (this) Base(other.num,other.data);}    //原始内存覆盖
	
	void setNum(const int num){this->num = num;}
	int getNum()const{return num;}
	
	void setData(const double data){this->data = data;}
	double getData()const{return data;}
	
	void show()const{cout<<"num ="<<num<<" ,data ="<<data<<endl;}
private:
	int num;
	double data;
};

class Derived:public Base
{
public:
	using Base::Base;         //继承构造函数,派生类使用了继承构造函数，并且增加了变量成员，那个新增加的变量成语必须使用就地初始化
	
	Derived(double value):Base(),value(value){}

#ifdef _ERROR_
	Derived(int num,double data,double value):Derived(num,data),value(value){}            //因为委托构造函数中已经初始化过了value，所以value不能继续初始化，只能赋值
#else
	Derived(int num,double data,double value):Derived(num,data){this->value = value;}     //一个变量只能被初始化一次
#endif
	
	void setValue(const double value){this->value = value;}
	double getValue()const{return value;}
	
	void display()const
	{
		cout<<"value ="<<value<<endl;
		show();
	}
private:
	double value = {2.71828};       //C++11就地初始化
};

int main(int argc,char** argv)
{
	Derived derived1(10);
	derived1.display();
	cout<<endl;
	
	Derived derived2(12,18);
	derived2.show();
	derived2.display();
	
	return 0;
}