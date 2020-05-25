#ifndef _IPHONE_H
#define _IPHONE_H

class IPhone
{
public:
	virtual ~IPhone(){};
	virtual void call() = 0;
};

#endif //_IPHONE_H