#ifndef _SAMPLE_PROXY_
#define _SAMPLE_PROXY_

#include "sample.h"          //头文件包含，以提供Sample类型

class SampleProxy
{
public:
	SampleProxy(Sample* psample=nullptr);
	virtual ~SampleProxy();
	
	void setNum(const int num);
	int getNum()const;
	void display()const;
private:
	SampleProxy(const SampleProxy& other);                 //私有的拷贝构造函数和赋值运算符可以不用实现
	SampleProxy& operator=(const SampleProxy& other);
	
	Sample* psample;
};

#endif //_SAMPLE_PROXY_