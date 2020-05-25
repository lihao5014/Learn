#ifndef _COMPONENT_H
#define _COMPONENT_H

class Component
{
public:
	virtual ~Component(){};
	virtual void operation() = 0;
};

#endif //_COMPONENT_H