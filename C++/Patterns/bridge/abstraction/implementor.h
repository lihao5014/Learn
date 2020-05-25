#ifndef _IMPLEMENTOR_H
#define _IMPLEMENTOR_H

#include <iostream>

class Implementor
{
public:
	virtual ~Implementor(){}
	virtual void operationImpl() = 0;
};

class ConcreteImplementorA:public Implementor
{
public:
	void operationImpl()
	{
		std::cout<<"ConcreteImplementorA : OperationImpl"<<std::endl;
	}
};

class ConcreteImplementorB:public Implementor
{
public:
	void operationImpl()
	{
		std::cout<<"ConcreteImplementorB : OperationImpl"<<std::endl;
	}
};

#endif //_IMPLEMENTOR_H