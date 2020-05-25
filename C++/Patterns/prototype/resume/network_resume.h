#ifndef _NETWORK_RESUME_H
#define _NETWORK_RESUME_H

#include "resume.h"
#include <iostream>

class NetworkResume:public Resume
{
public:
	NetworkResume(const char* name,const int age = 0)
		:Resume(name,age){}
	
	NetworkResume(const NetworkResume& resume)
		:Resume(resume){}
	
	virtual Resume* clone()
	{
		return new NetworkResume(*this);
	}
	
	void show()const
	{
		std::cout<<"network resume :"<<m_name<<" ,"<<m_age<<std::endl;
	}
};

#endif //_NETWORK_RESUME_H