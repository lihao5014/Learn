#include <iostream>
#include <array>

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

int main(void)
{
#ifdef _ERROR_ 
	array<Sample,SIZE> samples;                      //因为Sample类没有提供默认的构造函数,所以 array中无法装入Sample对象，编译报错
#else
	array<Sample,SIZE> samples = {0,1,2,3,4};        //因为Sample类没有提供默认的构造函数，所以必须使用{}初始化。并且定义array<Sample,SIZE>对象时，就已经装入了Sample对象
#endif

	samples[0].show();
	samples[1].show();
	cout<<endl;
	
	array<Sample*,SIZE> psamples;
	for(int i=0;i<SIZE;++i)
	{
		psamples[i] = new Sample(2 * i);
	}
	
	for(int j=0;j<SIZE;++j)
	{
		psamples[j]->show();
		delete psamples[j];
	}
	
	return 0;
}