#ifndef _RECRUIT_LIB_H
#define _RECRUIT_LIB_H

#include <iostream>

class Company
{
public:
	virtual ~Company(){}
	void recruit()
	{
		CareerTalk();
		ReceiveResume();
		Interview();
		offer();
	}
protected:
	virtual void CareerTalk()
	{
		std::cout << "Delivery" << std::endl;
	}
	
	virtual void ReceiveResume()
	{
		std::cout << "Receive Resume" << std::endl;
	}
	
	virtual void Interview() = 0;
	virtual void offer() = 0;
};

#endif //_RECRUIT_LIB_H