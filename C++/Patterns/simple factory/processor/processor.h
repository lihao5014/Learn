#ifndef _PROCESSOR_H
#define _PROCESSOR_H

#include <iostream>

class Processor
{
public:
	virtual ~Processor(){}
	virtual void show() = 0;
};

class SingleCore:public Processor
{
public:
	void show()
	{
		std::cout<<"single-core processor"<<std::endl;
	}
};

class MultiCore:public Processor
{
public:
	void show()
	{
		std::cout<<"multi-core processor"<<std::endl;
	}
};

#endif //_PROCESSOR_H