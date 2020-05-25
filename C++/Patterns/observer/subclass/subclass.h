#ifndef _SUBCLASS_H
#define _SUBCLASS_H

#include "base.h"
#include "sample.h"
#include <iostream>

class Subclass:public Base
{
public:
	Subclass(Sample* sample):Base(sample){sample->setBase(this);}
	void show()const{Base::show();std::cout<<"Subclass"<<std::endl;}
};

#endif //_SUBCLASS_H