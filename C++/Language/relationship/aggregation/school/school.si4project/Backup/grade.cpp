#include "grade.h"
#include <iostream>
#include "clazz.h"
#include "debug.h"

using namespace std;   //使用using namespace语句打开命名空间最好在源文件中。如果在头文件中使用的话，
                       //当头文件被其他文件包含时，命名空间打开的范围会被持续扩大。

Grade::Grade(int number)
	:number(number)
	,clazzs{nullptr,nullptr,nullptr,nullptr}
{
	Debug("break point2");
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
			clazzs[i] = nullptr;
		}
	}
}

Grade::~Grade()
{
	for(int i=0;i<CLAZZ_COUNT;++i)
	{
		if(clazzs[i] != nullptr)
		{
			delete clazzs[i];
			clazzs[i] = nullptr;
		}
	}
}

Grade& Grade::operator =(const Grade& other)
{
	for(int i=0;i<CLAZZ_COUNT;++i)
	{
		if(clazzs[i] != nullptr)
		{
			delete clazzs[i];        //释放clazzs指针数组中每一个指针变量指向的堆内存
			clazzs[i] = nullptr;
		}
	}
	
	for(int i=0;i<CLAZZ_COUNT;++i)
	{
		if(other.clazzs[i] != nullptr)
		{
			clazzs[i] = new Clazz(*(other.clazzs[i]));   //给clazzs指针数组中的每一个指针变量重新分配内存，并给重新分配的内存赋值
		}
	}
	number = other.number;
	
	return *this;
}

bool Grade::operator ==(const Grade& other)
{
	if(number != other.number)
	{
		return false;
	}
	
	for(int i=0;i<CLAZZ_COUNT;++i)
	{
		if(clazzs[i] == other.clazzs[i])
		{
			continue;
		}
		
		if(clazzs[i] == nullptr || other.clazzs[i] == nullptr)
		{
			return false;
		}
		
		if(*clazzs[i] != *(other.clazzs[i]))
		{
			return false;
		}
	}
	
	return true;
}

void Grade::setNumber(int number)
{
	this->number = number;
}

int Grade::getNumber()const
{
	return number;
}

void Grade::addClazz(Clazz* pclazz)
{
	if(pclazz == nullptr)      //不加pclazz是否为空指针判断也没有关系，只是加上可以减少pclass == nullptr时，接下来的无效循环
	{
		return ;
	}
	
	for(int i=0;i<CLAZZ_COUNT;++i)
	{
		if(clazzs[i] == nullptr)
		{
			Debug("break point3");
			clazzs[i] = pclazz;     //使用浅拷贝实现addClazz方法，所以传入的Clazz实参指针的内存释放由Grade类来自动管理，而不需要由用户来手动管理
			return ;                //一次只添加一个pclazz指针
		}
	}
}   

void Grade::removeClazz(const Clazz* pclazz)    //一次移除所有与*pclazz相同的Clazz对象
{
	if(pclazz == nullptr)
	{
		return ;
	}
	
	for(int i=0;i<CLAZZ_COUNT;++i)
	{
		if(clazzs[i] != nullptr && *clazzs[i] == *pclazz)
		{
			delete clazzs[i];
			clazzs[i] = nullptr;
		}
	}
}

Clazz* Grade::getClazz(int index)
{
	if(index < 0 || index >= CLAZZ_COUNT)
	{
		cout<<"Grade getClazz error: index is illegal"<<endl;
		return nullptr;
	}
	
	return clazzs[index];
}  

void Grade::print()const
{
	cout<<"Grade: number ="<<number<<endl;
	
	for(int i=0;i<CLAZZ_COUNT;++i)
	{
		if(clazzs[i] != nullptr)
		{
			clazzs[i]->display();
		}
	}
}