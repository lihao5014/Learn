#include "variable.h"
#include <iostream>

int main()
{
#ifndef _DUMMY_
	initVariable();
#endif

	std::string str = "hello world";
	printf("str =%s\n",str);                  //使用printf打印std::string时会出现乱码
	std::cout<<"str ="<<str<<std::endl;
	
	std::cout<<"variable name is "<<variable[VAR_NAME]<<std::endl;
	std::cout<<"variable unit is "<<variable[UNIT_INDEX]<<std::endl;
	std::cout<<"variable data type is "<<variable[DATA_TYPE]<<std::endl;
	
	return 0;
}