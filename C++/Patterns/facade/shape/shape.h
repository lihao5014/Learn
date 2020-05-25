#ifndef _SHPAE_H
#define _SHPAE_H

class Shape
{
public:
	virtual ~Shape(){}
	virtual void draw() = 0;
};

#endif //_SHPAE_H