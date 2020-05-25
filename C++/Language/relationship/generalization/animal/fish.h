#ifndef _FISH_H
#define _FISH_H

#include "animal.h"

#define _ERROE_
#undef _ERROE_

class Fish:public Animal
{
public:
	Fish(const string& name,const int age);
	Fish(const Fish& other);
	virtual ~Fish();
	
	void move()const override;
};

#ifdef _ERROE_
Fish::Fish(const string& name,int age)       //没有调用父类构造函数，构造父对象
	:name(name)
	,age(age)
{
	
}

Fish::Fish(const Fish& other)
	:name(other.name)
	,age(other.age)
{
	
}
#else
Fish::Fish(const string& name,const int age)
	:Animal(name,age)
{
	
}

Fish::Fish(const Fish& other)
	:Animal(other.name,other.age)
{
	
}	
#endif

Fish::~Fish()
{
	
}
	
void Fish::move()const
{
	cout<<"bird can swim"<<endl;
}

#endif //_FISH_H