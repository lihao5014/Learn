#ifndef _CHINESE_H
#define _CHINESE_H

#include "man.h"

class Chinese:public Man   //使用纯虚函数来实现类之间的泛化关系
{
public:
	Chinese(const std::string name):Man(name){};
	Chinese(const Chinese& other):Man(other){};
	
	void sayHello()
	{
		std::cout<<"中国人 "<<name<<": 说中文"<<std::endl;
	}
};

#endif //_CHINESE_H