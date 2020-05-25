#ifndef _SUBSYSTEM_H
#define _SUBSYSTEM_H

#include <iostream>

class SubsystemOne final
{
public:
	void methodOne()
	{
		std::cout<<"子系统方法一"<<std::endl;
	}
};

class SubsystemTwo final
{
public:
	void methodTwo()
	{
		std::cout<<"子系统方法二"<<std::endl;
	}
};

class SubsystemThree final
{
public:
	void methodThree()
	{
		std::cout<<"子系统方法三"<<std::endl;
	}
};

class SubsystemFour final
{
public:
	void methodFour()
	{
		std::cout<<"子系统方法四"<<std::endl;
	}
};

#endif //_SUBSYSTEM_H