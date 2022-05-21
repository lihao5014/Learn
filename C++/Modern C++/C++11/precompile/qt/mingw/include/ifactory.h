#ifndef _IFACTORY_H_
#define _IFACTORY_H_

#include <memory>
#include "dataacquirerabstract.h"

struct IFactory
{
	virtual ~IFactory(){};
	virtual std::shared_ptr<DataAcquirerAbstract> createDataAcquirer(const std::string& fileName) = 0;
};

#endif  //_IFACTORY_H_