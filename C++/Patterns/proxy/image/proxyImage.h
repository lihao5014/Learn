#ifndef _PROXY_IMAGE_H
#define _PROXY_IMAGE_H

#include "realImage.h"

class ProxyImage:public Image
{
public:
	ProxyImage(std::string fileName):image(nullptr)
	{
		this->fileName = fileName;
	}
	
	~ProxyImage()
	{
		if(image != nullptr){
			delete image;
			image = nullptr;
		}
	}
	
	void show()final				//ProxyImage是一个代理类，减少RealImage对象加载的内存占用。
	{
		if(image == nullptr)
			image = new RealImage(fileName);
		image->show();
	}
private:
	RealImage* image;
	std::string fileName;
};

#endif //_PROXY_IMAGE_H