#ifndef _SHAPE_H
#define _SHAPE_H

class DrawAPI;

class Shape
{
public:
	Shape(DrawAPI* drawAPI):drawAPI(drawAPI){}
	virtual ~Shape(){}
	void setDrawAPI(DrawAPI* drawAPI){this->drawAPI = drawAPI;}
	virtual void display()const = 0;
	virtual void draw() = 0;
protected:
	DrawAPI* drawAPI;
};

#endif //_SHAPE_H