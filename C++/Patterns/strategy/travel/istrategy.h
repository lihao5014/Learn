#ifndef _ISTRATEGY_H
#define _ISTRATEGY_H

struct IStrategy
{
	virtual ~IStrategy(){}
	virtual void travel() = 0;
};

#endif //_ISTRATEGY_H