#ifndef _DATA_ACQUIRER_H_
#define _DATA_ACQUIRER_H_

#include <stdio.h>
#include <fstream>
#include "dataacquirerabstract.h"

class DataAcquirer:public DataAcquirerAbstract
{
	class StreamHelper
	{
	public:
		StreamHelper(const std::string& fileName)
		{
			printf("StreamHelper(): open input file stream, %s\n",fileName.c_str());
			m_inputfileStream.open(fileName);
		}
		
		~StreamHelper()
		{
			puts("~StreamHelper(): close input file stream\n");
			m_inputfileStream.close();
		}
		
		std::string getData()
		{
			fputs("getData(): acquirer data from stream\n",stdout);
			if(!m_inputfileStream.is_open())
			{
				return "ifstream can't open!";
			}
			
			std::string strTemp,strText;
			while(!m_inputfileStream.eof())
			{
				std::getline(m_inputfileStream,strTemp);
				strText += strTemp + '\n';
			}
			
			return strText;
		}
		
	private:
		std::ifstream m_inputfileStream;
	};
	
public:
	DataAcquirer(const std::string& fileName);
	
	std::string getData()const;
};

#endif  //_DATA_ACQUIRER_H_