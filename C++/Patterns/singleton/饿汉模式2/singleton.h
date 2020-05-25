#ifndef _SINGLETON_H_
#define _SINGLETON_H_

#include <iostream>

class Singleton
{
public:
	~Singleton();
	static Singleton& getInstance(const int data=0);
	
	void setData(const int data);
	int getData()const;
	void display()const;
private:
	Singleton(const int data=0);
	Singleton(const Singleton& other)=delete;
	Singleton& operator =(const Singleton& other)=delete;
	
	int data;
};

Singleton& Singleton::getInstance(const int data)
{
	static Singleton instance(data);
	return instance;
}

Singleton::~Singleton()
{

}

void Singleton::setData(const int data)
{
	this->data = data;
}

int Singleton::getData()const
{
	return data;
}

void Singleton::display()const
{
	std::cout<<"data ="<<data<<std::endl;
}

Singleton::Singleton(const int data)
{
	this->data = data;
}

#endif //_SINGLETON_H_