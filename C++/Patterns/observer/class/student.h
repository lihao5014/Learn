#ifndef _STUDENT_H
#define _STUDENT_H

#include "iobserver.h"

class Student:public IObserver
{
public:
	Student(const char* name,const char* note = nullptr);
	~Student();
	void setName(const char* name);
	const char* getName()const;
	void setNote(const char* note);
	const char* getNote()const;
	virtual void update(const char* note);
private:
	char* name;
	char* note;
};

#endif //_STUDENT_H