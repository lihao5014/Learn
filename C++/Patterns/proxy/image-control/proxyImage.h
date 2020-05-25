#ifndef _PROXY_IMAGE_H
#define _PROXY_IMAGE_H

#include "realImage.h"

class ProxyImage:public Image
{
public:
	ProxyImage(std::string fileName):image(new RealImage(fileName))
	{
		this->fileName = fileName;
	}
	
	void show()final				//ProxyImage是一个代理类，减少RealImage对象加载的内存占用。
	{
		image->show();
	}
private:
	Image* image;				    //代理类控制只能访问Image定义的接口
	std::string fileName;
};

#endif //_PROXY_IMAGE_H