#include "concrete_subject.h"
#include "concrete_observer.h"
#include <iostream>

#define FREE_PTR(p)           \
	do{                       \
		if(nullptr != p)      \
			delete p;         \
		p = nullptr;          \
	}while(0)

#ifndef SAFE_DELETE
#define SAFE_DELETE(p)            \
	{							  \
		if(p){                    \
			delete(p);            \
			(p)=NULL;             \
		}                         \
	}
#endif

//static void free_ptr(void* p);     //只能使用void*不能使用void**

int main()
{
	Subject *subjectA = new ConcreteSubjectA(1);
	Observer *observerA = new ConcreteObserverA(subjectA,10);
	Observer *observerB = new ConcreteObserverB(20);
	observerB->setSubject(subjectA);   //这种被观察的对象
	subjectA->attach(observerB);
	subjectA->setState(30);
	subjectA->notify(30);
	
	Subject *subjectB = new ConcreteSubjectB(2);
	observerA->setSubject(subjectB);
	observerB->setSubject(subjectB);
	subjectB->attach(observerA);
	subjectB->attach(observerB);
	subjectB->setState(11);
	subjectB->notify(17);
	
	SAFE_DELETE(subjectA);
	SAFE_DELETE(subjectB);
	FREE_PTR(observerA);
	FREE_PTR(observerB);	
	return 0;
}

/*
void free_ptr(void* p)
{
	if(p != nullptr)
		delete p;
}
*/