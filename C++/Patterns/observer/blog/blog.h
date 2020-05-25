#ifndef _BLOG_H
#define _BLOG_H

#include "observer.h"
#include <list>
#include <string>

class Blog
{
public:
	virtual ~Blog(){}
	
	virtual void setStatus(std::string status)
	{
		m_status = status;
	}
	
	virtual std::string getStatus()const
	{
		return m_status;
	}
	
	void attach(Observer* observer)
	{
		if(observer != NULL)
			m_observerList.push_back(observer);
	}
	
	void remove(Observer* observer)
	{
		if(observer != NULL)
			m_observerList.remove(observer);
	}
	
	void notify()
	{
		std::list<Observer*>::iterator it = m_observerList.begin();
		while(it != m_observerList.end())
		{
			(*it)->update();
			++it;
		}
	}
protected:
	std::string m_status;
private:
	std::list<Observer*> m_observerList;
};

#endif //_BLOG_H