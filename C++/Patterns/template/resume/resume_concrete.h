#ifndef _RESUME_CONCRETE_H
#define _RESUME_CONCRETE_H

#include "resume_template.h"
#include <iostream>

class PaperResume:public ResumeTemplate
{
protected:
	virtual void setPersonalInfo()
	{
		std::cout << "PaperResume: write personal information" << std::endl;
	}
	
	virtual void setEducation()
	{
		std::cout << "PaperResume: write education" << std::endl;
	}
	
	virtual void setWorkExp()
	{
		std::cout << "PaperResume: write experience" << std::endl;
	}
};

class NetworkResume:public ResumeTemplate
{
private:
	virtual void setPersonalInfo()
	{
		std::cout << "NetworkResume: write personal information" << std::endl;
	}
	
	virtual void setEducation()
	{
		std::cout << "NetworkResume: write education" << std::endl;
	}
	
	virtual void setWorkExp()
	{
		std::cout << "NetworkResume: write experience" << std::endl;
	}
};

#endif //_RESUME_CONCRETE_H