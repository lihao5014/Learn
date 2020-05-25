#ifndef _PROXY_SUBJECT_H
#define _PROXY_SUBJECT_H

#include "realSubject.h"

class ProxySubject:public Subject
{
public:
	ProxySubject():subject(nullptr)
	{
		
	}
	
	~ProxySubject()
	{
		if(subject != nullptr){
			delete subject;
			subject = nullptr;
		}
	}
	
	void request()final
	{
		if(subject == nullptr)
			subject = new RealSubject();
		std::cout<<"proxy Request"<<std::endl;
		subject->request();
	}

private:
	RealSubject* subject;
};

#endif  //