#ifndef _SHAPE_CACHE_H
#define _SHAPE_CACHE_H

#include "rectangle.h"
#include "square.h"
#include "circle.h"
#include <iostream>
#include <map>

class ShapeCache
{
public:
	Shape* getShape(int id);
	static void loadCache();
private:
	static std::map<int,Shape*> m_map;
};

std::map<int,Shape*> ShapeCache::m_map;

Shape* ShapeCache::getShape(int id)
{
	if(id < 0 || id > 2){
		std::cout<<"id is illegal"<<std::endl;
	}
	
	return m_map[id]->clone();
}

void ShapeCache::loadCache()
{
	Rectangle* rectangle = new Rectangle("rectangle",0);
	m_map[0] = rectangle;
	
	Square* square = new Square("square",1);
	m_map[1] = square;
	
	Circle* circle = new Circle("circle",2);
	m_map[2] = circle;
}

#endif //_SHAPE_CACHE_H