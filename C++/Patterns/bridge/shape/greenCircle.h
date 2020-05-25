#ifndef _GREENCIRCLE_H
#define _GREENCIRCLE_H

#include "drawAPI.h"
#include <iostream>
#include <exception>

class GreenCircle:public DrawAPI
{
public:
	virtual void drawCircle(int r,int x,int y)
	{
		std::cout<<"Drawing green Circle :redius =r , ("<<x<<","<<y<<")"<<std::endl;
	}
	
	void drawRectangle(int w,int h,int x,int y){
		throw "GreenCircle :drawRectangle isn't implemented";
	}
};

#endif //_GREENCIRCLE_H