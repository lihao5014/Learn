#include "rectangle.h"
#include "circle.h"
#include "red_shape_decorator.h"

#ifndef _FREE_PTR_
#define FREE_PTR(p)              \
    do{                          \
	    if((p) != nullptr){      \
		    delete (p);          \
			(p) = nullptr;       \
		}                        \
	}while(0)
#endif //_FREE_PTR_

int main()
{
	Shape* rectangle = new Rectangle();
	ShapeDecorator* redRect = new RedShapeDecorator(rectangle);
	rectangle->draw();
	redRect->draw();
	FREE_PTR(redRect);
	FREE_PTR(rectangle);
	
	Shape* circle = new Circle();
	ShapeDecorator* redCircle = new RedShapeDecorator(circle);
	circle->draw();
	redCircle->draw();
	FREE_PTR(redCircle);
	FREE_PTR(circle);	
	
	return 0;
}