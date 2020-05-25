#ifndef _PROCESSOR_H
#define _PROCESSOR_H

#include <iostream>

class Processor
{
public:
	virtual ~Processor(){}
	virtual void show() = 0;
};

class SingleCore final:public Processor
{
public:
	virtual void show()final
	{
		std::cout<<"single-core processor"<<std::endl;
	}
};

class MultiCore final:public Processor
{
public:
	virtual void show()override
	{
		std::cout<<"multi-core processor"<<std::endl;
	}
};

#endif //_PROCESSOR_H