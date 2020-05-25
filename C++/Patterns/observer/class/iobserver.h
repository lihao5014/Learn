#ifndef _IOBSERVER_H
#define _IOBSERVER_H

class ISubject;

class IObserver
{
public:
	virtual ~IObserver(){}
	virtual void update(const char* note) = 0;
};

#endif //_IOBSERVER_H