#ifndef _IMAGE_H
#define _IMAGE_H

#include <string>

class Image
{
public:
	Image(std::string imageName):imageName(imageName){}
	virtual ~Image(){}
	virtual void show() = 0;
protected:
	std::string imageName;
};

#endif //_IMAGE_H