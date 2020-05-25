#include "math.h"
#include <stdlib.h>
#include <iostream>

#define TOTAL_USE_MATH_SDK
// #undef TOTAL_USE_MATH_SDK

#ifdef _TRACK_
#define DEBUG(str)    \
	std::cout<<str<< __FILE__ << " : " << __func__ << " : " << __LINE__ <<std::endl;
#else
#define DEBUG()
#endif

int main(int argc,char* argv[])
{
	printf("argv[1] =%f, argv[2] =%c, argv[3] =%f\n",atof(argv[1]),strToChar(argv[2]),atof(argv[3]));
	
	if(argc != 4)
	{
		puts("input parameter is illegal");
		return 0;
	}

#ifndef TOTAL_USE_MATH_SDK	
	SignalMap_t signalMap;
	signalMap.insert(SignalPair_t(ADD,add));
	signalMap.insert(SignalPair_t(SUB,sub));
	signalMap[MUT] = mut;
	signalMap[DIV] = div;
	
	char ch = strToChar(argv[2]);
	SignalMapIter_t iter = signalMap.find(static_cast<Signal_t>(ch));
	if(iter != signalMap.end())
	{
		iter->second(atoi(argv[1]),atoi(argv[3]));
	}
#else
	initMath();
	calculate(atoi(argv[1]),atoi(argv[3]),strToChar(argv[2]));
#endif
	
	return 0;
}