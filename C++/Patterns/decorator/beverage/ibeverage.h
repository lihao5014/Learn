#ifndef _IBEVERAGE_H
#define _IBEVERAGE_H

#include <string>
#include <iostream>

class IBeverage
{
public:
	virtual ~IBeverage(){}
	virtual std::string name() = 0;
	virtual double cost() = 0;
	void display()
	{
		std::cout<<name()<<" :"<<cost()<<std::endl;
	}
};

#endif //_IBEVERAGE_H