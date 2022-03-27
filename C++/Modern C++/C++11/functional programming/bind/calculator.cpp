#include "calculator.h"
#include <stdio.h>
#include <assert.h>
#include <functional>

data_t plus(data_t x,data_t y)
{
	return x + y;
}

data_t minus(data_t x,data_t y)
{
	return x - y;
}

data_t multiplies(data_t x,data_t y)
{
	return x * y;
}

data_t divides(data_t x,data_t y)
{
	assert(y != 0);
	return x / y;
}

#if (_CHANGE_WAY_ & 0b0001)
data_t calculate(data_t x,data_t y,Operator_t opt)
{
	switch(opt){
	case ADD:
		return plus(x,y);
	case SUB:
		return minus(x,y);
	case MULT:
		return multiplies(x,y);
	case DIVI:
		return divides(x,y);
	default:
		printf("opt is illegal!\n");
	}
	
	return 0;
}
#elif (_CHANGE_WAY_ & 0b0010)
data_t calculate(data_t x,data_t y,Operator_t opt)
{
	std::map<Operator_t,pFun>::const_iterator citer = g_operatorMap.find(opt);
	if(citer == g_operatorMap.end())
	{
		printf("opt is illegal!\n");
		return 0;
	}

	return citer->second(x,y);
}
#elif (_CHANGE_WAY_ & 0b0100)
data_t calculate(data_t x,data_t y,Operator_t opt)
{
	std::map<Operator_t,pFun> operatorMap = {
		{ADD,[](data_t x,data_t y){return x + y;}},
		{SUB,[](data_t x,data_t y){return x - y;}},
		{MULT,[](data_t x,data_t y){return x * y;}},
		{DIVI,[](data_t x,data_t y){assert(y != 0);return x / y;}}
	};
	
	std::map<Operator_t,pFun>::iterator iter = operatorMap.find(opt);
	if(iter == operatorMap.end())
	{
		printf("opt is illegal!\n");
		return 0;
	}

	return iter->second(x,y);
}
#elif (_CHANGE_WAY_ & 0b1000)
data_t calculate(data_t x,data_t y,Operator_t opt)
{
	using pf = data_t(data_t,data_t);
	std::function<pf> add = [](data_t x,data_t y){return x + y;};
	std::function<pf> sub = [](data_t x,data_t y){return x - y;};
	std::function<data_t(data_t,data_t)> mult = [](data_t x,data_t y){return x * y;};
	std::function<data_t(data_t,data_t)> divi = [](data_t x,data_t y){assert(y != 0);return x / y;};
	
	std::map<Operator_t,std::function<pf>> operatorMap = {
		{ADD,add},
		{SUB,sub},
		{MULT,mult},
		{DIVI,divi}
	};
	
	std::map<Operator_t,std::function<pf>>::iterator iter = operatorMap.find(opt);
	if(iter == operatorMap.end())
	{
		printf("opt is illegal!\n");
		return 0;
	}

	return iter->second(x,y);
}
#endif //_CHANGE_WAY_