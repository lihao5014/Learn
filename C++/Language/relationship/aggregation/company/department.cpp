#include "department.h"
#include <stdio.h>        //因为使用了char*作为字符串，所以包含C语言的头文件以处理C风格的字符串。
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define _CHANGE_WAY_
#undef _CHANGE_WAY_

using std::cout;
using std::endl;

Department::Department(const char* name)
{
	if(name == NULL)
	{
		printf("Department construct error: name is null\n");
		throw "Department construct error: name is null";
	}
	
	int len = strlen(name) + 1;
	this->name = (char*)malloc(len);     //为name成员指针开辟内存空间，并将开辟的内存空间中的内容马上清空。
	memset(this->name,0,len);
	strcpy(this->name,name);
}

Department::Department(const Department& other)
	:name(NULL)
	,managers(other.managers)
	,employees(other.employees)
{
	if(other.name == NULL)
	{
		fprintf(stdout,"Department copy construct error: name is null\n");
		throw "Department copy construct error: name is null";
	}
	
	int len = strlen(other.name) + 1;
	this->name = (char*)malloc(len);
	memcpy(this->name,other.name,len);
}

#ifndef _CHANGE_WAY_
Department::~Department()
{
	if(name != NULL)
	{
		free(name);
		name = NULL;
	}
}
#else
Department::~Department()
{                 //析构函数中释放成员指针，可以不用做判空和置空处理。因为NULL指针也可以free。
	free(name);   //析构完成以后成员指针就不存在了，所以也不用做置空处理，因为其不能再被使用了。
}
#endif

bool Department::operator ==(const Department& other)    //只要两个Departmentd对象的名字相同，就认为它们两个相等，
{                                                        //而不再继续去比较它们之间的managers和employees是否相同。
	if(name == other.name)
	{
		return true;
	}
	
	if(name == nullptr || other.name == nullptr)
	{
		return false;
	}
	
	return strcmp(name,other.name) == 0;
}

void Department::setName(const char* name)
{
	if(NULL == name)
	{
		puts("setName error: name is null");
		return ;
	}
	
	if(this->name != NULL)
	{
		free(this->name);
		this->name = NULL;
	}
	
	this->name = (char*)malloc(strlen(name) + 1);
	memcpy(this->name,name,strlen(name) + 1);
}

const char* Department::getName()const
{
	return name;
}

#ifndef _CHANGE_WAY_
void Department::addManager(const string& position,const Manager& manager)
{
	if(position.empty())
	{
		fputs("addManager error: position is empty",stdout);
		return ;
	}
	
	managers.insert(std::pair<string,Manager>(position,manager));
}
#else
void Department::addManager(const string& position,const Manager& manager)
{
	if(position.empty())
	{
		fputs("addManager error: position is empty",stdout);
		return ;
	}
	
	managers[position] = manager;
}
#endif

#ifndef _CHANGE_WAY_
void Department::removeManager(const string& position)
{
	if(position.empty())
	{
		fputs("removeManager error: position is empty",stdout);
		return ;
	}
	
	managers.erase(position);
}
#else
void Department::removeManager(const string& position)
{
	if(position.empty())
	{
		fputs("removeManager error: position is empty",stdout);
		return ;
	}
	
	map<string,Manager>::iterator iter = managers.find(position);
	if(iter != managers.end())
	{
		managers.erase(iter);
	}
}
#endif

#ifndef _CHANGE_WAY_
Manager& Department::getManager(const string& position)
{
	if(managers.count(position) == 0)
	{
		fprintf(stdout,"getManager error: %s is can't find in managers keys",position.c_str());
	}
	
	return managers[position];   //如果position在managers的key中找不到的话，则会先在managers中先插入一个key为position，value为Manager默认构造对象的键值对。
}
#else
Manager& Department::getManager(const string& position)
{
	map<string,Manager>::iterator iter = managers.find(position);
	if(iter == managers.end())
	{
		fprintf(stdout,"getManager error: %s is can't find in managers keys",position.c_str());
		abort();
	}
	
	return iter->second;
}
#endif

#ifndef _CHANGE_WAY_
void Department::addEmployee(const Employee& employee)
{
	employees.push_back(employee);   //向vector后面追加数据的速度很快，但是vector前面插入数据的速度很慢。因为在vector前面插入数据会造成内存移动的现象。
}
#else
void Department::addEmployee(const Employee& employee)
{
	vector<Employee>::iterator iter = employees.begin();  //将employee对象放置到vector容器的前面，只有使用insert实现。std::vector没有提供prepend或者push_front方法
	employees.insert(iter,employee);    //如果数据项要从前面插入到vector中，那么数据项类必须实现拷贝构造函数和赋值运算符。如果不实现赋值运算符可能会造成意想不到的结果。
}
#endif

void Department::removeEmployee(const Employee& employee)
{
	vector<Employee>::iterator iter = employees.begin();
	while(iter != employees.end())
	{
		if(*iter == employee)
		{
#ifndef _CHANGE_WAY_
			iter->release(DELETE_POINTER);      //即使不手动清除Employee对象中pbirthday指针的内存，Employee对象析构的时候也会自动释放pbirthday指针内存
#endif
			employees.erase(iter);     //array、vector和map都没有remove方法，只有list有remove方法。
			return ;                   //如果不加return语句，那么employees容器中的所有与参数employee相等的对象，都会被删除。
		}
		++iter;
	}
}

#ifndef _CHANGE_WAY_
Employee& Department::getEmployee(const int index)
{
	assert(index >= 0 && index < employees.size());

	return employees[index];
}
#else
Employee& Department::getEmployee(const int index)
{
	if(index < 0 || index >= employees.size())
	{
		puts("getEmployee error: index is illegal");
		throw "getEmployee error: index is illegal";
	}
	
	return employees.at(index);
}
#endif

void Department::detail()const
{
	if(NULL != name)
	{
		printf("department name: %s\n",name);
	}
	
	for(auto citer = managers.cbegin();citer != managers.cend();++citer)      //使用迭代器时，最好使用auto关键字来进行类型推导。这样可以使代码更加简洁。
	{
		cout<<"position: "<<citer->first<<" ,manager("<<citer->second<<")"<<endl;    //std::string类型不能使用printf进行输出，只能使用std::cout进行输出。
	}
	
	for(Employee employee: employees)
	{
		employee.show();
	}
}
