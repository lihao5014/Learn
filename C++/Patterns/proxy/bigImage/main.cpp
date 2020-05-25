#include "bigImage_proxy.h"

int main()
{
	Image* image = new BigImageProxy("proxty.jpg");
	image->show();
	delete image;
	
	return 0;
}