#ifndef _TEACHER_H
#define _TEACHER_H

#include "ISubject.h"

class Teacher:public ISubject
{
public:
	Teacher(const char* context);
	~Teacher();
	void setContext(const char* context);
	const char* getContext()const;
	void attach(IObserver* observer);
	void detach(IObserver* observer);
	void notify();
private:
	char* context;
};

#endif //_TEACHER_H