#ifndef _SINGLETON_H_
#define _SINGLETON_H_

#include <iostream>

class Singleton
{
public:
//	~Singleton();       //错误，会造成析构函数的递归调用,直接使用编译器生产的默认析构函数
	static Singleton& getInstance(const int data=0);
	static void destroyInstance();
	
	void setData(const int data);
	int getData()const;
	void display()const;
protected:
	Singleton(const int data=0);
	Singleton(const Singleton& other);
	Singleton& operator =(const Singleton& other);
private:	
	static Singleton *instance;
	int data;
};

//懒汉模式
Singleton* Singleton::instance = nullptr;

Singleton& Singleton::getInstance(const int data)
{
	if(instance == nullptr){
		instance = new Singleton(data);
	}
	return *instance;
}

void Singleton::destroyInstance()
{
	if(instance != NULL){	
		delete instance;
		instance = NULL;
	}	
}

/*
Singleton::~Singleton()
{
	if(instance != NULL){
		delete instance;
		instance = NULL;
	}
}
*/

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

Singleton::Singleton(const Singleton& other)
{
	data = other.data;
}

Singleton& Singleton::operator =(const Singleton& other)
{
	data = other.data;
	return *this;
}

#endif //_SINGLETON_H_