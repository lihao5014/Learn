#ifndef _MAN_H
#define _MAN_H

#include <string>
#include <iostream>

class Man
{
public:
	Man(const std::string name):name(name){};
	Man(const Man& other):name(other.name){};
	virtual ~Man(){};
	
	virtual void sayHello()
	{
		std::cout<<"Man "<<name<<": say hello"<<std::endl;
	}
protected:
	std::string name;
};

#endif //_MAN_H