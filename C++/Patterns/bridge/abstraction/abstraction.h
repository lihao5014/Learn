#ifndef _ABSTRACTION_H
#define _ABSTRACTION_H

#include "implementor.h"

class Abstraction
{
public:
	Abstraction(Implementor* impl):m_impl(impl){}
	void setImplementor(Implementor* impl){m_impl = impl;}
	virtual void operation() = 0;
protected:
	Implementor* m_impl;
};

class RedefineAbstraction:public Abstraction
{
public:
	RedefineAbstraction(Implementor* impl):Abstraction(impl){}
	void operation()
	{
		std::cout<<"RedefineAbstraction : operation"<<std::endl;
		if(m_impl != nullptr)
			m_impl->operationImpl();
	}
};

#endif //_ABSTRACTION_H