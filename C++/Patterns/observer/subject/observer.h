#ifndef _OBSERVER_H
#define _OBSERVER_H

class Subject;

class Observer
{
public:
	virtual ~Observer(){};
	virtual void update() = 0;
protected:
	Subject* subject;
};

#endif //_OBSERVER_H