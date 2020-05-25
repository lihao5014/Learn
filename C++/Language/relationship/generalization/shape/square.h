#ifndef _SQUARE_H
#define _SQUARE_H

#include "shape.h"

class Square:public Shape
{
public:
	Square(double length);
	Square(const Square& other);
	
	void draw()const;
private:
	double length;
};

Square::Square(const double length)
	:Shape(4*length,length*length)
	,length(length)
{
	
}

Square::Square(const Square& other)
	:Shape(other)
	,length(other.length)
{
	
}

void Square::draw()const
{
	cout<<"length ="<<length<<endl;
	Shape::draw();
}

#endif //_SQUARE_H