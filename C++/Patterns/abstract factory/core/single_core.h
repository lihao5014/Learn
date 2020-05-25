#ifndef _SINGLECORE_H
#define _SINGLECORE_H

#include <iostream>

class SingleCore
{
public:
	virtual ~SingleCore(){}
	virtual void show() = 0;
};

class SingleCoreA final:public SingleCore
{
public:
	virtual void show()final
	{
		std::cout<<"single-coreA"<<std::endl;
	}
};

class SingleCoreB final:public SingleCore
{
public:
	virtual void show()final
	{
		std::cout<<"single-coreB"<<std::endl;
	}
};

#endif //_SINGLECORE_H