#ifndef _FACTORY_H
#define _FACTORY_H

#include "processor.h"

typedef enum
{
	SINGLE,
	MULTI
}Cpu_t;

class Factory
{
public:
	Processor* createProcessor(Cpu_t type)
	{
		switch(type){
		case SINGLE:
			return new SingleCore();
		case MULTI:
			return new MultiCore();
		default:
			return nullptr;
		}
	}
	
	void destroyProcessor(Processor** core)
	{
		if(*core != nullptr){
			delete *core;
			*core = nullptr;
		}
	}
};

#endif //_FACTORY_H