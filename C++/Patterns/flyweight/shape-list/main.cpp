#include "shapecache.h"

int main()
{
	ShapeFactory* factory = new CircleFactory();
	ShapeCache circleCache(factory);
	
	circleCache.loadCache();
	circleCache.display();
	
	Circle* circle = dynamic_cast<Circle*>(circleCache.getShape(RED));
	circle->draw();
	circle->setR(10);
	circle->setX(4);
	circle->setY(5);
	circle->draw();
	
#if 1	
	circle = static_cast<Circle*>(circleCache.getShape(BLACK));
#else
	circle = (Circle*)circleCache.getShape(BLACK);
#endif	
	circle->draw();
	circle->setR(5);
	circle->setX(1);
	circle->setY(2);
	circle->draw();
	
	circleCache.display();
	delete factory;
	
	factory = new RectangleFactory();
	ShapeCache rectangleCache(factory);
	
	rectangleCache.loadCache();
	rectangleCache.display();
	
	Rectangle* rectangle = dynamic_cast<Rectangle*>(rectangleCache.getShape(GREEN));
	rectangle->draw();
	rectangle->setW(10);
	rectangle->setW(15);
	rectangle->setX(7);
	rectangle->setY(8);
	rectangle->draw();
	
	rectangle = (Rectangle*)rectangleCache.getShape(WHITE);
	rectangle->draw();
	rectangle->setW(20);
	rectangle->setW(25);
	rectangle->setX(11);
	rectangle->setY(12);
	rectangle->draw();
	rectangleCache.display();	
	
	return 0;
}