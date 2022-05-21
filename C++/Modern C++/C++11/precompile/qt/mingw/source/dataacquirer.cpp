#include "dataacquirer.h"

using namespace std;

DataAcquirer::DataAcquirer(const string& fileName)
	:DataAcquirerAbstract(fileName)
{
	
}

string DataAcquirer::getData()const
{
	StreamHelper stream(m_fileName);
	return stream.getData();
}