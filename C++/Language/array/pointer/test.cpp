#include <iostream>

#define _CHANGE_WAY_
// #undef _CHANGE_WAY_

#define _ERROR_
#undef _ERROR_

#define SIZE 5

using namespace std;

class Sample
{
public:
	// Sample():value(0){}                               //默认构造函数
	Sample(int value):value(value){}
	Sample(const Sample& other):value(other.value){}
	
	void setValue(int value){this->value = value;}
	int getValue()const{return value;}
	
	void show()const{cout<<"value ="<<value<<endl;}
private:
	int value;
};

#ifndef _CHANGE_WAY_
class Test
{
public:
	Test(const int value);
	Test(const Test& other);
	~Test();
	
	void display()const;
private:
	Sample *samples[SIZE];         //如果Sample类没有默认构造函数，且编译器不支持C++11标准的话，只能定义对象数组指针成员变量
};

Test::Test(const int value)
{
	for(int i=0;i<SIZE;++i)
	{
		samples[i] = new Sample(value);
	}
}

Test::Test(const Test& other)
{
	for(int i=0;i<SIZE;++i)
	{
		if(other.samples[i] != nullptr)
		{
			samples[i] = new Sample(*(other.samples[i]));
			continue;
		}
		samples[i] = nullptr;
	}
}

Test::~Test()
{
	for(int i=0;i<SIZE;++i)
	{
		if(samples[i] != nullptr)
		{
			delete samples[i];
			samples[i] = nullptr;
		}
	}
}

void Test::display()const
{
	for(int i=0;i<SIZE;++i)
	{
		if(samples[i] != nullptr)
		{
			cout<<samples[i]->getValue()<<" ";
		}
	}
	cout<<endl;	
}

#else
class Test
{
public:
	Test(const int value);
	Test(const Test& other);
	~Test();
	
	void display()const;
private:
	Sample samples[SIZE];            //如果Sample类没有默认构造函数，但编译器支持C++11标准的话，可以定义对象数组成员变量。
};

Test::Test(const int value)
	:samples{value,value,value,value,value}
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

Test::~Test()
{
	
}

void Test::display()const
{
	for(int i=0;i<SIZE;++i)
	{
		cout<<samples[i].getValue()<<" ";
	}
	cout<<endl;
}
#endif

static void printArr(const Sample *arr,int size);

int main(void)
{
	Test test1(5);
	test1.display();
	
	Test test2(test1);
	test2.display();
	
#ifdef _ERROR_
	Sample samples[SIZE];                                    //Sample没有默认构造函数，所以编译不通过
	printArr(samples,sizeof(samples)/sizeof(Sample));
#else
	Sample *psamples[SIZE];
	for(int i=0;i<SIZE;++i)
	{
		psamples[i] = new Sample(2 * i);
	}

	for(int i=0;i<SIZE;++i)
	{
		if(psamples[i] != nullptr)
		{
			psamples[i]->show();
			delete psamples[i];
			psamples[i] = nullptr;
		}
	}
#endif
	
	Sample *psample = new Sample[SIZE]{5,6,7,8,9};
	printArr(psample,SIZE);
	if(psample != nullptr)
	{
		delete[] psample;
		psample = nullptr;
	}
	
	return 0;
}

static void printArr(const Sample *arr,int size)
{
	if(arr == nullptr || size <= 0)
	{
		cout<<"arr is null,or size <= 0"<<endl;
		return ;
	}
	
	for(int i=0;i<size;++i)
	{
		arr[i].show();
	}
}