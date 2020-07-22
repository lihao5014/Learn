#include <stdlib.h>
#include <iostream>

#define _CHANGE_WAY_
// #undef _CHANGE_WAY_

#define SIZE 5

using namespace std;

typedef int data_t;

class Sample
{
public:
	/* explicit */ Sample():data(0){};                            //默认构造函数
	/* explicit */ Sample(const data_t data):data(data){};
	
	/* explicit */ Sample(const Sample& other):data(other.data){};    //拷贝构造函数最好不加explicit，因为return返回Sample会隐式调用拷贝构造函数
	
	void setData(const data_t data){this->data = data;};
	data_t getData()const{return data;};
	
	void print()const{cout<<"data ="<<data<<endl;};
private:
	data_t data;
};

class Demo
{
public:
	Demo(const data_t value):value(value){}             //会调用Sample的默认构造函数
	Demo(const data_t data,const data_t value):sample(data),value(value){}
	Demo(const Sample& sample,const data_t value):sample(sample),value(value){}
	Demo(const Demo& other):sample(other.sample),value(other.value){}
	
	void setSample(const Sample& sample){this->sample = sample;}
	Sample getSample()const{return sample;}
	
	void setValue(const data_t value){this->value = value;}
	data_t getValue()const{return value;}
	
	void show()const{sample.print(); cout<<"value ="<<value<<endl;}
	void show(){cout<<"sample.data ="<<sample.getData()<<" ,value ="<<value<<endl;}
private:
	Sample sample;
	data_t value;
};

class Test
{
public:
	Test(const data_t data);
	Test(const Sample& sample);
	Test(const Test& other);

	void setSample(int index,const Sample& sample);
	Sample getSample(int index)const;
	
	void setData(int index,const data_t data);
	data_t getData(int index)const;
	
	void display()const;
private:
	Sample samples[SIZE];
};

#ifndef _CHANGE_WAY_
Test::Test(const data_t data)
	:samples{data,data,data,data,data}          //C++11才支持数组使用初始化列表，进行初始化的方法。
{                                               //C++98中对象数组成员变量只能赋值不能在初始化列表中对其进行初始化。且对象数组所属类必须提供默认构造函数

}

Test::Test(const Sample& sample)
{
	for(int i=0;i<SIZE;++i)
	{
		samples[i] = sample;
	}
}

Test::Test(const Test& other)                  //调用Sample的默认构造函数
{
	for(int i=0;i<SIZE;++i)
	{
		samples[i].setData(other.samples[i].getData());        //或者 samples[i] = other.samples[i]
	}
}

#else
Test::Test(const data_t data)
	:samples{Sample(data),Sample(data),Sample(data),Sample(data),Sample(data)}
{

}

Test::Test(const Sample& sample)
	:samples{sample,sample,sample,sample,sample}
{

}

Test::Test(const Test& other)
	:samples{
		other.samples[0],
		other.samples[1],
		other.samples[2],
		other.samples[3],
		other.samples[4],
	}
{

}
#endif

void Test::setSample(int index,const Sample& sample)
{
	if(index < 0 || index >= SIZE)
	{
		cout<<"index is illegal"<<endl;
		return ;
	}

	samples[index] = sample;
}

Sample Test::getSample(int index)const
{
	if(index < 0 || index >= SIZE)
	{
		cout<<"index is illegal"<<endl;
		abort();
	}
	
	return samples[index];
}

void Test::setData(int index,const data_t data)
{
	if(index < 0 || index >= SIZE)
	{
		cout<<"index is illegal"<<endl;
		return ;
	}
	
	samples[index].setData(data);
}

data_t Test::getData(int index)const
{
	if(index < 0 || index >= SIZE)
	{
		cout<<"index is illegal"<<endl;
		throw "index is illegal";
	}
	
	return samples[index].getData();
}

void Test::display()const
{
	for(int i=0;i<SIZE;++i)
	{
		cout<<samples[i].getData()<<" ";
	}
	cout<<endl;
}

int main()
{
	Sample sample(10);
	sample.print();
	
	const Demo demo1(3,4);
	demo1.show();
	
	Demo demo2(sample,5);
	demo2.show();
	
	Test test1(Sample(8));
	test1.display();
	test1.setSample(2,sample);
	test1.display();
	
	Test test2(20);
	test2.display();
	test2.setData(2,30);
	test2.display();
	
	return 0;
}