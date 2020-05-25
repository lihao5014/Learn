#ifndef _BIRD_H
#define _BIRD_H

#include "animal.h"

class Bird:public Animal
{
public:
	Bird(const string& name,int age);
	Bird(const Bird& other);
	virtual ~Bird();
	
	virtual void move()const;
};

Bird::Bird(const string& name,const int age)
	:Animal(name,age)
{
	
}
	
Bird::Bird(const Bird& other)
	:Animal(other.name,other.age)
{
		
}
	
Bird::~Bird()
{
	
}
	
void Bird::move()const
{
	cout<<"bird can fly"<<endl;
}

#endif //_BIRD_H