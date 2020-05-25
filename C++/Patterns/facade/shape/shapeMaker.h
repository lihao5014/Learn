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
		circle = new Circle();
		rectangle = new Rectangle();
		square = new Square();
	}
	
	~ShapeMaker()
	{
		if(circle != nullptr){
			delete circle;
			circle = nullptr;
		}

		if(rectangle != nullptr){
			delete rectangle;
			rectangle = nullptr;
		}		

		if(square != nullptr){
			delete square;
			square = nullptr;
		}		
	}
	
	void drawCircle()
	{
		if(circle != nullptr)
			circle->draw();
	}
	
	void drawRectangle()
	{
		if(rectangle != nullptr)
			rectangle->display();
	}

	void drawSquare()
	{
		if(square != nullptr)
			square->draw();
	}	
private:
	Circle* circle;
	Rectangle* rectangle;
	Square* square;
};

#endif //_SHAPE_MAKER_H