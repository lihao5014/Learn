#ifndef _CONCRETE_OBSERVER_H
#define _CONCRETE_OBSERVER_H

#include "observer.h"

class ConcreteObserverA:public Observer
{
public:
	ConcreteObserverA(const int value);
	ConcreteObserverA(Subject* subject,const int value = 0);
	void update(int value);
};

class ConcreteObserverB:public Observer
{
public:
	ConcreteObserverB(const int value);
	ConcreteObserverB(Subject* subject,const int value = 0);
	void update(int value);
};

#endif //_CONCRETE_OBSERVER_H