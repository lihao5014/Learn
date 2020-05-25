#ifndef _CONTEXT_H
#define _CONTEXT_H

#include "concrete_strategy.h"

class Context
{
public:	
	Context(IStrategy* strategy):strategy(strategy){}
	void setStrategy(IStrategy* strategy)
	{
		this->strategy = strategy;
	}
	
	void travel()
	{
		if(strategy != NULL)
			strategy->travel();
	}
private:
	IStrategy *strategy;
};

#endif //_CONTEXT_H