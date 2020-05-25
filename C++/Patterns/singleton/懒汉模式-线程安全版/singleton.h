#ifndef _SINGLETON_H_
#define _SINGLETON_H_

#include <iostream>
#include <pthread.h>

class Singleton
{
public:
//	~Singleton();      错误，会造成析构函数的递归调用,直接使用编译器生产的默认析构函数
	void setData(const int data);
	int getData()const;
	void display()const;
	
	static Singleton& getInstance(const int data=0);
	static void destroyInstance();
	static pthread_mutex_t mutex;
protected:
	Singleton(const int data=0);
	Singleton(const Singleton& other);
	Singleton& operator =(const Singleton& other);
private:
	static Singleton *instance;
	int data;
};

//懒汉模式-线程安全
Singleton* Singleton::instance = nullptr;
pthread_mutex_t Singleton::mutex = PTHREAD_MUTEX_INITIALIZER;

Singleton& Singleton::getInstance(const int data)
{
	pthread_mutex_lock(&mutex);
	if(instance == nullptr){
		instance = new Singleton(data);
	}
	pthread_mutex_unlock(&mutex);
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