#include "company.h"   //源文件中头文件包含的顺序：源文件所对应的头文件、C标准库文件、C++标准库文件、第三方库头文件、自定义头文件。
#include <iostream>
#include "manager.h"
#include "department.h"

#define _CHANGE_WAY_
#undef _CHANGE_WAY_

using namespace std;

Company::Company(const string& location)
	:location(location)
	,departments{nullptr,nullptr,nullptr,nullptr}
{
	
}

Company::Company(const Company& other)
	:location(other.location)
	,departments{nullptr,nullptr,nullptr,nullptr}
{
	map<int,Manager*>::const_iterator citer = other.leaders.cbegin();
	for(;citer != leaders.cend();++citer)
	{
		if(citer->second != nullptr)
		{
			leaders[citer->first] = new Manager(*(citer->second));
		}
	}
	
	int index = 0;
	for(Department *pdepartment: other.departments)
	{
		if(pdepartment != nullptr)
		{
			departments[index] = new Department(*pdepartment);
		}
	}
}

Company::~Company()
{
	auto iter = leaders.begin();
	while(iter != leaders.end())
	{
		if(iter->second != nullptr)
		{
			delete iter->second;
			iter->second = nullptr;
		}
		++iter;
	}
	leaders.clear();
	
	for(int i=0;i<DEPARTMENT_COUNT;++i)
	{
		if(departments[i] != nullptr)
		{
			delete departments[i];
			departments[i] = nullptr;
		}
	}
}

void Company::setLocation(const string& location)
{
	this->location = location;
}

const string& Company::getLocation()const
{
	return location;
}

#ifndef _CHANGE_WAY_
void Company::registerManager(int telephone,const Manager* pmanager)
{
	if(pmanager == nullptr)
	{
		cout<<"registerManager error: pmanager is null"<<endl;
		return ;
	}
	
	leaders[telephone] = new Manager(*pmanager);
}
#else
void Company::registerManager(int telephone,const Manager* pmanager)
{
	if(pmanager == nullptr)
	{
		cout<<"registerManager error: pmanager is null"<<endl;
		return ;
	}
	
	leaders.insert(pair<int,Manager*>(telephone,new Manager(*pmanager)));
}
#endif

#ifndef _CHANGE_WAY_
void Company::unregisterManager(int telephone)
{
	map<int,Manager*>::iterator iter = leaders.find(telephone);
	if(iter == leaders.end())
	{
		return ;
	}
	
	if(iter->second != nullptr)
	{
		delete iter->second;
		iter->second = nullptr;
	}
	
	leaders.erase(iter);
}
#else
void Company::unregisterManager(int telepthone)
{
	if(leaders.count(telephone) < 1)
	{
		return ;
	}
	
	if(leaders[telephone] != nullptr)
	{
		delete leaders[telephone];
		leaders[telephone] = nullptr;
	}
	
	leaders.erase(telephone);
}
#endif

#ifndef _CHANGE_WAY_
Manager* Company::manager(int telephone)
{
	map<int,Manager*>::iterator iter = leaders.find(telephone);
	if(iter == leaders.end())
	{
		return nullptr;
	}
	
	return iter->second;
}
#else
Manager* Company::manager(int telephone)
{
	if(leaders.count(telephone) == 0)
	{
		return nullptr;
	}
	
	return leaders[telephone];
}
#endif

void Company::registerDepartment(const Department* pdepartment)
{
	if(pdepartment == nullptr)
	{
		cout<<"registerDepartment error: pdepartment is null"<<endl;
		return ;
	}
	
	for(int i=0;i<DEPARTMENT_COUNT;++i)
	{
		if(departments[i] == nullptr)
		{
			departments[i] = new Department(*pdepartment);
			return ;
		}
	}
	
	cout<<"registerDepartment warn: departments is full"<<endl;
}

void Company::unregisterDepartment(const Department* pdepartment)
{
	if(pdepartment == nullptr)
	{
		cout<<"unregisterDepartment error: pdepartment is null"<<endl;
		return ;
	}
	
	for(int i=DEPARTMENT_COUNT;i>0;--i)
	{
		if(departments[i - 1] != nullptr && *departments[i - 1] == *pdepartment)
		{
			delete departments[i - 1];
			departments[i - 1] = nullptr;
			return ;
		}
	}
	
	cout<<"unregisterDepartment warn: departments can't find"<<endl;
}

Department* Company::department(const int index)      //因为department()有可能会返回nullptr，所以使用department()函数返回值时，最好先做判空处理。
{
	if(index < 0 || index >= DEPARTMENT_COUNT)
	{
		cout<<"department error: index is illegal"<<endl;
		return nullptr;
	}
	
	return departments[index];
}

void Company::info()const
{
	cout<<"location: "<<location<<endl;
	
	for(pair<int,Manager*> data: leaders)
	{
		if(data.second != nullptr)
		{
			cout<<"telephone: "<<data.first<<" ,";
			data.second->display();
		}
	}
	
	for(int i=0;i<DEPARTMENT_COUNT;++i)
	{
		if(departments[i] != nullptr)
		{
			departments[i]->detail();
		}
	}
}