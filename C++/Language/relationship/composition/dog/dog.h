#ifndef _DOG_H
#define _DOG_H

#include "tail.h"
#include "eye.h"
#include "leg.h"

class Dog
{
public:
	Dog(const char* shape,const string& color,int length);
	Dog(const Dog& other);
	~Dog();
	
	void detail()const;
private:
	Tail *tail;                //如果对象指针成员变量，在构造函数中new，在析构函数中delete，则就构成了组合关系
	Eye *eyes[2];              //如果对象指针成员变量，不在构造函数中new出来，或者不在析构函数中delete，则就构成了聚合关系
	Leg *legs[4];
};

Dog::Dog(const char* shape,const string& color,int length)
	:tail(new Tail(shape))
	,eyes{new Eye(color),nullptr}
	,legs{new Leg(length),new Leg(length),nullptr,nullptr}
{
	eyes[1] = new Eye("blue");
	legs[2] = new Leg(length + 4);
	legs[3] = new Leg(length + 4);
}

Dog::Dog(const Dog& other)
	:tail(new Tail(*(other.tail)))
	,eyes{new Eye(*(other.eyes[0])),new Eye(*(other.eyes[1]))}
	,legs{
		new Leg(*(other.legs[0])),
		new Leg(*(other.legs[1])),
		new Leg(*(other.legs[2])),
		new Leg(*(other.legs[3]))
	}
{
	tail =  new Tail("long");
}

Dog::~Dog()
{
	if(tail != nullptr)
	{
		delete tail;
		tail = nullptr;
	}
	
	eyes[0] == nullptr ? (void)0 : delete eyes[0];
	eyes[1] == nullptr ? (void)0 : delete eyes[1];
	
	for(int i=0;i<4;++i)
	{
		if(legs[i] != nullptr)
		{
			delete legs[i];
			legs[i] = nullptr;
		}
	}
}

void Dog::detail()const
{
	tail == nullptr ? (void)0 : tail->display();
	eyes[0] == nullptr ? (void)0 : eyes[0]->show();
	eyes[1] == nullptr ? (void)0 : eyes[1]->show();
	
	for(int i=0;i<4;++i)
	{
		if(legs[i] != nullptr)
		{
			legs[i]->print();
		}
	}
}

#endif //_DOG_H