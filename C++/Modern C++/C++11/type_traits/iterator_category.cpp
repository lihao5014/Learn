/*1.STL中容器、迭代器和算法直接的关系：
 *（1）在STL编程中，容器和算法是独立设计的，即数据结构和算法是独立设计的，连接容器和算法的桥梁
 *     就是迭代器了，迭代器使其独立设计成为可能。
 *（2）STL标准库的目标就是要把数据和算法分开，分别对其进行设计，之后通过一种名为iterator的东西，
 *     把这二者再粘接到一起。
 */

/*2.STL标准库中提供的算法具有的特征：
 *（1）函数参数一般包括迭代器iterator。
 *（2）要根据iterator的种类和iterator包装的元素的类型等信息，来决定使用最优化的算法。
 *     如果是vector的iterator，那么就可以使用+、-、+=和-=操作；如果是list的iterator，
 *     那么就不可以使用+、-、+=和-=操作，只能使用++和--运算符。总之算法必须知道一些
 *     关于iterator的信息。
 *（3）有一些容器对应的iterator是一个类，并在该类中定义了5种类型信息。有了这5种类型
 *     信息的定义，算法就能够知道iterator的基本情况，可以正常工作了。
 *     template<typename T>
 *     struct __list_iterator
 *     { 
 *         typedef bidirectional_iterator_tag    iterator_category;
 *         typedef T                             value_type;
 *         typedef T*                            pointer;
 *         typedef T&                            reference;
 *         typedef ptrdiff_t                     difference_type;
 *     };
 *
 *（4）但vector和array的迭代器iterator并不是类，而是C++里内置的指针。当把原始指针作为参数传递给算法后，
 *     算法无法得知iterator中定义的iterator_category、value_type、pointer、reference和difference_type
 *     等信息，算法就无法工作。为了解决这个问题，就需要添加一个中间层，也就是创建一个iterator_traits类，
 *     它包装了iterator，并使用模板局部特化技术。
 *（5）traits是萃取机的意思，也就是萃取iterator里的信息并给到算法。算法向iterator_traits类要它需要的信息，
 *     iterator_traits再向iterator要，如果要到了就使用；如果没有要到，就使用iterator_traits提供的类型信息。
 */

/*3.特性萃取技术traits在迭代器和算法设计中的应用：
 *（1）设计模式中关于iterator的描述为：一种能够顺序访问容器中每个元素的方法，使用该方法不能暴露
 *     容器内部的表达方式。而类型萃取技术就是为了要解决和iterator有关的问题的。
 *（2）迭代器将for_each()、find()、count()等泛型算法用于某个容器中，最重要的是要给算法提供一个访问
 *     容器中元素的工具，iterator就扮演着这个重要的角色。而在算法中我们可能会定义简单的中间变量或者
 *     设定算法的返回变量类型，这时候需要知道迭代器所指元素的类型是什么。但是由于没有typeof这类判断
 *     类型的函数，所以我们无法直接获取，这时候就需要使用traits特性萃取技术。
 *（3）迭代器是一种不管理内存的智能指针，它拥有一般指针的所有特点，即能够对其进行*解引用和->指针操作。
 *     但是在遍历容器的时候，不可避免的要对遍历的容器内部有所了解，所以干脆把迭代器的开发工作交给容器
 *     的设计者好了。如此一来所有实现细节，反而得以封装起来不被使用者看到，这正是为什么每一种STL容器
 *     都提供有专属迭代器的缘故。
 *（4）总而言之，迭代器是指向序列元素的指针的一种抽象。通过使用迭代器，我们可以访问序列中的某个元素、
 *     改变序列中的某个元素的值、使迭代器向前或向后行走等。
 */

/*迭代器中定义了5种数据类型，其中value_type, difference_type, reference_type, pointer_type这4种类型都比较
 *容易在traits和相应偏特化中提取。但是iterator_category一般也有5个，该类型会引发较大规模的写代码工程。
 */

#include <assert.h>
#include <iostream>
#include <iterator>       //iterator_traits,input_iterator_tag,bidirectional_iterator_tag,random_access_iterator_tag
#include <forward_list>
#include <list>
#include <array>

#define _ERROR_
#undef _ERROR_

#define _CHANGE_WAY_
// #undef _CHANGE_WAY_

#define _DEBUG_
#undef _DEBUG_

#ifdef _DEBUG_
#define Debug(str) std::cout<<"["<<__TIME__<<" "<<__FILE__<<"] "<<__func__<<" (line:"<<__LINE__<<") -- "<<(str)<<std::endl;
#else
#define Debug(str) (void)0
#endif

#define UNUSED(x) (void)x;

using namespace std;

template <typename Iterator>
bool is_random_access_iterator(Iterator iter)
{
	typedef typename iterator_traits<Iterator>::iterator_category category;
	return is_same<category,std::random_access_iterator_tag>::value;
}

template <typename Iterator>
bool is_bidirectional_iterator(Iterator iter)
{
	typedef typename iterator_traits<Iterator>::iterator_category category;
	return is_same<category,std::bidirectional_iterator_tag>::value;	
}

template <typename InputIterator>
int distance_input_iterator(InputIterator first,InputIterator last)
{
	Debug("input iterator");
	
	int ret = 0;
	while(first != last)
	{
		first++;
		ret++;
	}
	return ret;
}

template <typename BidirectionalIterator>
int distance_bidirectional_iterator(BidirectionalIterator first,BidirectionalIterator last)
{
	Debug("bidirectional iterator");
	
	int result = 0;
	for(;last-- != first;++result);
	return result;
}

template <typename RandomAccessIterator>
int distance_random_access_iterator(RandomAccessIterator first,RandomAccessIterator last)
{
	Debug("random access iterator");
	return last - first;
}

template <typename InputIterator>
int __distance(InputIterator first,InputIterator last,std::input_iterator_tag)
{
	Debug("input iterator");
	
	int ret = 0;
	while(first != last)
	{
		first++;
		ret++;
	}
	return ret;
}

template <typename BidirectionalIterator>
int __distance(BidirectionalIterator first,BidirectionalIterator last,std::bidirectional_iterator_tag)
{
	Debug("bidirectional iterator");
	
	int result = 0;
	for(;last-- != first;++result);
	return result;
}

template <typename RandomAccessIterator>
int __distance(RandomAccessIterator first,RandomAccessIterator last,std::random_access_iterator_tag)
{
	Debug("random access iterator");
	return last - first;
}

template <typename Iterator>
typename iterator_traits<Iterator>::iterator_category iterator_category(Iterator)
{
	typedef typename iterator_traits<Iterator>::iterator_category category;
	return category();
}

#ifdef _ERROR_
/*（1）因为if-else语句属于运行期的条件判断，不能用于编译期分支选择，所有的if条件分支都会被编译。
 *     所以只有同时支持-、--和++操作的随机访问迭代器才能编译通过。
 *（2）没有使用trais类型特性萃取技术，在运行阶段才能确定，调用哪种迭代器类型的distance_*_iterator()方法。
 */
template <typename Iterator>
int distance(Iterator first,Iterator last)
{
	if(is_random_access_iterator(first))
	{
		return distance_random_access_iterator(first,last);    //需要迭代器支持-运算符
	}
	else if(is_bidirectional_iterator(first))
	{
		return distance_bidirectional_iterator(first,last);    //需要迭代器支持--运算符
	}
	else
	{
		return distance_input_iterator(first,last);            //需要迭代器支持++运算符
	}
}
#else  //_ERROR_
#ifndef _CHANGE_WAY_
//C++17的constexpr if语句提供了编译时测试的新写法，让模板测试更加直观，提高了模板代码的可读性。
template <typename Iterator>
int distance(Iterator first,Iterator last)
{
	typedef typename iterator_traits<Iterator>::iterator_category iterator_category;
	
	if constexpr(is_same<iterator_category,std::random_access_iterator_tag>::value)
	{
		return distance_random_access_iterator(first,last);
	}
	else if constexpr(is_same<iterator_category,std::bidirectional_iterator_tag>::value)
	{
		return distance_bidirectional_iterator(first,last);
	}
	else
	{
		return distance_input_iterator(first,last);
	}
}
#else  //_CHANGE_WAY_
/*distance()算法向特性萃取器iterator_traits要iterator_category的信息。如果iterator能提供，就使用iterator里的
 *iterator_category，如果iterator不能提供，就使用iterator_traits里的iterator_category。得到iterator_category后，
 *就可以在编译阶段确定调用哪一个__distance()方法了。在编译阶段就可以确定，比在运行阶段确定调用哪个__distance()
 *方法的效率要高。
 */
template <typename Iterator>
int distance(Iterator first,Iterator last)
{
	return ::__distance(first,last,iterator_category(first));
}
#endif  //_CHANGE_WAY_
#endif  //_ERROR_

auto main(int argc,char* argv[]) -> int
{
	UNUSED(argc);
	UNUSED(argv);
	
	//原始指针属于随机访问迭代器
	int seq[] = {0,1,2,3,4,5,6,7,8,9};
	int *p = seq;
	int num = ::distance(p,p + sizeof(seq)/sizeof(int));
	cout<<"raw pointer: num ="<<num<<endl;

#ifndef _ERROR_
	//测试前向迭代器
	forward_list<double> forwardList = {3.14,2.718,0.618,1.414,9.78};
	forward_list<double>::iterator forward_iter = forwardList.begin();
	
	for(int i=0;i<2;i++,forward_iter++);
	num = ::distance(forward_iter,forwardList.end());
	cout<<"*forward_iter ="<<*forward_iter<<" ,num ="<<num<<endl;
	
	//测试双向迭代器
	list<int> myList = {20,21,22,23,24,25,26,27,28,29};
	list<int>::iterator bidirectional_iter = myList.end();
	
	for(int i=0;i<3;i++,bidirectional_iter--);
	num = ::distance(myList.begin(),bidirectional_iter);
	cout<<"*bidirectional_iter ="<<*bidirectional_iter<<" ,num ="<<num<<endl;
#endif

	//测试随机访问迭代器
	array<char,5> arr = {'a','b','c','d','e'};
	array<char,5>::iterator random_access_iter = arr.begin();
	
	num = ::distance(random_access_iter,random_access_iter + 3);
	cout<<"*random_access_iter ="<<*random_access_iter<<" ,num ="<<num<<endl;
	
	return 0;
}