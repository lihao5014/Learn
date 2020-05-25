#ifndef _SINGLETON_H
#define _SINGLETON_H

template <class T>
class Singleton
{
public:
    static T& getInstance();
protected:
    Singleton() = default;
    virtual ~Singleton(){}
private:
    Singleton(const Singleton& other) = default;
    Singleton& operator =(const Singleton& other){}
};

template <class T>
T& Singleton<T>::getInstance()
{
    static T instance;
    return instance;
}

#endif //_SINGLETON_H