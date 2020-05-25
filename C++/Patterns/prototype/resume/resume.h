#ifndef _RESUME_H
#define _RESUME_H

#include <string.h>

#define SIZE 32

class Resume
{
public:
	Resume(const char* name,const int age = 0);
	Resume(const Resume& resume);
	virtual ~Resume(){}
	void setName(const char* name);
	const char* getName()const;
	void setAge(const int age);
	int getAge()const;
	virtual Resume* clone() = 0;
	virtual void show()const = 0;
protected:
	char m_name[SIZE];
	int m_age;
};

Resume::Resume(const char* name,const int age)
{	
	if(name == nullptr || strlen(name) >= SIZE){
		throw "name is illegal!";
	}
	
	memset(m_name,0,SIZE);				//构造函数中做输入参数检测需要使用异常
	strcpy(m_name,name);
	m_age = age;
}

Resume::Resume(const Resume& resume)
{
	memset(m_name,0,SIZE);
	strcpy(m_name,resume.m_name);
	m_age = resume.m_age;
}

void Resume::setName(const char* name)
{
	if(name == nullptr || strlen(name) >= SIZE){
		throw "name is illegal!";
	}
	
	memset(m_name,0,SIZE);
	strcpy(m_name,name);
}

const char* Resume::getName()const
{
	return m_name;
}

void Resume::setAge(const int age)
{
	m_age = age;
}

int Resume::getAge()const
{
	return m_age;
}

#endif //_RESUME_H