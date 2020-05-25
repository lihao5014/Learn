#ifndef _SAMPLE_H
#define _SAMPLE_H

#include <iostream>
#include <assert.h>

class Sample
{
public:
    Sample(const int data=0);
    Sample(const Sample& other);
    
    void setData(const int data);
    int getData()const;
    void display()const;
    
    friend std::ostream& operator <<(std::ostream& os,const Sample& s);
private:
    class Garbo                     //嵌套类只能访问外部类的静态成函数或方法
    {
    public:
        ~Garbo()
        {
            std::cout<<" ~Garbo()"<<std::endl;
            if(pdata != nullptr){
                delete pdata;
                pdata = nullptr;
            }
        }
    };
    
    Garbo garbo;
    static int *pdata;
};

int* Sample::pdata = nullptr;

Sample::Sample(const int data)
{
    pdata = new int(data);
    assert(pdata != nullptr);
}

Sample::Sample(const Sample& other)
{
    assert(other.pdata != nullptr);
    pdata = new int(*(other.pdata));
    assert(pdata != nullptr);
}

void Sample::setData(const int data)
{
    if(pdata != nullptr){
        *pdata = data;
    }
}
    
int Sample::getData()const
{
    assert(pdata != nullptr);
    return *pdata;
}

void Sample::display()const
{
    if(pdata == nullptr){
        std::cout<<"pdata = nullptr"<<std::endl;
        return ;
    }
    std::cout<<"*pdata ="<<*pdata<<std::endl;
}

std::ostream& operator <<(std::ostream& os,const Sample& s)
{
    if(s.pdata == nullptr){
        os<<"pdata is nullptr";
    }else{
        os<<"*pdata ="<<*(s.pdata);
    }
    
    return os;
}

#endif //_SAMPLE_H