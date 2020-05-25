#ifndef _CHILD_H
#define _CHILD_H

#include "parent.h"

typedef enum Sex_t
{
	BOY,
	GIRL
}Sex;

class Child:public Parent
{
public:
	Child(const std::string name = "",const int age = 0,const Sex sex = BOY);
	Child(const Child& other);
	virtual ~Child();
	
	void setSex(const Sex sex);
	Sex getSex()const;
	
	void show()override;
private:
	Sex sex;
};

Child::Child(const std::string name,int age,const Sex sex)
	:Parent(name,age)
	,sex(sex)
{
	
}

Child::Child(const Child& other)
	:Parent(other)
	,sex(other.sex)
{
	
}

Child::~Child()
{
	
}

void Child::setSex(const Sex sex)
{
	this->sex = sex;
}

Sex Child::getSex()const
{
	return sex;
}

void Child::show()
{
	Parent::show();
	
	std::string strSex = (sex == BOY ? "boy" : "girl");
	cout<<"sex ="<<strSex<<endl;
}

#endif //_CHILD_H