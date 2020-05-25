#include "teacher.h"
#include "student.h"
#include <iostream>

int main()
{
	Teacher teacher("class begin!");
	Student amy("amy");
	teacher.attach(&amy);
	Student bob("bob");
	teacher.attach(&bob);
	teacher.notify();
	
	teacher.setContext("stand up");
	teacher.notify();
	
	std::cout<<"teacher context :"<<teacher.getContext()<<std::endl;
	std::cout<<"amy note :"<<amy.getNote()<<std::endl;
	std::cout<<"bob note :"<<bob.getNote()<<std::endl;
	
	return 0;
}