#ifndef _SHAPE_MAKER_H
#define _SHAPE_MAKER_H

#include "circle.h"
#include "rectangle.h"
#include "square.h"

class ShapeMaker
{
public:
	ShapeMaker()
	{
		
	}
		
	void drawCircle()
	{
		circle.draw();
	}
	
	void drawRectangle()
	{
		rectangle.draw();
	}

	void drawSquare()
	{
		square.draw();
	}	
private:
	Circle circle;
	Rectangle rectangle;
	Square square;
};

#endif //_SHAPE_MAKER_H