#ifndef _MOBILE_H
#define _MOBILE_H

#include "itelco.h"
#include <iostream>

class Mobile:public ITelco
{
public:
	void recharge(int money)override
	{
		std::cout << "Mobile recharge :" <<money<<std::endl;
	}
};

class MobileProxy:public ITelco
{
public:
	MobileProxy():mobile(nullptr)
	{
		
	}
	
	~MobileProxy()
	{
		if(mobile != nullptr)
		{
			delete mobile;
			mobile = nullptr;
		}
	}
	
	virtual void recharge(int money)
	{
		std::cout <<"MobileProxy recharge :"<<money<< std::endl;
		if(money >= 50){
			if(mobile == nullptr){
				mobile = new Mobile();
				mobile->recharge(money);
			}
		}else{
			std::cout << "Sorry, too little money" << std::endl;
		}
	}	
private:
	Mobile* mobile;
};

#endif  //_MOBILE_H