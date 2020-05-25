#ifndef _CONCRETE_STRATEGY_H
#define _CONCRETE_STRATEGY_H

#include "tax_strategy.h"
#include <iostream>

class CNTax : public TaxStrategy
{
public:
    virtual void calculate()
	{
        std::cout<<"Calculate chine tax"<<std::endl;
    }
};

class USTax : public TaxStrategy
{
public:
    virtual void calculate()
	{
        std::cout<<"Calculate america tax"<<std::endl;
    }
};

class DETax : public TaxStrategy
{
public:
    virtual void calculate()
	{
        std::cout<<"Calculate germany tax"<<std::endl;
    }
};

//扩展
class FRTax : public TaxStrategy
{
public:
	virtual void calculate()
	{
		std::cout<<"Calculate france tax"<<std::endl;
	}
};

#endif //_CONCRETE_STRATEGY_H