#include <iostream>
#include "grade.h"
#include "clazz.h"

using namespace std;   //使用using namespace语句打开命名空间最好在源文件中。如果在头文件中使用的话，
                       //当头文件被其他文件包含时，命名空间打开的范围会被持续扩大。

Grade::Grade(int number)
	:number(number)
	,clazzs{nullptr,nullptr,nullptr,nullptr}
{
	
}

Grade::Grade(const Grade& other)
	:number(other.number)
{
	for(int i=0;i<CLAZZ_COUNT;++i)
	{
		if(other.clazzs[i] != nullptr)
		{
			clazzs[i] = new Clazz(*(other.clazzs[i]));
		}
		else
		{
			clazz[i] = nullptr;
		}
	}
}

Grade::~Grade()
{
	
}

void Grade::setNumber(int number)
{
	
}

void Grade::getNumber()const;

void Grade::addClazz(Clazz* pclazz);          
void Grade::removeClazz(const Clazz* pclazz);
Clazz* Grade::getClazz(int index);            

void Grade::display()const;