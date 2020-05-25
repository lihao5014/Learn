#ifndef _SINGLETON_H
#define _SINGLETON_H

#include <iostream>
#include <mutex>

typedef int data_t;

class Singleton
{
public:
    static Singleton* getInstance();
    
    void setData(const data_t& data);
    data_t getData()const;
    void display()const;
private:
    class GC                       // GC类唯一的工作就是在析构函数中删除Singleton的实例
    {
    public:
        ~GC()
        {
            std::cout<<"~GC(): delete m_instance"<<std::endl;
            if(m_instance != nullptr){
                delete m_instance;
                m_instance = nullptr;
            }
        }
    };
    
    Singleton();
    Singleton(const Singleton& other) = delete;
    Singleton& operator =(const Singleton& other) = delete;
    
    static Singleton *m_instance;
    static std::mutex m_mutex;
    static GC gc;                //定义一个静态成员，在程序结束时，系统会调用它的析构函数
    data_t data;
};

Singleton* Singleton::m_instance = nullptr;
std::mutex Singleton::m_mutex;
Singleton::GC Singleton::gc;     //静态成员需要类外部初始化,否则程序运行时连GC的构造都不会进入，何谈自动析构

Singleton::Singleton()
{
    data = 0;
}

Singleton* Singleton::getInstance()
{
    if(m_instance == nullptr){
        std::lock_guard<std::mutex> lock(m_mutex);
        if(m_instance == nullptr){
            m_instance = new Singleton; 
        }
    }
    
    return m_instance;
}
    
void Singleton::setData(const data_t& data)
{
    this->data = data;
}

data_t Singleton::getData()const
{
    return data;
}

void Singleton::display()const
{
    std::cout<<"data ="<<data<<std::endl;
}

#endif  //_SINGLETON_H