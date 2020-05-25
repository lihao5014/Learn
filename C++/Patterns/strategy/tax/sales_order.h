#ifndef _SALES_ORDER_H 
#define _SALES_ORDER_H

#include "concrete_strategy.h"

class SalesOrder
{
public:
    SalesOrder(TaxStrategy* strategy):strategy(strategy){}
	
	void setStrategy(TaxStrategy* strategy)
	{
		this->strategy = strategy;
	}

    void calculateTax()
	{
         strategy->calculate(); //¶àÌ¬µ÷ÓÃ
    }
private:
    TaxStrategy* strategy;
};

#endif //_SALESORDER_H