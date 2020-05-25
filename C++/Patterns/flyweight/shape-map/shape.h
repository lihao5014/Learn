#ifndef _SHPAE_H
#define _SHPAE_H

enum Color_t
{
	RED,
	GREEN,
	BLUE,
	BLACK,
	WHITE
};

class Shape
{
public:
	virtual ~Shape(){}
	virtual void draw() = 0;
protected:
	;
};

#endif //_SHPAE_H