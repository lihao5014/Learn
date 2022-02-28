#ifndef _SINGLETON_H
#define _SINGLETON_H

#include <QMutex>
#include <QMutexLocker>

template <typename T>
class Singleton
{
public:
    static T* getInstance();
    static void release();   //模板单例不能使用Garbo垃圾回收类,只能手动释放
	
protected:
    Singleton() = default;           //构造函数设置为保护才能保证，即不被外部调用，又可以被子类调用。
    virtual ~Singleton() = default;
	
private:
    Singleton(const Singleton& other) = delete;
    Singleton& operator =(const Singleton& other) = delete;
    
    static QMutex m_mutex;   
    static T* volatile m_instance;
};

template <typename T>
QMutex Singleton<T>::m_mutex;

template <typename T>
T* volatile Singleton<T>::m_instance = nullptr;

template <typename T>
T* Singleton<T>::getInstance()
{
    if(m_instance == nullptr)
	{
        m_mutex.lock();
        if(m_instance == nullptr)
		{
            m_instance = new T();
        }
        m_mutex.unlock();
    }
    
    return m_instance;
}

template <typename T>
void Singleton<T>::release()
{
    if(m_instance != nullptr)
	{
		QMutexLocker locker(&m_mutex);
		if(m_instance != nullptr)
		{
			delete m_instance;
			m_instance = nullptr;
		}
    }
}

#endif //_SINGLETON_H