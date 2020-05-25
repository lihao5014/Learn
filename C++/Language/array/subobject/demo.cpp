#include <assert.h>
#include <iostream>

#define _CHANGE_WAY_
// #undef _CHANGE_WAY_

#define _ERROE_H
#undef _ERROE_H

#define SIZE 5

using std::cout;
using std::endl;

class Sample
{
public:
	// Sample():value(0){}                 //默认构造函数
	Sample(const int value):value(value){}
	Sample(const Sample& other):value(other.value){}
	
	void setValue(const int value){this->value = value;}
	int getValue()const{return value;}
	
	void show()const{cout<<"value ="<<value<<endl;}
private:
	int value;
};

class Demo
{
public:
	Demo(const int value);
	Demo(const Demo& other);
	
	void setSample(int index,const Sample& sample);
	Sample getSample(int index)const;
		
	void setData(int index,int value);
	int getData(int index)const;
	
	void display()const;
private:
	Sample sampleArr[SIZE];          //对于C++11以前的标准，如果Sample没有默认构造函数，则这里就不能定义为对象数组。而应该换为对象数组指针Sample *sampleArr[SIZE]
};

Demo::Demo(const int value)
	:sampleArr{value,value,value,value,value}          //C++11以后才支持这种初始化列表中对象数组初始化方法
{
	
}

#ifndef _ERROE_H
Demo::Demo(const Demo& other)
	:sampleArr{
		other.sampleArr[0],
		other.sampleArr[1],
		other.sampleArr[2],
		other.sampleArr[3],
		other.sampleArr[4]
	}
{
	
}
#else
Demo::Demo(const Demo& other)
	:sampleArr[0](other.sampleArr[0])       //因为sampleArr[i]对象都没有构造出来，所以这里使用中括号[]访问没有构造出来的对象存在bug
	,sampleArr[1](other.sampleArr[1])
	,sampleArr[2](other.sampleArr[1])
	,sampleArr[3](other.sampleArr[1])
	,sampleArr[4](other.sampleArr[1])
{
	
}
#endif

void Demo::setSample(int index,const Sample& sample)
{
	if(index < 0 || index >= SIZE)
	{
		cout<<"index is illegal"<<endl;
		return ;
	}
	
	sampleArr[index] = sample;
}

Sample Demo::getSample(int index)const
{
	assert(index >= 0);
	assert(index < SIZE);
	
	return sampleArr[index];
}
	
void Demo::setData(int index,int value)
{
	if(index < 0 || index >= SIZE)
	{
		cout<<"index is illegal"<<endl;
		return ;
	}

	sampleArr[index].setValue(value);
}

int Demo::getData(int index)const
{
	if(index < 0 || index >= SIZE)
	{
		cout<<"index is illegal"<<endl;
		throw "index is illegal";
	}
	
	return sampleArr[index].getValue();
}

void Demo::display()const
{
	for(int i=0;i<SIZE;++i)
	{
		cout<<sampleArr[i].getValue()<<" ";
	}
	cout<<endl;
}

static void printArr(const Sample *arr,int size);

int main(int argc,char** argv)
{
#ifdef _ERROE_H
	Sample arr[SIZE];        //Sample类型没有默认构造函数，所以这里编译不通过
	printArr(arr,SIZE);
#else
	Sample *arr[SIZE];       //Sample类型没有默认构造函数，但可以定义Sample数组指针，指针的大小都是4个字节
	for(int i=0;i<SIZE;++i)
	{
		arr[i] = new Sample(2*i);
	}
	
	for(int i=0;i<SIZE;++i)
	{
		arr[i]->show();
		delete arr[i];
		arr[i] = nullptr;
	}
#endif

#ifdef _CHANGE_WAY_
	Sample samples[SIZE]{0,1,2,3,4};
#else
	Sample samples[SIZE] = {0,1,2,3,4};
#endif
	printArr(samples,SIZE);

	Sample *psample = new Sample[SIZE]{5,6,7,8,9};
	printArr(psample,SIZE);
	if(psample != nullptr)
	{
		delete[] psample;
		psample = nullptr;
	}
	
	Demo demo(5);
	demo.display();
	
	demo.setData(2,10);
	cout<<"index =3, value ="<<demo.getData(3)<<endl;
	demo.display();

	return 0;
}

void printArr(const Sample *arr,int size)
{
	assert(arr != nullptr);
	assert(size > 0);
	
	for(int i=0;i<size;++i)
	{
		cout<<arr[i].getValue()<<" ";
	}
	cout<<endl;
}