#ifndef _SAMPLE_H
#define _SAMPLE_H

typedef int data_t;

class Sample           //C++中一个头文件可以对应多个源文件，即一个头文件可以分割到多个源文件中实现。
{
public:
	Sample(const data_t value);
	Sample(Sample& other);              //如果传入的实参是非const变量，则优先调用Sample&版本拷贝构造函数。
	Sample(const Sample& other);        //如果传入的实参是const变量，则优先调用const Sample&版本拷贝构造函数。
	
	void setValue(const data_t value);
	data_t getValue()const;
	
	void show()const;
private:
	data_t value;
};

#endif //_SAMPLE_H