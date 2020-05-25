#ifndef _SAMPLE_PROXY_
#define _SAMPLE_PROXY_

//尽管sampleproxy.h头文件中没有包含Sample类型数据，但这个程序依然可以编译成功。说明在头文件中包含其他头文件或者前置声明数据类型都不是必须的。
//只要在sampleproxy.cpp源文件和需要使用sampleproxy.h头文本的源文件中，在包含sampleproxy.h头文件前先包含sample.h即可。因为在C/C++中最小编译
//单元都是源文件，而#include预处理指令的作用只是简单的文件复制，并不会做其他多余的工作。编译器会先将除包含了main函数以外的一个个源文件编译通过，
//然后在编译包含main函数的源文件中进行衔接，最后生成可执行的exe文件。。

class SampleProxy
{
public:
	SampleProxy(Sample* psample=nullptr);
	virtual ~SampleProxy();
	
	void setNum(const int num);
	int getNum()const;
	void display()const;
private:
	SampleProxy(const SampleProxy& other);               //私有的拷贝构造函数和赋值运算符可以不用实现
	SampleProxy& operator=(const SampleProxy& other);
	
	Sample* psample;              //没有包含sample.h头文件，也没有对Sample类型做前置声明
};

#endif //_SAMPLE_PROXY_