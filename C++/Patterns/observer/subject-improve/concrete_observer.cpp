#include "concrete_observer.h"
#include "subject.h"
#include <iostream>

ConcreteObserverA::ConcreteObserverA(const int value)
{
	this->value = value;
	this->subject = nullptr;
}

ConcreteObserverA::ConcreteObserverA(Subject* subject,const int value)
{
	this->value = value;
	this->subject = subject;
	this->subject->attach(this);
}

void ConcreteObserverA::update(int value)
{
	this->value = value;
	std::cout<<"ConcreteObserverA : update value ="<<value<<std::endl;
}

ConcreteObserverB::ConcreteObserverB(const int value)
{
	this->value = value;
	this->subject = nullptr;
}

ConcreteObserverB::ConcreteObserverB(Subject* subject,const int value)
{
	this->value = value;
	this->subject = subject;
	this->subject->attach(this);
}

void ConcreteObserverB::update(int value)
{
	this->value = value;
	std::cout<<"ConcreteObserverB : update value ="<<value<<std::endl;
}