#ifndef _SYSTEM_H
#define _SYSTEM_H

#include <iostream>

class System
{
public:
	virtual ~System(){}
	virtual void installOS_impl() = 0;
};

class Windows:public System
{
public:
	virtual void installOS_impl()
	{
		std::cout<<"安装Window操作系统"<<std::endl;
	}
};

class Linux:public System
{
public:
	virtual void installOS_impl()
	{
		std::cout<<"安装Linux操作系统"<<std::endl;
	}
};

class Unix:public System
{
public:
	virtual void installOS_impl()
	{
		std::cout<<"安装Unix操作系统"<<std::endl;
	}
};

#endif //_SYSTEM_H