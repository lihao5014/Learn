#ifndef _ISUBJECT_H
#define _ISUBJECT_H

#include <list>

class IObserver;

class ISubject
{
public:
	virtual ~ISubject(){}
	virtual void attach(IObserver* observer) = 0;
	virtual void detach(IObserver* observer) = 0;
	virtual void notify() = 0;
protected:
	std::list<IObserver*> observerList;
};

#endif //_ISUBJECT_H