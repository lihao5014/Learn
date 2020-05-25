#ifndef _SAMPLE_H
#define _SAMPLE_H

#include "singleton.h"

typedef int data_t;

class Sample:public Singleton<Sample>
{
public:
    void setData(const data_t& data);
    data_t getData()const;
    void display()const;

    friend class Singleton<Sample>;     //因为Singleton<T>::getInstance()函数中需要new T(),即调用类型Sample构造函数，
private:                                //而Sample构造函数又是private的，所以需要定义Singleton<Sample>类为友元函数，
    Sample();
    
    data_t data;
};

Sample::Sample():data(0)
{
    
}

void Sample::setData(const data_t& data)
{
    this->data = data;
}

data_t Sample::getData()const
{
    return data;
}

void Sample::display()const
{
    std::cout<<"data ="<<data<<std::endl;
}

#endif //_SAMPLE_H