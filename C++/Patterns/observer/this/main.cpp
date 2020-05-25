#include "base.h"
#include "sample.h"
#include <iostream>

int main()
{
	Sample sample(10);
	Base* base = new Base(&sample,20);
//	sample.setBase(base);
	sample.display();
	base->show();
	
	base->setValue(30);
	sample.setData(40);
	sample.display();
	base->show();
		
	if(base != nullptr){
		delete base;
		base = nullptr;
	}
	
	base = new Base(&sample,11);
	sample.display();
	base->show();
	
		if(base != nullptr){
		delete base;
		base = nullptr;
	}
	
	Sample sample1(base,13);
	sample1.display();
	
	return 0;
}