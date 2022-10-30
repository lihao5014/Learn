#ifndef _DEBUG_H_
#define _DEBUG_H_

#include <iostream>

#ifdef _DEBUG_ON_
#	define TRACK(expr)  \
		std::cout<<"["<<__TIME__<<" "<<__FILE__<<"] "<<__func__<<" (line:"<<__LINE__<<") -- "<<#expr<<" ="<<(expr)<<std::endl;
#else
#	define TRACK(str)
#endif

#endif // _DEBUG_H_