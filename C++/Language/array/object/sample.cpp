#ifndef _SAMPLE_H
#define _SAMPLE_H

#include <stdlib.h>
#include <iostream>

#define _CHANGE_WAY_
// #undef _CHANGE_WAY_

#define _ERROR_
#undef _ERROR_

#define SIZE 5

#define DisplayArr(arr,size)                            \
	do{                                                 \
		if((arr) == nullptr || (size) <= 0)             \
		{                                               \
			cout<<"arr or size is illegal"<<endl;       \
			exit(-1);                                   \
		}                                               \
		                                                \
		for(int i=0;i<size;++i)                         \
		{                                               \
			cout<<arr[i].getNum()<<" ";                 \
		}                                               \
		cout<<endl;                                     \
	}while(0)

using std::cout;
using std::endl;

class Sample
{
public:
	// Sample():num(0){}                //默认构造函数
	Sample(const int num):num(num){}
	Sample(const Sample& other):num(other.num){}
	
	void setNum(const int num){this->num = num;}
	int getNum()const{return num;}
	
	void show()const{cout<<"num ="<<num<<endl;}
private:
	int num;
};

static void printArr(const Sample sampleArr[],int size);

template <typename T>
static void showArr(const T* arr,int size);

int main()
{
#ifdef _ERROR_
	Sample sampleArr[SIZE];               //因为Sample类型没有默认构造函数，所以这里编译不通过
	DisplayArr(sampleArr,SIZE);
#else
	Sample *psampleArr[SIZE];              //Sample类型没有默认构造函数,但是可以定义Sample指针数组，然后对数组中的指针逐一赋值
	for(int i=0;i<SIZE;++i)
	{
		psampleArr[i] = new Sample(i);
	}
	
	for(int i=0;i<SIZE;++i)
	{
		if(psampleArr[i] != nullptr)
		{
			psampleArr[i]->show();
			delete psampleArr[i];
			psampleArr[i] = nullptr;
		}
	}
#endif
	
#ifndef _CHANGE_WAY_
	Sample samples[SIZE] = {0,1,2,3,4};                                           //隐式调用Sample(const int num)构造函数
#else
	Sample samples[SIZE] = {Sample(0),Sample(1),Sample(2),Sample(3),Sample(4)};   //显式调用Sample(const int num)构造函数
	Sample sample(samples[2]);                                                    //显示调用拷贝构造函数
	sample.show();
#endif
	
	printArr(samples,SIZE);
	DisplayArr(samples,sizeof(samples)/sizeof(Sample));
	showArr(samples,sizeof(samples)/sizeof(samples[0]));
	
	Sample *psample = new Sample[SIZE]{5,6,7,8,9};            //显式调用Sample(const int num)构造函数
	showArr(psample,SIZE);
	if(psample != nullptr)
	{
		delete[] psample;
		psample = nullptr;
	}
	
	return 0;
}

static void printArr(const Sample sampleArr[],int size)
{
	if(size <= 0)
	{
		cout<<"size is less than zero"<<endl;
		return ;
	}
	
	for(int i=0;i<size;++i)
	{
		cout<<sampleArr[i].getNum()<<" ";
	}
	cout<<endl;
}

template <typename T>
void showArr(const T* arr,int size)
{
	if((arr) == nullptr || (size) <= 0)
	{
		cout<<"arr or size is illegal"<<endl;
		return ;
	}  

	for(int i=0;i<size;++i)
	{
		cout<<arr[i].getNum()<<" ";         //模板类型T必须具有public的getNum方法才能编译通过
	}
	cout<<endl;		  	
}

#endif //_SAMPLE_H