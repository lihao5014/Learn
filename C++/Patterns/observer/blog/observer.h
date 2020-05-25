#ifndef _OBSERVER_H
#define _OBSERVER_H

class Observer
{
public:
	virtual ~Observer(){}
	virtual void update() = 0;
};

#endif //_OBSERVER_H