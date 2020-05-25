#include "implementor.h"
#include "abstraction.h"

int main()
{
	Implementor* impl = new ConcreteImplementorA();
	Abstraction* abs =  new RedefineAbstraction(impl);
	impl->operationImpl();
	abs->operation();
	delete impl;
	
	impl = new ConcreteImplementorB();
	abs->setImplementor(impl);
	impl->operationImpl();
	abs->operation();
	delete impl;
	delete abs;	
	
	return 0;
}