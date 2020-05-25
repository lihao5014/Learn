#ifndef _BIG_IMAGE_H
#define _BIG_IMAGE_H

#include "image.h"
#include <iostream>

class BigImage:public Image
{
public:
	BigImage(std::string imageName):Image(imageName)
	{
		
	}
	
	virtual void show()override
	{
		std::cout<<"Show big image :"<<imageName<<std::endl;
	}
};

#endif //_BIG_IMAGE_H