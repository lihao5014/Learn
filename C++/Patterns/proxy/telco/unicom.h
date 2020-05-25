#ifndef _UNICOM_H
#define _UNICOM_H

#include "itelco.h"

class Unicom:public ITelco
{
public:
	void recharge(int money)final
	{
		std::cout << "Unicom recharge :" <<money<<std::endl;
	}
};

class UnicomProxy:public ITelco
{
public:
	UnicomProxy():unicom(nullptr)
	{
		
	}
	
	~UnicomProxy()
	{
		if(unicom != nullptr)
		{
			delete unicom;
			unicom = nullptr;
		}
	}
	
	void recharge(int money)
	{
		std::cout <<"MobileProxy recharge :"<<money<< std::endl;
		if(money >= 50){
			if(unicom == nullptr){
				unicom = new Unicom();
				unicom->recharge(money);
			}
		}else{
			std::cout << "Sorry, too little money" << std::endl;
		}
	}	
private:
	Unicom* unicom;
};

#endif  //_UNICOM_H