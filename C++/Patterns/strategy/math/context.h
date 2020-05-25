#ifndef _CONTEXT_H
#define _CONTEXT_H

#include "strategy.h"

class Context
{
public:
	Context(Strategy *strategy = nullptr)
	{
		this->strategy = strategy;
	}
	
	void setStrategy(Strategy *strategy)
	{
		this->strategy = strategy;
	}
	
	double executeStrategy(int x,int y)
	{
		if(strategy == nullptr) throw nullptr;
		
		return strategy->doOperation(x,y);
	}
private:
	Strategy *strategy;
};

#endif //_CONTEXT_H