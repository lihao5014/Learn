#ifndef _CPU_H
#define _CPU_H

#include <iostream>
#include <string>

class Cpu
{
public:
	Cpu(const std::string& name);
	Cpu(const Cpu& other);             //没有指针数据成员，所以不用写析构函数
	
	void setName(const std::string& name);
	std::string getName()const;
	
	void show()const;
private:
	std::string name;
};

Cpu::Cpu(const std::string& name)
	:name(name)
{
	
}

Cpu::Cpu(const Cpu& other)
	:name(other.name)
{
	
}

void Cpu::setName(const std::string& name)
{
	this->name = name;
}

std::string Cpu::getName()const
{
	return name;
}

void Cpu::show()const
{
	std::cout<<"cpu name is: "<<name<<std::endl;
}

#endif //_CPU_H