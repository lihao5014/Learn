#ifndef _SHAPE_CACHE_H
#define _SHAPE_CACHE_H

#include "shapeFactory.h"
#include <list>

class ShapeCache
{
public:
	ShapeCache(ShapeFactory* factory):factory(factory)
	{
		
	}
	
	void setFactory(ShapeFactory* factory)
	{
		this->factory = factory;
	}
	
	Shape* getShape(Color_t color)
	{
		std::list<Shape*>::iterator iter = m_list.begin();
		if(iter != m_list.end()){
			if((*iter)->getColor() == color){
				return *iter;
			}
			++iter;
		}
		
		Shape* shape = factory->createShape(color);
		m_list.push_back(shape);
		return shape;
	}
	
	void loadCache()
	{
		Shape* shape = nullptr;
		for(int i=0;i<3;i++){
			shape = factory->createShape(static_cast<Color_t>(i));
			m_list.push_back(shape);
		}
	}
	
	void display()
	{
		std::list<Shape*>::iterator iter = m_list.begin();
		while(iter != m_list.end()){
			(*iter)->draw();
			++iter;
		}
	}
private:
	std::list<Shape*> m_list;
	ShapeFactory* factory;
};

#endif //_SHAPE_CACHE_H