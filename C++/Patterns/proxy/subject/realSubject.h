#ifndef _REAL_SUBJECT_H
#define _REAL_SUBJECT_H

#include "subject.h"
#include <iostream>

class RealSubject:public Subject
{
public:
	void request()override
	{
		std::cout<<"CRealSubject Request"<<std::endl;
	}
};

#endif  //_REAL_SUBJECT_H