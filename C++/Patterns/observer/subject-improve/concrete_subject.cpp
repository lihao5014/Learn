#include "concrete_subject.h"
#include "observer.h"
#include <iostream>

ConcreteSubjectA::ConcreteSubjectA(int state)
{
	this->state = state;
}

void ConcreteSubjectA::attach(Observer* observer)
{
	if(observer != NULL)
		observerList.push_back(observer);
}

void ConcreteSubjectA::remove(Observer* observer)
{
	if(observer != NULL)
		observerList.remove(observer);	
}

void ConcreteSubjectA::notify(const int value)
{
	std::cout<<"ConcreteSubjectA notify"<<std::endl;
	std::list<Observer*>::iterator it = observerList.begin();
	while(it != observerList.end()){
		(*it)->update(value);
		++it;
	}
}

ConcreteSubjectB::ConcreteSubjectB(int state)
{
	this->state = state;
}


void ConcreteSubjectB::attach(Observer* observer)
{
	if(observer != NULL)
		observerList.push_back(observer);
}

void ConcreteSubjectB::remove(Observer* observer)
{
	if(observer != NULL)
		observerList.remove(observer);	
}

void ConcreteSubjectB::notify(const int value)
{
	std::cout<<"ConcreteSubjectB notify"<<std::endl;
	for(auto pobserver:observerList){
		pobserver->update(value);
	}
}
