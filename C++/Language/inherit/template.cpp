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

template <typename T>
class Base
{
public:
	Base(){cout<<"Base1 constructor"<<endl;}
	Base(const T val){this->val = val;cout<<"Base2 constructor"<<endl;}
	~Base(){cout<<"Base destructor"<<endl;}
	
	T getVal()const{return val;}
	void display()const{cout<<"val="<<val<<endl;}
protected:
	void setVal(const T val){this->val = val;}
private:
	T val;
};

template<typename T1,typename T2>
class Demo:public Base<T2>
{
public:
	Demo(const Sample& s=Sample(0),T2 val=0,T1 num=0):Base<T2>(val),s(s){this->num = num;cout<<"Demo constructor"<<endl;}
	~Demo(){cout<<"Demo destructor"<<endl;}
	
	T1 getNum()const{return num;}
	void display()const{cout<<"num="<<num<<endl;}
	
	void setSample(const Sample& s){this->s = s;}
	Sample& getSample(){return s;}
	
	void setVal(const T1 val){Base<T2>::setVal(val);}
protected:
	void setNum(const T1 num){this->num = num;}
private:
	T1 num;
	Sample s;
};

int main()
{
	Demo<int,int> d(10);   //默认参数的匹配从第一个参数，一直到最后一个参数。
	
	d.display();
	d.Base::display();
	cout<<"data="<<(d.getSample().getDate())<<endl;
//	d.setNum(11);      //protected成员是不能直接访问的
//  d.Base::setVal(12);
	d.setVal(7);
	d.Base::display();
	cout<<"val="<<d.getVal()<<endl;
	
	Demo<char,double> d2(10,3.14,'a');
	d2.display();
	d2.Base::display();	
	d2.getSample().display();
	
	return 0;
}