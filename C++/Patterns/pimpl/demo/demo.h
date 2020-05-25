//注意模板类的方法实现只能写在头文件中，不可以写在源文件中

#ifndef _DEMO_H
#define _DEMO_H

#include <iostream>
#include <assert.h>

template <typename T>
class Demo
{
public:
    Demo(const T& value);
    Demo(const Demo& demo);
    virtual ~Demo();
    
    void setValue(const T& value);
    T getValue()const;
    void show()const;
private:
    class DemoImpl;
    
    DemoImpl *pimpl;
};

template <typename T>
class Demo<T>::DemoImpl
{
public:
    DemoImpl(const T& value);
    DemoImpl(const DemoImpl& other);
    
    void setValue(const T& value);
    T getValue()const;
    void show()const;
private:
    T value;
};

template <typename T>
Demo<T>::DemoImpl::DemoImpl(const T& value)
    :value(value)
{
    
}

template <typename T>
Demo<T>::DemoImpl::DemoImpl(const DemoImpl& other)
    :value(other.value)
{
    
}

template <typename T>
void Demo<T>::DemoImpl::setValue(const T& value)
{
    this->value = value;
}

template <typename T>
T Demo<T>::DemoImpl::getValue()const
{
    return value;
}

template <typename T>
void Demo<T>::DemoImpl::show()const
{
    std::cout<<"value ="<<value<<std::endl;
}


template <typename T>
Demo<T>::Demo(const T& value)
    :pimpl(new DemoImpl(value))
{
    
}

template <typename T>
Demo<T>::Demo(const Demo& demo)
    :pimpl(new DemoImpl(demo.getValue()))
{
    
}

template <typename T>
Demo<T>::~Demo()
{
    if(pimpl != nullptr){
        delete pimpl;
        pimpl = nullptr;
    }
}

template <typename T>
void Demo<T>::setValue(const T& value)
{
    if(pimpl != nullptr){
        pimpl->setValue(value);
    }
}

template <typename T>
T Demo<T>::getValue()const
{
    assert(pimpl != nullptr);
    return pimpl->getValue();
}

template <typename T>
void Demo<T>::show()const
{
    if(pimpl != nullptr){
        pimpl->show();
        return ;
    }
    
    std::cout<<"pimpl == nullptr"<<std::endl;
}

#endif //_DEMO_H