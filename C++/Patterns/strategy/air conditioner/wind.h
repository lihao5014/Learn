#ifndef _WIND_H
#define _WIND_H

#include <iostream>

class IWind
{
public:
	virtual ~IWind(){}
	virtual void blowWind() = 0;
};

class ColdWind:public IWind
{
public:
	void blowWind()
	{
		std::cout<<"Blowing cold wind!"<<std::endl;
	}
};

class WarmWind:public IWind
{
public:
	void blowWind()
	{
		std::cout<<"Blowing warm wind!"<<std::endl;
	}
};

class NoWind:public IWind
{
public:
	void blowWind()
	{
		std::cout<<"NO wind!"<<std::endl;
	}
};

#endif //_WIND_H