#ifndef _ALGORITHM_HPP_
#define _ALGORITHM_HPP_

#include "iterator_traits.hpp"

namespace Learn {
	
template <class Iterator,class Function>
void foreach(Iterator first,Iterator last,Function fun)
{
	while(first != last)
	{
		fun(*first);
		first++;
	}
}

template <typename ForwardIterator,class T>
void fill(ForwardIterator first,ForwardIterator last,const T& val)
{
	while(first != last)
	{
		*first = val;
		++first;
	}
}

template <typename ForwardIterator,class Generator>
void generate(ForwardIterator first,ForwardIterator last,Generator gen)
{
	for(;first != last;++first)
	{
		*first = gen();
	}
}

template <typename InputIterator,typename UnaryPredicate>
InputIterator find_if(InputIterator first,InputIterator last,UnaryPredicate pred)
{
	for(;first != last;++first)
	{
		if(pred(*first))
		{
			return first;
		}
	}
	
	return last;
}

template <class OutputIterator>
void swap(OutputIterator first,OutputIterator last)
{
	typename iterator_traits<OutputIterator>::value_type temp = *first;
	*first = *last;
	*last = temp;
}
	
}  // namespace Learn

#endif