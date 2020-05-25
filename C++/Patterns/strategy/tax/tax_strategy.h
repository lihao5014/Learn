#ifndef _TAX_STRATEGY_H
#define _TAX_STRATEGY_H

class TaxStrategy
{
public:
	virtual ~TaxStrategy(){}
    virtual void calculate() = 0;
};

#endif //_TAX_STRATEGY_H