#include "shape.h"

int main()
{
	Shape* arrShape[SHAPE_COUNT];
	
	arrShape[SQUARE] = new Square;
	arrShape[RECTANGLE] = new Rectangle;
	arrShape[TRIANGLE] = new Triangle();
	arrShape[CIRCLE] = new Circle();
	arrShape[ELLIPSE] = new Ellipse();
	
	arrShape[SQUARE]->draw();
	arrShape[ELLIPSE]->draw();
	
	for(int i=0;i<SHAPE_COUNT;++i)
	{
		if(arrShape[i] != nullptr)
		{
			delete arrShape[i];
			arrShape[i] = nullptr;
		}
	}
	
	return 0;
}