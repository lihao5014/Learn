#include "employee.h"
#include <iostream>
#include "date.h"

#define _CHANGE_WAY_
// #undef _CHANGE_WAY_

using std::cout;
using std::endl;
using std::cin;

Employee::Employee(int number)
	:pbirthday(nullptr)
	,number(number)
{
	
}

#ifndef _DEEPLY_COPY_
Employee::Employee(int number,Date* pbirthday)
	:number(number)
	,pbirthday(pbirthday)
{
	
}
#else
Employee::Employee(int number,Date* pbirthday)
	:number(number)
	,pbirthday(nullptr)
{
	if(pbirthday != nullptr)
	{
		this->pbirthday = new Date(*pbirthday);
	}
}
#endif

#ifndef _DEEPLY_COPY_
Employee::Employee(const Employee& other)
	:number(other.number)
	,pbirthday(other.pbirthday)
{
	
}
#else
Employee::Employee(const Employee& other)
	:number(other.number)
{
	if(other.pbirthday == nullptr)
	{
		pbirthday = other.pbirthday;
	}
	else
	{
		pbirthday = new Date(*(other.pbirthday));   //拷贝构造函数中的pbirthday成员指针不能使用浅拷贝实现。因为如果使用浅拷贝实现，则会造成拷贝后的
	}                                               //两个Employee对象析构时，先后释放同一个pbirthday指针的地址。导致同一个指针两次delete问题?
}
#endif

#ifndef _DEEPLY_COPY_
Employee& Employee::operator =(const Employee& other)
{
	number = other.number;
	pbirthday = other.pbirthday;
	return *this;
}
#else
Employee& Employee::operator =(const Employee& other)
{
	number = other.number;
	if(pbirthday != nullptr)
	{
		delete pbirthday;
		pbirthday = nullptr;
	}
	
	if(other.pbirthday != nullptr)
	{
		pbirthday = new Date(*(other.pbirthday));
	}
	
	return *this;
}
#endif

Employee::~Employee()
{
#ifndef _CHANGE_WAY_
	if(pbirthday != nullptr)
	{
		delete pbirthday;
		pbirthday = nullptr;
	}
#else
	delete pbirthday;
#endif
}

bool Employee::operator ==(const Employee& other)
{
	if(number == other.number)
	{
		if(pbirthday == other.pbirthday)
		{
			return true;
		}
		
		if(pbirthday == nullptr || other.pbirthday == nullptr)
		{
			return false;
		}
		
		return *pbirthday == *(other.pbirthday);
	}
	
	return false;
}

void Employee::release(ReleaseType type)
{
	if(type != DELETE_POINTER && type != SET_NULLPTR)
	{
		cout<<"release error: release type is illegal"<<endl;
		return ;
	}
	
	if(type == SET_NULLPTR)
	{
		pbirthday = nullptr;
		return ;
	}
	
#ifndef _CHANGE_WAY_
	if(pbirthday != nullptr)
	{
		delete pbirthday;
		pbirthday = nullptr;
	}
#else
	delete pbirthday;        //在delete指针前可以不用做判空处理，因为nullptr指针也可以delete，而野指针也满足不为nullptr情况
	pbirthday = nullptr;     //防止pbirthday指针变为野指钿
#endif
}

#ifndef _DEEPLY_COPY_
void Employee::setBirthday(Date* pbirthday)
{
	this->pbirthday = pbirthday;      //使用浅拷贝实现类的set方法
}
#else     //_DEEPLY_COPY_
#ifndef _CHANGE_WAY_
void Employee::setBirthday(const Date* pbirthday)   //先将pbirthday成员指针的内存释放掉，再重新分配内存空间
{
	if(this->pbirthday != nullptr)
	{
		delete this->pbirthday;
		this->pbirthday = nullptr;
	}
	
	if(pbirthday != nullptr)
	{
		this->pbirthday = new Date(*pbirthday);   //使用深拷贝实现类的set方法
	}
}
#else     //_CHANGE_WAY_
void Employee::setBirthday(const Date* pbirthday)   //如果pbirthday成员指针不为空时，直接在它指向的内存上覆盖。这样可以减少不必要的内存申请和释放时开销?
{
	if(pbirthday == nullptr)
	{
		if(this->pbirthday != nullptr)
		{
			delete this->pbirthday;	
			this->pbirthday = nullptr;
		}
		return ;
	}

	if(this->pbirthday == nullptr)
	{
		this->pbirthday = new Date(*pbirthday);   //使用深拷贝实现类的set方法
		return ;
	}
	
	*(this->pbirthday) = *pbirthday;
}
#endif    //_CHANGE_WAY_
#endif    //_DEEPLY_COPY_

Date* Employee::getBirthday()  //用户使用getBirthday()返回的指针前最好先做判空处理，因为它有可能返回nullptr指针
{
	return pbirthday;
}

void Employee::setNumber(const int number)
{
	this->number = number;
}

int Employee::getNumber()const
{
	return number;
}

void Employee::show()const
{
	if(pbirthday != nullptr)
	{
		cout<<"birthday ="<<*pbirthday<<" ,";
	}
	
	cout<<"number ="<<number<<endl;
}
