#ifndef _SAMPLE_H
#define _SAMPLE_H

#include "noncopyable.h"

#define FLAG 0

class Sample:private Noncopyable
{
public:
    Sample(const int value);

#if FLAG    
    Sample(const Sample& other);   //Noncopyable只用于限制默认的拷贝构造函数
#endif

    void setValue(const int value);
    int getValue()const;
    void print()const;
private:
    int value;
};


#endif //_SAMPLE_H