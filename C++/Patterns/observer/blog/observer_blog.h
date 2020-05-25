#ifndef _OBSERVER_BLOG_H
#define _OBSERVER_BLOG_H

#include "observer.h"
#include <iostream>

class Blog;

class ObserverBlog:public Observer
{
public:
	ObserverBlog(std::string name,Blog *blog)
		:m_name(name),m_blog(blog){}

	void update()
	{
		std::cout<<m_name<<"---"<<m_blog->getStatus()<<std::endl;
	}
private:
	std::string m_name;
	Blog *m_blog;
};

#endif //_OBSERVER_BLOG_H