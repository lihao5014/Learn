#ifndef _NONCOPYABLE_H
#define _NONCOPYABLE_H

class Noncopyable
{
protected:
    Noncopyable() = default;
    virtual ~Noncopyable() = default;

    Noncopyable(const Noncopyable&) = delete;               //使派生自Noncopyable的类不能自动生成默认拷贝构造函数
    Noncopyable& operator =(const Noncopyable&) = delete;   //使派生自Noncopyable的类不能自动生成默认赋值运算符
};

#endif //_NONCOPYABLE_H