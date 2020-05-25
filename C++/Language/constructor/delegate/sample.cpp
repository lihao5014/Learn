#include <iostream>

#define _GCC_
// #undef _GCC_

using namespace std;

class Sample
{
public:
	Sample();
	Sample(int data);
	Sample(int data,double value);
	Sample(const Sample& other);
	
	void setData(const int data);
	int getData()const;
	
	void setValue(const double value);
	double getValue()const;
	
	void display()const;
private:
	int data;
	double value;
};

Sample::Sample()
	:Sample(0,0)                                       //委托构造
{
	
}

#ifndef _GCC_
Sample::Sample(int data)
{
	this->Sample::Sample(data,0);                      //GCC编译器不支持这种方式的委托构造,VC++支持
}
#else
Sample::Sample(int data)
	:Sample(data,0)
{

}	
#endif

Sample::Sample(int data,double value)
	:data(data)
	,value(value)
{
	
}

Sample::Sample(const Sample& other)
{
	new(this) Sample(other.data,other.value);          //不是从新分配内存，而是直接覆盖在原内存上，即原始内存覆盖。
}


void Sample::setData(const int data)
{
	this->data = data;
}

int Sample::getData()const
{
	return data;
}

void Sample::setValue(const double value)
{
	this->value = value;
}

double Sample::getValue()const
{
	return value;
}

void Sample::display()const
{
	cout<<"data ="<<data<<" ,value ="<<value<<endl;
}

int main(void)
{
	Sample sample1;
	sample1.setData(4);
	sample1.setValue(3.1415);
	sample1.display();
	cout<<endl;
	
	Sample sample2(sample1);
	sample2.display();
	
	return 0;
}