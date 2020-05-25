#ifndef _REDCIRCLE_H
#define _REDCIRCLE_H

#include "drawAPI.h"
#include <iostream>

class RedCircle:public DrawAPI
{
public:
	virtual void drawCircle(int r,int x,int y)
	{
		std::cout<<"Drawing red Circle :redius =r , ("<<x<<","<<y<<")"<<std::endl;
	}
	
	void drawRectangle(int w,int h,int x,int y){
		throw const_cast<char*>("RedCircle :drawRectangle isn't implemented");
	}
};

#endif //_REDCIRCLE_H