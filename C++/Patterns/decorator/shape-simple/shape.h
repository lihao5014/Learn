#ifndef _SHAPE_H
#define _SHAPE_H

struct Shape
{
	virtual ~Shape(){};
	virtual void draw() = 0;
};

#endif //_SHAPE_H