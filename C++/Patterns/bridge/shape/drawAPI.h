#ifndef _DRAWAPI_H
#define _DRAWAPI_H

class DrawAPI
{
public:
	virtual ~DrawAPI(){}
	virtual void drawCircle(int r,int x,int y) = 0;
	virtual void drawRectangle(int w,int h,int x,int y) = 0;
};

#endif //_DRAWAPI_H