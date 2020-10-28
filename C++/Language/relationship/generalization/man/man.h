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
	
	virtual void sayHello() = 0;         //Man类是一个带有纯虚函数的抽象类
protected:
	std::string name;
};

#endif //_MAN_H