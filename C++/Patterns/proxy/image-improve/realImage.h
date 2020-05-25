#ifndef _REAL_IMAGE_H
#define _REAL_IMAGE_H

#include "image.h"
#include <string>
#include <iostream>

class RealImage:public Image
{
public:
	RealImage(std::string fileName)
	{
		this->fileName = fileName;
		loadFromDisk(fileName);
	}
	
	void loadFromDisk(std::string fileName)
	{
		fileName = "loading "+fileName;
		std::cout<<fileName<<std::endl;
	}
	
	void show()override
	{
		std::cout<<"showing "<<fileName<<std::endl;
	}
	
	void display()
	{
		std::cout<<"displaying "<<fileName<<std::endl;
	}
private:
	std::string fileName;
};

#endif //_REAL_IMAGE_H