#ifndef _SUBJECT_H
#define _SUBJECT_H

#include "observer.h"
#include <list>
#include <iostream>

class Subject
{
public:
	Subject(int state = 0);
	void setState(const int state);
	int getState()const;
	
	void attach(Observer* observer);
	void detach(Observer* observer);
	
	void notify();
private:
	std::list<Observer*> observerList;
	int state;
};

Subject::Subject(int state)
{
	this->state = state;
}

void Subject::setState(const int state)
{
	this->state = state;
}

int Subject::getState()const
{
	return state;
}

void Subject::attach(Observer* observer)
{
	if(observer != NULL){
		observerList.push_back(observer);
	}
}

void Subject::detach(Observer* observer)
{
	if(observer != NULL)
		observerList.remove(observer);
}

void Subject::notify()
{
	std::cout<<"size = "<<observerList.size()<<std::endl;
	std::list<Observer*>::iterator it = observerList.begin();
	while(it != observerList.end()){
		(*it)->update();
		++it;
	}
}

#endif //_SUBJECT_H