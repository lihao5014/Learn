#ifndef _FACTORY_H
#define _FACTORY_H

#include "processor.h"

class Factory
{
public:
	virtual ~Factory(){}
	virtual Processor* createProcessor() = 0;
	void destroyProcessor(Processor** core)
	{
		if(*core != nullptr){
			delete *core;
			*core = nullptr;
		}
	}
};

class SingleCoreFactory:public Factory
{
public:
	Processor* createProcessor()
	{
		return new SingleCore();
	}
};

class MultiCoreFactory:public Factory
{
public:
	Processor* createProcessor()
	{
		return new MultiCore();
	}
};

#endif //_FACTORY_H