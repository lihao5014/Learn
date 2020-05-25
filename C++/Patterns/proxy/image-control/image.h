#ifndef _IMAGE_H
#define _IMAGE_H

class Image
{
public:
	virtual ~Image(){}
	virtual void show() = 0;
};

#endif //_IMAGE_H