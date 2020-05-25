#ifndef _VIDEOPHONE_H
#define _VIDEOPHONE_H

#include "iphone.h"
#include "ivideo.h"
#include <iostream>

using std::cout;
using std::endl;

class Videophone:public IPhone,public IVideo
{
public:
	void call()final
	{
		cout<<"Videophone call()"<<endl;
	}
	
	void show()override
	{
		cout<<"Videophone show()"<<endl;
	}
};

#endif //_VIDEOPHONE_H