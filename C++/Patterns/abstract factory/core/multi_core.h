#ifndef _MULTICORE_H
#define _MULTICORE_H

#include <iostream>

class MultiCore
{
public:
	virtual ~MultiCore(){}
	virtual void display() = 0;
};

class MultiCoreA final:public MultiCore
{
public:
	virtual void display()override
	{
		std::cout<<"multi-coreA"<<std::endl;
	}
};

class MultiCoreB final:public MultiCore
{
public:
	virtual void display()override
	{
		std::cout<<"multi-coreB"<<std::endl;
	}
};

#endif //_MULTICORE_H