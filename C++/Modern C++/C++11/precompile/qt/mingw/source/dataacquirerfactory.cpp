#include "dataacquirerfactory.h"
#include "dataacquirer.h"

using namespace std;

shared_ptr<DataAcquirerAbstract> DataAcquirerFactory::createDataAcquirer(const std::string& fileName)
{
	return make_shared<DataAcquirer>(fileName);
}