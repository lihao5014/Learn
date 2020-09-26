#include <iostream>
#include "teacher.h"

using std::string;
using std::cout;
using std::endl;

Teacher::Teacher(const Sex_t& sex,const string& title)
	:sex(sex)
	,title(title)
{
	
}

Teacher::Teacher(const Teacher& other)
	:sex(other.sex)
	,title(other.title)
{
	
}

Teacher& Teacher::operator =(const Teacher& other)
{
	sex = other.sex;
	title = other.title;
}

bool Teacher::operator ==(const Teacher& other)
{
	return (sex == other.sex) && (title == other.title);
}

void Teacher::setSex(const Sex_t& sex)
{
	this->sex = sex;
}

Sex_t Teacher::getSex()const
{
	return sex;
}

void Teacher::setTitle(const string& title)
{
	this->title = title;
}

string Teacher::getTitle()const
{
	return title;
}

void Teacher::show()const
{
	cout<<"Teacher: sex ="<<sex<<" ,title ="<<title<<endl;
}