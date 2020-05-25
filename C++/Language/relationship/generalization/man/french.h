#ifndef _FRENCH_H
#define _FRENCH_H

#include "man.h"

class French:public Man
{
public:
	French(const std::string name):Man(name){};
	French(const French& other):Man(other){};
	
	virtual void sayHello()
	{
		std::cout<<"法国人 "<<name<<": 说法语"<<std::endl;
	}
};

#endif //_FRENCH_H