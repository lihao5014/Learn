#ifndef _MAP_REDUCE_H
#define _MAP_REDUCE_H

#include <vector>
#include <functional>

template <typename T>
void map(std::vector<T>& vec,std::function<T(T)> fun)
{
	for(T& n : vec)
	{
		n = fun(n);
	}
}

template <typename T>
T reduce(const std::vector<T>& vec,T init,std::function<T(T,T)> fun)
{
	T result = init;
	typename std::vector<T>::const_iterator citer = vec.cbegin();
	for(;citer != vec.cend();++citer)
	{
		result = fun(result,*citer);
	}
	
	return result;
}

#endif  //_MAP_REDUCE_H