#ifndef _CONCRETE_SUBJECT_H
#define _CONCRETE_SUBJECT_H

#include "subject.h"

class ConcreteSubjectA:public Subject
{
public:
	ConcreteSubjectA(int state);
	void attach(Observer* observer);
	void remove(Observer* observer);
	void notify(const int value);
};

class ConcreteSubjectB:public Subject
{
public:
	ConcreteSubjectB(int state);
	void attach(Observer* observer);
	void remove(Observer* observer);
	void notify(const int value);
};

#endif //_CONCRETE_SUBJECT_H