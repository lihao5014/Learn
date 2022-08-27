#ifndef _DEBUG_H
#define _DEBUG_H

#include <iostream>

using std::cout;
using std::endl;

#define _DEBUG_ON_
#undef _DEBUG_ON_

#ifdef _DEBUG_ON_
#define Debug(str) cout<<"["<<__TIME__<<" "<<__FILE__<<"] "<<__func__<<" (line:"<<__LINE__<<") -- "<<str<<endl;
#else
#define Debug(str)
#endif


#endif //_DEBUG_H