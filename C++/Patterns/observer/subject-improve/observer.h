#ifndef _OBSERVER_H
#define _OBSERVER_H

class Subject;

class Observer
{
public:
	virtual ~Observer(){}
	void setValue(const int value){this->value = value;}
	int getValue()const{return value;}
	void setSubject(Subject* subject){this->subject = subject;}
	Subject* getSubject(){return subject;}
	virtual void update(int value) = 0;
protected:
	int value;
	Subject* subject;
};

#endif //_OBSERVER_H