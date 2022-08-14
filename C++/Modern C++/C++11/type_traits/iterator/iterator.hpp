/*1.ptrdiff_t的定义：
 *（1）ptrdiff_t定义在stddef.h（cstddef）这个文件内。ptrdiff_t通常被定义为long int类型。
 *     ptrdiff_t定义在C99标准中。
 *（2）ptrdiff_t是C/C++标准库中定义的一个与机器相关的数据类型。ptrdiff_t类型变量通常用来
 *     保存两个指针减法操作的结果。
 */

/*2.ptrdiff_t与size_t的区别：
 *（1）标准库类型ptrdiff_t与size_t类型一样，ptrdiff_t也是一种与机器相关的类型，在cstddef头文件中定义。
 *（2）size_t是unsigned类型,而ptrdiff_t则是signed整型。
 *（3）size_t类型用于指明数组长度，它必须是一个正数。ptrdiff_t类型则应保证足以存放同一数组中两个指针之间的差距，
 *     它有可能是负数。
 */

#ifndef _ITERATOR_HPP_
#define _ITERATOR_HPP_

#include <cassert>
#include <cstddef>
#include "iterator_traits.hpp"

namespace Learn {

template <typename Category,
		  typename T,
		  typename Distance = ptrdiff_t,
		  typename Pointer = T*,
		  typename Reference = T&>
struct iterator
{
	typedef Category iterator_category;
	typedef T value_type;
	typedef Distance difference_type;
	typedef Pointer pointer;
	typedef Reference reference;
};

template <class InputIterator, class Distance>
void __advance(InputIterator& iter,Distance n,input_iterator_tag)
{
	assert(n >= 0);
	for(int i=0;i<n;++i,++iter);
}

template <typename BidirectionalIterator,typename Distance>
void __advance(BidirectionalIterator& iter,Distance n,bidirectional_iterator_tag)
{
	if(n >= 0)
	{
		while(n-->0) ++iter;
	}
	else
	{
		for(int i=n;i<0;++i) --iter;
	}
}

template <typename RandomAccessIterator,typename Distance>
void __advance(RandomAccessIterator& iter,Distance n,random_access_iterator_tag)
{
	iter += n;
}

template <class InputIterator, class Distance>
void advance(InputIterator& iter,Distance n)
{
	typedef typename iterator_traits<InputIterator>::iterator_category category;
	__advance(iter,n,category());
}

template <typename InputIterator>
int __distance(InputIterator first,InputIterator last,input_iterator_tag)
{
	int result = 0;
	while(first != last)
	{
		first++;
		result++;
	}
	return result;
}

template <typename BidirectionalIterator>
int __distance(BidirectionalIterator first,BidirectionalIterator last,bidirectional_iterator_tag)
{
	int result = 0;
	for(;last-- != first;++result);
	return result;
}

template <typename RandomAccessIterator>
int __distance(RandomAccessIterator first,RandomAccessIterator last,random_access_iterator_tag)
{
	return last - first;
}

template <typename Iterator>
int distance(Iterator first,Iterator last)
{
	typedef typename iterator_traits<Iterator>::iterator_category category;
	return __distance(first,last,category());
}

}   // namespace Learn

#endif  //_ITERATOR_HPP_