#include "factory.h"
#include "concrete_factory.h"

Factory* Factory::createFactory(Factory_t type)
{
	switch(type){
	case BENZ_FACTORY:
		return new BenzFactory();
	case BWM_FACTORY:
		return new BmwFactory();
	case AUDI_FACTORY:
		return new AudiFactory();
	default:
		return nullptr;
	}
}