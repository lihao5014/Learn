#include "clazz.h"
#include <cstdlib>
#include <iostream>

using std::string;
using std::list;
using std::cout;
using std::endl;

Clazz::Clazz(const string& major)
	:major(major)
	,advisor(nullptr)
{
	
}

Clazz::Clazz(const Clazz& other)
	:major(other.major)
	,students(other.students)    //使用std::list的拷贝构造函数
{
	if(other.advisor != nullptr)
	{
		advisor = new Teacher(*other.advisor);
	}
	else                         //因为构造函数中不能提前return，所以这里的else必须加上，不能省略
	{
		advisor = nullptr;
	}
}

Clazz::~Clazz()
{
	if(advisor != nullptr)
	{
		delete advisor;
		advisor = nullptr;
	}
}

Clazz& Clazz::operator =(const Clazz& other)
{
	delete advisor;
	
	if(other.advisor != nullptr)
	{
		advisor = new Teacher(*(other.advisor));
	}
	else
	{
		advisor = nullptr;
	}
	
	major = other.major;
	students = other.students;        //使用std::list的赋值运算符
	
	return *this;
}

bool Clazz::operator ==(const Clazz& other)
{
	if(major != other.major || students != other.students)   //取反退出，减少if语句的嵌套。==取反是!=,&&取反是||
	{
		return false;
	}
	
	if(advisor == other.advisor)
	{
		return true;
	}
	
	if(advisor == nullptr || other.advisor == nullptr)
	{
		return false;
	}
	
	if(*advisor == *(other.advisor))
	{
		return true;
	}
	
	return false;
}

bool Clazz::operator !=(const Clazz& other)
{
	return !(*this == other);
}

void Clazz::setMajor(const string& major)
{
	this->major = major;
}

string Clazz::getMajor()const
{
	return major;
}

void Clazz::setAdvisor(Teacher* advisor)
{
	if(advisor == nullptr)       //逻辑上是可以不用做判空处理，因为构造函数中也将advisor初始化为了nullptr，
	{                            //说明Clazz类中的advisor属性是可以为nullptr的。
		cout<<"setAdvisor warn: advisor is nullptr"<<endl;
		return ;
	}
	this->advisor = advisor;     //使用浅拷贝
}

Teacher* Clazz::getAdvisor()
{
	return advisor;
}

void Clazz::addStudent(const Student& student)
{
	students.push_back(student);
}

//list的remove和erase的区别是，remove方法需要模板参数类支持==运算符，
//而erase方法不需要，它是通过迭代器位置去擦除的
void Clazz::removeStudent(const Student& student)
{
	students.remove(student);
}

void Clazz::clearStudent()
{
	students.clear();
}

Student& Clazz::getStudent(int index)
{
	if(index < 0 || index >= students.size())
	{
		cout<<"getStudent error: index is out of list range"<<endl;
		abort();
	}
	
	list<Student>::iterator iter = students.begin();
	while(index--)
	{
		iter++;
	}
	
	return *iter;
}

void Clazz::display()const
{
	cout<<"Clazz: major ="<<major<<endl;
	
	if(advisor != nullptr)
	{
		advisor->show();
	}
	
	for(auto student: students)
	{
		student.info();
	}
}