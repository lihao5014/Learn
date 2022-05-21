#ifndef _DATA_ACQUIRER_ABSTRACT_H_
#define _DATA_ACQUIRER_ABSTRACT_H_

#include <string>

class DataAcquirerAbstract
{
public:
	DataAcquirerAbstract(const std::string& fileName):m_fileName(fileName){};
	virtual ~DataAcquirerAbstract(){};
	
	virtual std::string getData()const = 0;
protected:
	std::string m_fileName;	
};

#endif  //_DATA_ACQUIRER_ABSTRACT_H_