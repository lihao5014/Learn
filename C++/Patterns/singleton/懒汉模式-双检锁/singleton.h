//双检锁机制：是对线程安全版本饿汉模式的改进，以防止每次进来都加锁。
#ifndef _SINGLETON_H_
#define _SINGLETON_H_

#include <iostream>
#include <mutex>

class Singleton
{
public:
//	~Singleton();      错误，会造成析构函数的递归调用,直接使用编译器生产的默认析构函数
	void setData(const int data);
	static void destroyInstance();
	
	int getData()const;
	void display()const;
	
	static Singleton& getInstance(const int data=0);
	static std::mutex m_mutex;
protected:
	Singleton(const int data=0);
	Singleton(const Singleton& other);
	Singleton& operator =(const Singleton& other);
private:
	static Singleton *instance;
	int data;
};


Singleton* Singleton::instance = nullptr;
std::mutex Singleton::m_mutex;

#if 0
Singleton& Singleton::getInstance(const int data)
{
	if(instance == nullptr){
		m_mutex.lock();
		if(instance == nullptr){
			instance = new Singleton(data);
		}
		m_mutex.unlock();
	}
	return *instance;
}
#else
Singleton& Singleton::getInstance(const int data)
{
	if(instance == nullptr){
		std::lock_guard<std::mutex> lock(m_mutex);
		if(instance == nullptr){
			instance = new Singleton(data);
		}
	}
	return *instance;
}	
#endif

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