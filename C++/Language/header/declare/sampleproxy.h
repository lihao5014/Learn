#ifndef _SAMPLE_PROXY_
#define _SAMPLE_PROXY_

class Sample;          //前置声明Sample类型

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
	
	Sample* psample;     //因为声明的是Sample类型的指针，所以可以使用前置声明的方式。如果是Sample类型的对象，则必须使用头文件包含的方式。
};

#endif //_SAMPLE_PROXY_