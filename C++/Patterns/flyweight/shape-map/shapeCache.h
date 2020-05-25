#ifndef _SHAPE_CACHE_H
#define _SHAPE_CACHE_H

#include "shapeFactory.h"
#include <map>

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
		std::map<Color_t,Shape*>::iterator iter = m_map.find(color);
		if(iter != m_map.end()){
			return m_map[color];
		}
		
		Shape* shape = factory->createShape(color);
		m_map[color] = shape;
		return shape;
	}
	
	void loadCache()
	{
		Shape* shape = nullptr;
		for(int i=0;i<3;i++){
			shape = factory->createShape(static_cast<Color_t>(i));
			m_map[static_cast<Color_t>(i)] = shape;
		}
	}
	
	void display()
	{
		std::map<Color_t,Shape*>::iterator iter = m_map.begin();
		while(iter != m_map.end()){
			std::cout<<"key ="<<iter->first<<" , ";
			iter->second->draw();
			++iter;
		}
	}
private:
	std::map<Color_t,Shape*> m_map;
	ShapeFactory* factory;
};

#endif //_SHAPE_CACHE_H