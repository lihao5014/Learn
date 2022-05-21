#ifndef _DATA_ACQUIRER_FACTORY_H_
#define _DATA_ACQUIRER_FACTORY_H_

#include <memory>
#include "ifactory.h"

class DataAcquirerFactory:public IFactory
{
public:
	virtual std::shared_ptr<DataAcquirerAbstract> createDataAcquirer(const std::string& fileName)override;
};

#endif  //_DATA_ACQUIRER_FACTORY_H_
