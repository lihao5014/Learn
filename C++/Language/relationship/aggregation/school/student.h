#ifndef _STUDENT_H
#define _STUDENT_H

#include <cstdio>
#include <cstring>
#include <cassert>

class Student
{
public:
	Student(const char* name,const int number);
	Student(const Student& other);
	virtual ~Student();
	
	Student& operator =(const Student& other);
	bool operator ==(const Student& other)const;
	
	void setName(const char* name);
	const char* getName()const;
	
	void setNumber(const int number);
	int getNumber()const;
	
	void show()const;
private:
	char *name;
	int number;
};

Student::Student(const char* name,const int number)
{
	if(name == nullptr)
	{
		printf("Student constructor error: name is nullptr\n");
		throw "Student constructor error: name is nullptr";
	}
	
	if(number < 0)
	{
		printf("Student constructor error: number is less than zero\n");
		throw "Student constructor error: number is less than zero";
	}
	
	int len = strlen(name) + 1;
	this->name = new char[len];
	memset(this->name,0,len);
	memcpy(this->name,name,len);
	
	this->number = number;
}

Student::Student(const Student& other)
{
	if(other.name == nullptr)
	{
		printf("Student copy constructor error: other.name is nullptr\n");
		throw "Student copy constructor error: other.name is nullptr";
	}
	
	if(other.number < 0)
	{
		printf("Student copy constructor error: number is less than zero\n");
		throw "Student copy constructor error: number is less than zero";
	}
	
	name = new char[strlen(other.name) + 1];
	strcpy(name,other.name);
	
	number = other.number;
}

//只有指针读写时需要做判空操作，指针delete或者free都不需要做判空操作。
//因为野指针name == nullptr不能排除；nullptr指针可以delete或free程序不会崩溃。
Student::~Student()
{
	delete[] name;
}

Student& Student::operator =(const Student& other)
{
	assert(other.name != nullptr);
	assert(other.number >= 0);
	
	int len = strlen(other.name) + 1;
	name = new char[len];
	memcpy(name,other.name,len);
	
	number = other.number;
	return *this;
}

bool Student::operator ==(const Student& other)const
{
	if(number == other.number && strcmp(name,other.name) == 0)
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

void Student::setNumber(const int number)
{
	if(0 > number)
	{
		printf("setNumber error: number is less than zero\n");
		return ;
	}
	
	this->number = number;
}

int Student::getNumber()const
{
	return number;
}

void Student::show()const
{
	if(name == nullptr)        //只有指针读写时需要做判空操作，指针delete或者free都不需要做判空操作。
	{                          //因为野指针name == nullptr不能排除；nullptr指针可以delete或free程序不会崩溃。
		printf("show error: name is nullptr");
		return ;
	}
	
	printf("name =%s, number =%d\n",name,number);
}

#endif //_STUDENT_H