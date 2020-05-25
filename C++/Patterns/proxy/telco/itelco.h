#ifndef _ITECLO_H
#define _ITECLO_H

class ITelco
{
public:
	virtual ~ITelco(){}
	virtual void recharge(int money) = 0;
};

#endif //_ITECLO_H