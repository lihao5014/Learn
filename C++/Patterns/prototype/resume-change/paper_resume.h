#ifndef _PAPER_RESUME_H
#define _PAPER_RESUME_H

#include "resume.h"
#include <iostream>

class PaperResume:public Resume
{
public:
	PaperResume(const char* name,const int age = 0)
		:Resume(name,age){}
	
	PaperResume(const PaperResume& resume)
		:Resume(resume){}
	
	virtual Resume* clone()
	{
		return new PaperResume(*this);
	}
	
	void show()const
	{
		std::cout<<"paper resume :"<<m_name<<" ,"<<m_age<<std::endl;
	}
};

#endif //_PAPER_RESUME_H