#ifndef _SAMPLE_H
#define _SAMPLE_H

#include <string.h>
#include <iostream>

#define _DEEPLY_COPY_
#undef _DEEPLY_COPY_

using namespace std;

class Sample
{
public:
	Sample(const char* name);
	Sample(const Sample& other);
	virtual ~Sample();

	Sample& operator =(const Sample& other);
	bool  operator ==(const Sample& other);
	
#ifdef _DEEPLY_COPY_
	void setName(const char* name);
	const char* getName()const;
#else
	void setName(char* name);
	char* getName();
#endif
	
	void show()const;
private:
	char* name;
};

Sample::Sample(const char* name)
{
	if(name == nullptr)
	{
		this->name = nullptr;
	}
	else
	{
		this->name = new char[strlen(name) + 1];
		memcpy(this->name,name,strlen(name) + 1);
	}
}

#ifdef _DEEPLY_COPY_
Sample::Sample(const Sample& other)     //深拷贝
{
	if(other.name == nullptr)
	{
		name = nullptr;
	}
	else
	{
		name = new char[strlen(other.name) + 1];
		strcpy(name,other.name);
	}
}
#else
Sample::Sample(const Sample& other)     //浅拷贝，注意使用浅拷贝实现复制构造函数时，会造成同一个指针被释放两次bug
	:name(other.name)
{
	cout<<"shallow copy constructor"<<endl;
}
#endif

#ifdef _DEEPLY_COPY_
Sample::~Sample()
{
	if(name != nullptr)
	{
		delete[] name;    //对于int*、char*、double*等基本类型的指针数组，delete[]与delete效果是相同的
		name = nullptr;
	}
}
#else
Sample::~Sample()
{
	delete name;         //析构函数中delete释放成员指针时，不需要做判空和置空处理
}
#endif

#ifdef _DEEPLY_COPY_
Sample& Sample::operator =(const Sample& other)
{
	if(nullptr != name)
	{
		delete[] name;
		name = nullptr;
	}
	
	if(other.name != nullptr)
	{
		name = new char[strlen(other.name) + 1];
		memcpy(name,other.name,strlen(other.name) + 1);
	}
	
	return *this;
}
#else
Sample& Sample::operator =(const Sample& other)
{
	name = other.name;
	return *this;
}
#endif

#ifdef _DEEPLY_COPY_
bool Sample::operator ==(const Sample& other)
{
	if(name == other.name)
	{
		return true;
	}
	
	if(name == nullptr && other.name == nullptr)
	{
		return false;
	}
	
	return strcmp(name,other.name) == 0;
}
#else
bool Sample::operator ==(const Sample& other)
{
	if(name == other.name)
	{
		return true;
	}
	return false;
}
#endif

#ifdef _DEEPLY_COPY_
void Sample::setName(const char* name)    //使用深赋值实现setName方法
{
	if(this->name != nullptr)
	{
		delete this->name;
		this->name = nullptr;
	}
	
	if(nullptr != name)
	{
		this->name = new char[strlen(name) + 1];
		strcpy(this->name,name);
	}
}

const char* Sample::getName()const
{
	return name;
}
#else
void Sample::setName(char* name)    //使用浅赋值实现setName方法
{
	this->name = name;
}

char* Sample::getName()
{
	return name;
}
#endif

void Sample::show()const
{
	if(nullptr != name)
	{
		cout<<"name ="<<name<<endl;
	}
}

#endif //_SAMPLE_H