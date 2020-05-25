#ifndef _IPHONE_H
#define _IPHONE_H

#include "phone.h"
#include <iostream>

class Iphone:public Phone
{
public:
	Iphone(char* name):m_name(name){}
	void show()final
	{
		std::cout<<m_name<<"µÄ×°ÊÎ"<<std::endl;
	}
private:
	char* m_name;
};

#endif //_IPHONE_H