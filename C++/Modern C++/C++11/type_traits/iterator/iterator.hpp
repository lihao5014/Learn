/*1.ptrdiff_t的定义：
 *（1）ptrdiff_t定义在stddef.h（cstddef）这个文件内。ptrdiff_t通常被定义为long int类型。
 *     ptrdiff_t定义在C99标准中。
 *（2）ptrdiff_t是C/C++标准库中定义的一个与机器相关的数据类型。ptrdiff_t类型变量通常用来
 *     保存两个指针减法操作的结果。
 */

/*2.ptrdiff_t与size_t的区别：
 *（1）标准库类型ptrdiff_t与size_t类型一样，ptrdiff_t也是一种与机器相关的类型，在cstddef头文件中定义。
 *（2）size_t是unsigned类型,而ptrdiff_t则是signed整型。
 *（3）size_t类型用于指明数组长度，它必须是一个正数。ptrdiff_t类型则应保证足以存放同一数组中两个指针
 *     之间的差距，它有可能是负数。
 */

/*1.std::iterator迭代器基类模板：
 *（1）STL定义了std::iterator迭代器模板，用来帮助我们在自己的迭代器类中包含要求的类型别名。iterator是一个
 *     结构体模板，它定义了5个来自于iterator_traits模板的类型别名。
 *（2）std::iterator模板定义了STL对迭代器所要求的全部类型。如果有一个未知类型的迭代器模板参数MyIterator，
 *     当需要声明一个指针，它指向一个迭代器解引用时提供的类型，这时我们可以写作MyIterator::pointer。迭代器
 *     iterator_category的值必定是5种tag标签类中的一个。
 *（3）当定义一个表示迭代器的类时，可以使用以std::iterator为基类生成的实例，这样会添加类需要的类型别名。
 *     注意需要为迭代器定义STL要求的全部类型。模板的第1个参数指定了作为完全随机访问迭代器的迭代器类型。
 *     第2个参数是迭代器所指向对象的类型。最后的3个参数是默认值，因此第3个参数和这两个迭代器的类型不同，
 *     是ptrdiff_t。第4个参数是一个指向对象的指针类型。最后一个模板参数指定了引用的类型。如果迭代器类型
 *     不做任何事，仍然需要定义类的全部成员。
 */

/*2.STL迭代器成员函数的要求：
 *（1）STL定义了一套需要迭代器类型支持并且依赖迭代器类别的成员函数。所有迭代器类都需要提供的成员函数：
 *     默认构造函数、析构函数、拷贝构造函数以及赋值运算符。
 *（2）对于随机访问迭代器类，STL需要一整套的关系运算符。可以通过使用<utility>标准库头文件中的函数模板
 *     来完成关系运算符的定义。
 *（3）迭代器的其他操作由它的类别决定。每种迭代器都提供了特定操作，而且因为迭代器的累加特性，随机访问
 *     迭代器可以支持全部操作。
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