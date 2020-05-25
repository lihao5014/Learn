#ifndef _TAIL_H
#define _TAIL_H

#include <iostream>
#include <string.h>

using namespace std;

class Tail
{
public:
	Tail(const char* shape);
	Tail(const Tail& other);
	~Tail();
	
	void operator =(const char* shape);
	Tail operator =(const Tail& other);
	
	void display()const;
private:
	char* shape;
};

Tail::Tail(const char* shape)
	:shape(nullptr)
{
	if(shape != nullptr)
	{
		int strLen = strlen(shape) + 1;
		this->shape = new char[strLen];
		memcpy(this->shape,shape,strLen);
	}
}

Tail::Tail(const Tail& other)
	:shape(nullptr)
{
	if(other.shape != nullptr)
	{
		int strLen = strlen(other.shape) + 1;
		this->shape = new char[strLen];
		memcpy(this->shape,other.shape,strLen);
	}	
}

Tail::~Tail()
{
	if(shape != nullptr)
	{
		delete shape;
		shape = nullptr;
	}
}

void Tail::operator =(const char* shape)
{
	if(shape != nullptr)
	{
		if(this->shape != nullptr)
		{
			delete this->shape;
			this->shape = nullptr;
		}
		
		this->shape = new char[strlen(shape) + 1];
		strcpy(this->shape,shape);
	}
}

Tail Tail::operator =(const Tail& other)
{
	if(other.shape != nullptr)
	{
		if(shape != nullptr)
		{
			delete shape;
			shape = nullptr;
		}
		
		shape = new char[strlen(other.shape) + 1];
		strcpy(shape,other.shape);
	}
	return *this;
}

void Tail::display()const
{
	if(shape != nullptr)                    //怕Tail中的成员函数修改了shape指针，所以使用前都要做判空处理
	{
		cout<<"tail shape ="<<shape<<endl;
	}
}

#endif //_TAIL_H