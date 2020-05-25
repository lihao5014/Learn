#ifndef _KOREAN_H
#define _KOREAN_H

#include "man.h"

class Korean:public Man
{
public:
	Korean(const std::string name):Man(name){};
	Korean(const Korean& other):Man(other.name){};
	
	void sayHello()final
	{
		std::cout<<"º«¹úÈË "<<name<<": Ëµº«Óï"<<std::endl;
	}
};

#endif //_KOREAN_H