#include "school.h"
#include <iostream>
#include "grade.h"

using namespace std;

School::School(const string& address)
	:address(address)
	,grades{nullptr,nullptr,nullptr}
{
	
}

School::School(const School& other)
	:address(address)
{
	for(int i=0;i<GRADE_COUNT;++i)
	{
		if(other.grades[i] != nullptr)
		{
			grades[i] = new Grade(*(other.grades[i]));
		}
		else
		{
			grades[i] = nullptr;
		}
	}
}

School::~School()
{
	array<Grade*,GRADE_COUNT>::iterator iter = grades.begin();   //array可以使用迭代器、[]和at()访问
	while(iter != grades.end())
	{
		if(*iter != nullptr)
		{
			delete *iter;
			*iter = nullptr;
		}
		++iter;
	}
}

void School::setAddress(const string& address)
{
	this->address = address;
}

string School::getAddress()const
{
	return address;
}

void School::addGrade(const Grade* pgrade)
{
	if(pgrade == nullptr)       //不加pgrade == nullptr判断也没有关系，不会导致软件崩溃，
	{                           //因为School构造函数也将grades数组初始化为nulltr，只是加上可以减少接下来的无效循环。
		return ;
	}
	
	for(int i=0;i<GRADE_COUNT;++i)
	{
		if(grades.at(i) == nullptr)
		{
			grades.at(i) = new Grade(*pgrade);   //使用深拷贝实现addGrade()方法，所以传入的Grade实参指针的内存需要由用户手动释放。
			return ;
		}
	}
}

void School::removeGrade(const Grade* pgrade)    //一次移除一个与*pgrade相同的Grade对象
{
	if(pgrade == nullptr)
	{
		return ;
	}
	
	array<Grade*,GRADE_COUNT>::iterator iter = grades.begin();
	for(;iter != grades.end();++iter)
	{
		if(*iter != nullptr && **iter == *pgrade)
		{
			delete *iter;
			*iter = nullptr;
			return ;
		}
	}
	
}

Grade* School::getGrade(const int index)
{
	if(index < 0 || index >= GRADE_COUNT)
	{
		cout<<"School getGrade error: index is illegal"<<endl;
		return nullptr;
	}
	
	return grades[index];
}

void School::detail()const
{
	cout<<"School: address ="<<address<<endl;
	
	for(auto pgrade: grades)
	{
		if(pgrade != nullptr)
		{
			pgrade->print();
		}
	}
}