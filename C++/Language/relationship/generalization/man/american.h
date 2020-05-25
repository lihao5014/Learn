#ifndef _AMERICAN_H
#define _AMERICAN_H

#include "man.h"

class American:public Man
{
public:
	American(const std::string name):Man(name){};
	American(const American& other):Man(other.name){};
	
	void sayHello()override
	{
		std::cout<<"美国人 "<<name<<": 说英语"<<std::endl;
	}
};

#endif //_AMERICAN_H