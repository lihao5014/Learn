#include <iostream>
#include "clazz.h"

using std::string;
using std::list;

Clazz::Clazz(const string& major)
	:major(major)
{
	
}

Clazz::Clazz(const Clazz& other)
	:major(other.major)
	,students(other.students)          //使用std::list的拷贝构造函数
{
	
}

Clazz& Clazz::operator =(const Clazz& other)
{
	major = other.major;
	students = other.students;        //使用std::list的赋值运算符
}

bool Clazz::operator ==(const Clazz& other)
{
	
}

void Clazz::setMajor(const string& major);
string Clazz::getMajor()const;

void Clazz::clearStudent();
void Clazz::addStudent(const Student& student);
bool Clazz::removeStudent(const Student& student);

void Clazz::display()const;