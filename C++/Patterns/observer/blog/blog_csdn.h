#ifndef _BLOG_CSDN_H
#define _BLOG_CSDN_H

#include "blog.h"

class BlogCSDN:public Blog
{
public:
	BlogCSDN(std::string name):m_name(name){}
	
	virtual void setStatus(std::string status)override
	{
		m_status = "CSDN " + m_name + status;
	}
private:
	std::string m_name;
};

#endif //_BLOG_CSDN_H