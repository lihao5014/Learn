#ifndef _IELECTRICAL_H
#define _IELECTRICAL_H

#include "iswitch.h"
#include <iostream>
#include <string>

class IElectrical
{
public:
	IElectrical(std::string name)
		:m_name(name),m_switch(nullptr){}
	IElectrical(std::string name,ISwitch* _switch)
		:m_name(name),m_switch(_switch){}
	virtual ~IElectrical(){}
	
	void setSwitch(ISwitch* _switch){m_switch = _switch;}
	virtual void display()const = 0;
	virtual void powerOn() = 0;
	virtual void powerOff() = 0;
protected:
	std::string m_name;
	ISwitch* m_switch;
};

class Light:public IElectrical
{
public:
	Light(std::string name):IElectrical(name){}
	Light(std::string name,ISwitch* _switch):IElectrical(name,_switch){}
	
	virtual void display()const
	{
		std::cout << "this is light" << std::endl;
	}
	
	virtual void powerOn()
	{
		std::cout << "Light is on." << std::endl;
		if(m_switch != nullptr)
			m_switch->on();
	}
	
	virtual void powerOff()
	{
		std::cout << "Light is off." << std::endl;
		if(m_switch != nullptr)
			m_switch->off();
	}
};

class Fan:public IElectrical
{
public:
	Fan(std::string name):IElectrical(name){}
	Fan(std::string name,ISwitch* _switch):IElectrical(name,_switch){}

	virtual void display()const
	{
		std::cout << "this is fan"<< std::endl;
	}
	
void powerOn()
{
	std::cout << "Fan is on." << std::endl;
	if(m_switch != nullptr)
		m_switch->on();		
}

void powerOff()
{
	std::cout << "Fan is off." << std::endl;
	if(m_switch != nullptr)
		m_switch->off();		
}
};

#endif //_IELECTRICAL_H
