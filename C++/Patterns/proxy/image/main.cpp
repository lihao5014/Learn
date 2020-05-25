#include "proxyImage.h"

int main()
{
	Image* image = new ProxyImage("proxty.jpg");

	std::cout<<"图像将从磁盘加载 showing"<<std::endl;
	image->show();
	std::cout<<"图像不需要从磁盘加载 showing"<<std::endl;
	image->show();
	
	return 0;
}