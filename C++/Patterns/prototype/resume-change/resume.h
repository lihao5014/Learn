#ifndef _RESUME_H
#define _RESUME_H

#include <string.h>

class Resume
{
public:
	Resume(const char* name,const int age = 0);
	Resume(const Resume& resume);
	virtual ~Resume();
	void setName(const char* name);
	const char* getName()const;
	void setAge(const int age);
	int getAge()const;
	virtual Resume* clone() = 0;
	virtual void show()const = 0;
protected:
	char *m_name;
	int m_age;
};

Resume::Resume(const char* name,const int age)
{	
	if(name == nullptr){
		throw "name = nullptr";
	}
	
	m_name = new char[strlen(name)+1];	
	memset(m_name,0,strlen(m_name)+1);				//构造函数中做输入参数检测需要使用异常
	strcpy(m_name,name);
	m_age = age;
}

Resume::Resume(const Resume& resume)
{
	m_name = new char[strlen(resume.m_name)+1];
	memset(m_name,0,strlen(m_name)+1);
	strcpy(m_name,resume.m_name);
	m_age = resume.m_age;
}

Resume::~Resume()
{
	if(m_name != nullptr)
	{
		delete m_name;
		m_name = nullptr;
	}
}

void Resume::setName(const char* name)
{
	if(name == nullptr){
		throw "name = nullptr";
	}
	
	if(m_name != nullptr)
	{
		delete m_name;
		m_name = nullptr;
	}
	
	m_name = new char[strlen(name)+1];
	memset(m_name,0,strlen(name)+1);
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