#include "shape_cache.h"

int main()
{
	ShapeCache shape_cache;
	
	shape_cache.loadCache();
	Shape* shape = shape_cache.getShape(0);
	shape->draw();
	delete shape;
	
	shape = shape_cache.getShape(1);
	shape->draw();
	delete shape;
	
	shape = shape_cache.getShape(2);
	shape->draw();
	delete shape;
	
	return 0;
}