#ifndef _ISWITCH_H
#define _ISWITCH_H

#include <iostream>

class ISwitch
{
public:
	virtual ~ISwitch(){}
	virtual void on() = 0;
	virtual void off() = 0;
};

class ButtonSwitch:public ISwitch
{
public:
	virtual void on()override
	{
		std::cout << "button switch turn on." << std::endl;
	}
	
	virtual void off()override
	{
		std::cout << "button switch turn off." << std::endl;
	}	
};

class RotarySwitch:public ISwitch
{
public:
	virtual void on()override
	{
		std::cout << "rotary switch turn on." << std::endl;
	}
	
	virtual void off()override
	{
		std::cout << "rotary switch turn off." << std::endl;
	}	
};

#endif //_ISWITCH_H