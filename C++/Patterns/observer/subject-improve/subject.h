#ifndef _SUBJECT_H
#define _SUBJECT_H

#include <list>

class Observer;

class Subject
{
public:
	virtual ~Subject(){}
	void setState(const int state){this->state = state;}
	int getState()const{return state;}
	virtual void attach(Observer* observer) = 0;
	virtual void remove(Observer* observer) = 0;
	virtual void notify(int value) = 0;
protected:
	int state;
	std::list<Observer*> observerList;
};

#endif //_SUBJECT_H