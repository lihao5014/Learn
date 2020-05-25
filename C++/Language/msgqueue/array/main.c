#include "msgqueue.h"

#define _PERSET_VALUE_
#undef _PERSET_VALUE_

int main(int argc,char** argv)
{
#ifdef _PERSET_VALUE_
	Signal_t msgArr[] = {
		{4,5,ADD},
		{7,8,SUB},
		{3.14159,2.17828,MULT},
		{20,10,DIVI},
		{9,6,MAX},
		{14,5,MIN}
	};
	
	initMsg(msgArr,sizeof(msgArr)/sizeof(msgArr[0]));
	processMsg();
#else
	msgLoop();
#endif
	return 0;
}