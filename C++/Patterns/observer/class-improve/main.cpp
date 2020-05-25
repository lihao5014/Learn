#include "teacher.h"
#include "student.h"
#include <iostream>

int main()
{
	Teacher teacher("class begin!");
	Student amy("amy");
#if 1
	amy.setSubject(&teacher);
#else
	teacher.attach(&amy);
#endif
	Student bob("bob",&teacher);
	teacher.notify();
	
	teacher.setContext("stand up");
	teacher.notify();
	
	Teacher teacher1("math class");
	amy.setSubject(&teacher1);
	bob.setSubject(&teacher1);
	teacher1.notify();
	std::cout<<"debug start"<<std::endl;
	teacher.notify();
	std::cout<<"debug end"<<std::endl;
	
	std::cout<<"teacher context :"<<teacher.getContext()<<std::endl;
	std::cout<<"amy note :"<<amy.getNote()<<std::endl;
	std::cout<<"bob note :"<<bob.getNote()<<std::endl;
	
	return 0;
}