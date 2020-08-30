//智能指针（Smart Pointer）是一个用了存储指向动态内存分配对象指针的类。
//简单说来，它本身是一个类，这个类用来存储对象指针。

//智能指针就是具有指针功能，同时提供安全内存回收的一个类。它是用一个对象来对指针进行建模，使之具有指针的特性，
//跟指针具有相同含义->和*操作，并且通过对象的构造函数（获取资源）,析构函数（释放资源）来对资源进行管理，
//从而减少程序员通过new操作获取到的对象生命周期进行管理的负担。

// 运算符->被称为类成员访问运算符，可以被重载。它被定义用于为一个类赋予"指针"行为。
// 即可以使类对象可以通过运算符'->'访问类中的成员函数及成员变量。运算符->重载必须是一个成员函数的形式。
// 而且返回类型必须是指针或者是类的对象。运算符->通常与指针引用运算符*结合使用，用于实现智能指针的功能

#ifndef _AUTO_PTR_H
#define _AUTO_PTR_H

#include <assert.h>

//所有的指针指针都需要实现构造函数、析构函数、拷贝构造函数、重载赋值运算符=、重载指针指向运算符->和重载解引用运算符*
template <typename T>
class Auto_ptr
{
public:
	Auto_ptr(T* ptr);
	~Auto_ptr();
	
	T& operator *()const;     //为了使智能指针与裸指针的使用方式一致，所以必须重载->和*这两个运算符
	T* operator ->()const;    //间接引用运算符->可被定义为一个一元后缀运算符，语句p->func被解释为 (p.operator->())->func。
private:
	Auto_ptr(const Auto_ptr& other);        //为了简单使用、防止多个智能指针管理同一个裸指针造成的野指针问题，所以这里禁用拷贝构造和赋值运算符。
	void operator =(const Auto_ptr& other);
	
	T* ptr;      //智能指针都是使用聚合的方式，来管理一个裸指针的生命周期结束。
};

template <typename T>
Auto_ptr<T>::Auto_ptr(T* ptr):ptr(ptr)
{
	
}

template <typename T>
Auto_ptr<T>::~Auto_ptr()
{
	if(ptr != nullptr)
	{
		delete ptr;
		ptr = nullptr;
	}
}

template <typename T>
T& Auto_ptr<T>::operator *()const
{
	assert(ptr != nullptr);
	return *ptr;
}

template <typename T>
T* Auto_ptr<T>::operator ->()const
{
	assert(ptr != nullptr);
	return ptr;
}

#endif //_AUTO_PTR_H

