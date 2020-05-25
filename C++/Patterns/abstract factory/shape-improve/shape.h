#ifndef _SHAPE_H
#define _SHAPE_H

class Shape
{
public:
	virtual ~Shape(){}
	virtual void draw() = 0;
};

#endif //_SHAPE_H