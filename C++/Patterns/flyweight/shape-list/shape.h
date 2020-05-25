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
	void setColor(const Color_t color){this->color = color;}
	Color_t getColor()const{return color;}	
	virtual void draw() = 0;
protected:
	Color_t color;
};

#endif //_SHPAE_H