#include "student.h"    //C++源文件中头文件包含顺序：源文件对应的头文件，C标准库头文件，C++标准库头文件，第三方库头文件，本项目内编写的头文件。
#include <cstdio>
#include <cstring>
#include <cassert>

Student::Student(const char* name,const int age)
{
	if(name == nullptr)
	{
		printf("Student constructor error: name is nullptr\n");
		throw "Student constructor error: name is nullptr";
	}
	
	if(age < 0)
	{
		printf("Student constructor error: age is less than zero\n");
		throw "Student constructor error: age is less than zero";
	}
	
	int len = strlen(name) + 1;
	this->name = new char[len];
	memset(this->name,0,len);
	memcpy(this->name,name,len);
	
	this->age = age;
}

Student::Student(const Student& other)
{
	if(other.name == nullptr)
	{
		printf("Student copy constructor error: other.name is nullptr\n");
		throw "Student copy constructor error: other.name is nullptr";
	}
	
	if(other.age < 0)
	{
		printf("Student copy constructor error: age is less than zero\n");
		throw "Student copy constructor error: age is less than zero";
	}
	
	name = new char[strlen(other.name) + 1];
	strcpy(name,other.name);
	
	age = other.age;
}

//只有指针读写时需要做判空操作，指针delete或者free都不需要做判空操作。
//因为野指针使用name == nullptr不能排除；nullptr指针可以delete或free程序不会崩溃。
Student::~Student()
{
	delete[] name;
}

Student& Student::operator =(const Student& other)
{
	assert(other.name != nullptr);
	assert(other.age >= 0);
	
	delete[] name;             //重新为name分配内存前，先将原来name指针指向的释放掉，以免造成内存泄漏问题
	
	int len = strlen(other.name) + 1;
	name = new char[len];
	memcpy(name,other.name,len);
	
	age = other.age;
	return *this;
}

//因为Student类的构造函数，赋值运算符和setName方法已经保证了，name成员指针不可能为空。
//所以重载等于运算符时，other.name指针可以不用再做判空处理。
bool Student::operator ==(const Student& other)const
{
	if(age == other.age && strcmp(name,other.name) == 0)
	{
		return true;
	}
	return false;
}

void Student::setName(const char* name)
{
	if(nullptr == name)
	{
		printf("setName error: name is nullptr\n");
		return ;
	}
	
	delete[] this->name;
	
	int len = strlen(name) + 1;
	this->name = new char[len];
	memcpy(this->name,name,len);
}

const char* Student::getName()const
{
	return name;
}

void Student::setAge(const int age)
{
	if(0 > age)
	{
		printf("setAge error: age is less than zero\n");
		return ;
	}
	
	this->age = age;
}

int Student::getAge()const
{
	return age;
}

void Student::info()const
{
	if(name == nullptr)        //只有指针读写时需要做判空操作，指针delete或者free都不需要做判空操作。
	{                          //因为野指针name == nullptr不能排除；nullptr指针可以delete或free程序不会崩溃。
		printf("info error: name is nullptr");
		return ;
	}
	
	printf("Student: name =%s, age =%d\n",name,age);
}