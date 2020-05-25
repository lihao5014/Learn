#ifndef _CAR_H
#define _CAR_H

#include <string>
#include <iostream>

class Car
{
public:
	void setEngine(std::string engine)
	{
		m_engine = engine;
	}
	
	void setWheel(std::string wheel)
	{
		m_wheel = wheel;
	}
	
	void setBody(std::string body)
	{
		m_body = body;
	}
	
	void show()const
	{
		std::cout<<m_engine<<" , "<<m_wheel<<" , "<<m_wheel<<std::endl;
	}
private:
	std::string m_engine;
	std::string m_wheel;
	std::string m_body;
};

#endif //_CAR_H