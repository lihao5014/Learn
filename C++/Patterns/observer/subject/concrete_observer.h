#ifndef _CONCERET_OBSERVER_H
#define _CONCERET_OBSERVER_H

#include "observer.h"
#include "subject.h"
#include <iostream>

class BinaryObserver:public Observer
{
public:
	BinaryObserver(Subject* subject)
	{ 
		this->subject = subject;
		this->subject->attach(this);
	}
	
	void update()
	{
		std::cout<<"Binary observer update! Subject state: "
			<<subject->getState()<<std::endl;
	}
};

class OctalObserver:public Observer
{
public:
	OctalObserver(Subject* subject)
	{
		this->subject = subject;
		this->subject->attach(this);
	}
	
	void update()
	{
		std::cout<<"Octal observer update! Subject state: "
			<<subject->getState()<< std::endl;
	}
};

class HexaObserver:public Observer
{
public:
	HexaObserver(Subject* subject)
	{
		this->subject = subject;
		this->subject->attach(this);
	}
	
	void update()
	{
		std::cout<<"Hexa observer update! Subject state: "
			<<subject->getState()<< std::endl;
	}
};

#endif //_CONCERET_OBSERVER_H