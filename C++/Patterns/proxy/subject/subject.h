#ifndef _SUBJECT_H
#define _SUBJECT_H

class Subject
{
public:
	virtual ~Subject(){}
	virtual void request() = 0;
};

#endif //_SUBJECT_H