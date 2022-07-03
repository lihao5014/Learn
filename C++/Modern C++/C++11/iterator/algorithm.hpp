#ifndef _ALGORITHM_HPP_
#define _ALGORITHM_HPP_

#define _ERROR_
#undef _ERROR_

#define _CHANGE_WAY_
// #undef _CHANGE_WAY_

#include <iterator>

namespace Study {

/*foreach()算法中用到了迭代器中的拷贝构造、后++、!=不等于、*解引用运算。
 *所以想要通过迭代器调用foreach()函数，传入的迭代器必须支持以上4种运算。
 *正好输入迭代器就是满足这4种运算要求的最低级别迭代器，所以foreach()函数
 *支持输入迭代器、前向迭代器、双向迭代器和随机访问迭代器类型参数。
 */
template <typename InputIterator,class Function>
void foreach(InputIterator first,InputIterator last,Function fun)
{
	while(first != last)
	{
		fun(*first);
		first++;
	}
}

/*使用迭代器我们不需要关心容器的具体类型，也不需要关心T的具体实现，
 *就能够对不同的容器进行查找操作。
 */
template <typename InputIterator,typename T>
InputIterator find(InputIterator first,InputIterator last,const T& value)   //查找范围[first,last)
{
	for(;first != last;++first)
	{
		if(*first == value)
		{
			return first;
		}
	}
	
	return last;
}

//迭代器中的difference_type类型，通常用于STL中泛型算法提供的计数功能。
template <typename InputIterator,typename T>
auto count(InputIterator first,InputIterator last,const T& value) -> typename std::iterator_traits<InputIterator>::difference_type    //统计[first,last)范围中，数值value出现的次数。
{
	typename std::iterator_traits<InputIterator>::difference_type n = 0;
	for(;first != last;++first)
	{
		if(*first == value)
		{
			n++;
		}
	}
	
	return n;
}

#ifdef _ERROR_
/*swap()函数模板的实例用来交换迭代器所指向的两个对象。局部变量temp应该是什么类型
 *我们没法知道，即使知道迭代器指向对象的类型却无计可施，因为直到类模板生成实例时，
 *才能确定对象的类型。在不知道对象的类型时，可以使用auto定义变量。但在一些情况下，
 *我们也想知道迭代器类型的值和类型差别。
 */
template <typename ForwardIteraor>
void swap(ForwardIteraor first,ForwardIteraor last)    //迭代器作为参数的交换函数，模板类型参数指定了迭代器类型。
{
	temp = *first;      //error：variable temp undeclared
	*first = *last;
	*last = temp;
}
#else   //_ERROR_
#ifndef _CHANGE_WAY_
/*除了auto或decltype变量类型自动推导外，还有些其他的机制可以确定一个迭代器所指向值的类型。
 *其中一种是坚持要求每个使用swap()函数的迭代器，都应该包含一个公共定义的类型别名value_type，
 *这样就可以使用在迭代器中定义的value_type类型别名，来指定swap()中temp变量的类型。
 */
template <typename ForwardIteraor>
void swap(ForwardIteraor first,ForwardIteraor last)
{
	typename ForwardIteraor::value_type temp = *first;
	*first = *last;
	*last = temp;
}
#else  //_CHANGE_WAY_
/*因为value_type别名定义在迭代器类中，所以可以通过typename ForwardIteraor::value_type的方式引用它。
 *这样定义了value_type别名的迭代器类，就能在swap()函数中正常使用。然而STL中算法既支持指针类型参数，
 *也支持迭代器。如果ForwardIteraor是普通类型的指针，这样swap()函数可能就无法使用了。因为指针不是类，
 *不能包含定义的别名，所以不能写成int*::value_type。STL中用traits特性萃取技术，优雅地解决了这个问题。
 */
template <typename ForwardIteraor>
void swap(ForwardIteraor first,ForwardIteraor last)
{
	typename std::iterator_traits<ForwardIteraor>::value_type temp = *first;
	*first = *last;
	*last = temp;
}
#endif  //_CHANGE_WAY_
#endif  //_ERROR_

}  //namespace Study

#endif  //_ALGORITHM_HPP_
