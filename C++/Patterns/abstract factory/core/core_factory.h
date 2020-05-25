#ifndef _CORE_FACTORY_H
#define _CORE_FACTORY_H

#include "single_core.h"
#include "multi_core.h"

class CoreFactory
{
public:
	virtual ~CoreFactory(){}
	virtual SingleCore* createSingleCore() = 0;
	virtual MultiCore* createMultiCore() = 0;
};

class CoreFactoryA:public CoreFactory
{
public:
	SingleCore* createSingleCore()
	{
		return new SingleCoreA();
	}
	
	MultiCore* createMultiCore()
	{
		return new MultiCoreA();
	}
};

class CoreFactoryB:public CoreFactory
{
public:
	SingleCore* createSingleCore()
	{
		return new SingleCoreB();
	}
	
	MultiCore* createMultiCore()
	{
		return new MultiCoreB();
	}
};


#endif //_CORE_FACTORY_H