#ifndef _RECRUIT_APP_H
#define _RECRUIT_APP_H

#include "recruit_lib.h"

class Alibaba:public Company
{
protected:
	virtual void Interview()
	{
		std::cout << "First interview -> Second interview -> Third interview" << std::endl;
	}
	
	virtual void offer()
	{
		std::cout << "30W" << std::endl;
	}
};

class Tencent:public Company
{
protected:
	virtual void Interview()
	{
		std::cout << "First interview -> Second interview" << std::endl;
	}
	
	virtual void offer()
	{
		std::cout << "25W" << std::endl;
	}
};

#endif //_RECRUIT_APP_H
