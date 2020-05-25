#ifndef _OBSERVER_H
#define _OBSERVER_H

class Blog;

class Observer
{
public:
	Observer(Blog *blog):m_blog(blog){}
	virtual ~Observer(){}
	virtual void update() = 0;
protected:
	Blog *m_blog;
};

#endif //_OBSERVER_H