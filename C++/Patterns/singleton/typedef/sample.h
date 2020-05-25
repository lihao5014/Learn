#ifndef _SAMPLE_H
#define _SAMPLE_H

#include "singleton.h"
#include <iostream>

typedef int data_t;

class SampleImpl
{
public:
    SampleImpl(const data_t value = 0);
    SampleImpl(const SampleImpl& other);
    
    void setValue(const data_t value);
    data_t getValue()const;
    void display()const;
    
    SampleImpl operator =(const SampleImpl& other);
    friend std::ostream& operator <<(std::ostream& os,const SampleImpl& sample);
private:
    int value;
};

SampleImpl::SampleImpl(const data_t value):value(value)
{
    
}

SampleImpl::SampleImpl(const SampleImpl& other)
{
    value = other.value;
}

void SampleImpl::setValue(const data_t value)
{
    this->value = value;
}

data_t SampleImpl::getValue()const
{
    return value;
}

void SampleImpl::display()const
{
    std::cout<<"value ="<<value<<std::endl;
}

SampleImpl SampleImpl::operator =(const SampleImpl& other)
{
    value = other.value;
    return *this;
}

std::ostream& operator <<(std::ostream& os,const SampleImpl& sample)
{
    os<<"value ="<<sample.value;
    return os;
}

typedef Singleton<SampleImpl> Sample;

#endif //_SAMPLE_H