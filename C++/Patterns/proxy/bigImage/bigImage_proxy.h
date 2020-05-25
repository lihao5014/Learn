#ifndef _BIGIMAGE_PROXY_H
#define _BIGIMAGE_PROXY_H

#include "bigImage.h"

class BigImageProxy:public Image
{
public:
	BigImageProxy(std::string imageName):Image(imageName),image(nullptr)
	{
		
	}
	
	~BigImageProxy()
	{
		if(image != nullptr){
			delete image;
			image = nullptr;
		}
	}
	
	void show()final
	{
		if(image == nullptr)
			image = new BigImage(imageName);
		image->show();
	}
private:
	BigImage* image;
};

#endif //_BIGIMAGE_PROXY_H