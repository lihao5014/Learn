#ifndef _COMPUTER_H
#define _COMPUTER_H

#include "system.h"

class Computer
{
public:
	virtual ~Computer(){}
	void setSystem(System* system){this->system = system;}
	virtual void installOS() = 0;
protected:
	System* system;
};

class DellComputer:public Computer
{
public:
	DellComputer(System* system){this->system = system;}    //调用Computer的默认构造函数
	void installOS()override
	{
		std::cout<<"Dell计算机安装操作系统"<<std::endl;
		if(system != nullptr)
			system->installOS_impl();
	}
};

class AppleComputer:public Computer
{
public:
	AppleComputer(System* system){this->system = system;}
	void installOS()override
	{
		std::cout<<"Apple计算机安装操作系统"<<std::endl;
		if(system != nullptr)
			system->installOS_impl();
	}
};

class HPComputer:public Computer
{
public:
	HPComputer(System* system){this->system = system;}
	void installOS()override
	{
		std::cout<<"HP计算机安装操作系统"<<std::endl;
		if(system != nullptr)
			system->installOS_impl();
	}
};

#endif //_COMPUTER_H