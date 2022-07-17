/*type_traits负责萃取元素类型的特性。如果元素具有某个性质，则我们调用某个函数，
 *如果不具有某个性质，则调用另一个函数。它充分利用了C++模板编程和编译器的参数
 *推导功能（编译器只有面对类类型参数才会进行参数推导）。STL中大量运用了traits
 *编程技巧，通过模板特化，函数重载让编译器选择正确的处理方式，在编译期就能完成
 *函数分发，极大的提高了灵活性。
 */

/*1.traits技术产生的原因：
 *（1）尽管C++的模板技术为泛型编程提供了支持，可以编写更加通用的代码。但是模板参数类型
 *     的不同，往往会带来一些问题，这时候traits会是一种很好的解决方案。
 *（2）因为模板参数的类型不同，可能会影响到模板中具体的算法实现，那么我们就需要把这些
 *     与模板参数相差的方法从模板中提取出来，从而保证算法的一致不受参数类型不同的影响。
 *     而traits模板即是把与模板参数相差的方法都封装起来了。
 */

/*2.traits特性萃取技术：
 *（1）C++的traits技术是一种约定俗称的技术方案，用来为同一类数据（包括自定义类型和内置类型）
 *     提供统一的操作函数。
 *（2）traits技术的关键在于，使用另外的模板类type_traits来保存不同数据类型的type，这样就可以
 *     兼容自定义数据类型和内置数据类型。
 *（3）traits特性萃取技术的本质是加上一层间接性，换来一定的灵活性。
 */

/*3.iterator_traits迭代器萃取机源码：
 *  template<typename Iterator>
 *  struct iterator_traits         //使用iterator提供的信息
 *  {
 *    typedef typename Iterator::iterator_category iterator_category;
 *    typedef typename Iterator::value_type        value_typep;
 *    typedef typename Iterator::difference_type   difference_type;
 *    typedef typename Iterator::pointer           pointer;
 *    typedef typename Iterator::reference         reference;
 *  };
 *  
 *  template<typename T>
 *  struct iterator_traits<T*>           //由于无法使用iterator的信息，所以traits自己提供了。针对原生指针而设计的"偏特化版"
 *  {
 *    typedef random_access_iterator_tag iterator_category;
 *    typedef T                          value_type;
 *    typedef ptrdiff_t                  difference_type;
 *    typedef T*                         pointer;
 *    typedef T&                         reference;
 *  };
 *    
 *  template<typename T>
 *  struct iterator_traits<const T*>     //由于无法使用iterator的信息，所以traits自己提供了。针对原生的pointer-to-const而设计的"偏特化"
 *  {
 *    typedef random_access_iterator_tag iterator_category;
 *    typedef T                          value_type;          //注意这里不是const T。如果是const T，算法拿到这个类型，用该类型定义变量后却无法改变其值，那就没有作用了，所以是T。
 *    typedef ptrdiff_t                  difference_type;
 *    typedef const T*                   pointer;
 *    typedef const T&                   reference;
 *  };
 */

/*4.STL迭代器的5种标签tag：
 *（1）struct input_iterator_tag {};
 *（2）struct output_iterator_tag {};
 *（3）struct forward_iterator_tag : public input_iterator_tag {};
 *（4）struct bidirectional_iterator_tag : public forward_iterator_tag {};
 *（5）struct random_access_iterator_tag : public bidirectional_iterator_tag {};
 *
 *（6）使用继承的好处是，当函数需要用input_iterator_tag的时候，假设你传进一个forward_iterator_tag，
 *     它会沿继承向上找，知道符合条件。
 */

#include <cassert>
#include <iostream>
#include <forward_list>
#include <list>
#include <vector>
#include <iterator>

#define _CHANGE_WAY_
// #undef _CHANGE_WAY_

#define _ERROR_
#undef _ERROR_

#define _DEBUG_
#undef _DEBUG_

#ifdef _DEBUG_
#define Debug(str) std::cout<<"["<<__TIME__<<" "<<__FILE__<<"] "<<__func__<<" (line:"<<__LINE__<<") -- "<<(str)<<std::endl;
#else
#define Debug(str) (void)0
#endif

#define UNUSED(x) (void)x;

using std::forward_list;
using std::list;
using std::vector;

using std::input_iterator_tag;
using std::bidirectional_iterator_tag;
using std::random_access_iterator_tag;

using std::cout;
using std::endl;

template <typename Iterator>
struct Is_RandomAccessIterator
{
	static const bool value = false; 
};

template <>
struct Is_RandomAccessIterator<std::random_access_iterator_tag>
{
	static const bool value = true; 
};

//使用C++14中的变量模板简化元函数的调用
template <typename Iterator>
constexpr bool isRandomAccessIterator = Is_RandomAccessIterator<Iterator>::value;

template <typename Iterator>
struct Is_BidirectionalIterator
{
	enum{value = false};
};

template <>
struct Is_BidirectionalIterator<std::bidirectional_iterator_tag>
{
	enum{value = true};
};

//使用C++14中的变量模板简化元函数的调用
template <typename Iterator>
constexpr bool isBidirectionalIterator = Is_BidirectionalIterator<Iterator>::value;

/*using和typedef属于C++的编译期语法，不会在代码的运行期中执行。所以可以随便添加到全局作用域、
 *名字空间、函数体、类、结构体或联合体的代码块中。
 */
template <typename Iterator>
bool is_random_access_iterator(Iterator iter)
{
	using std::iterator_traits;
	typedef typename iterator_traits<Iterator>::iterator_category iterator_category;
	return Is_RandomAccessIterator<iterator_category>::value;
}

template <typename Iterator>
bool is_bidirectional_iterator(Iterator iter)
{
	using std::iterator_traits;
	typedef typename iterator_traits<Iterator>::iterator_category iterator_category;
	return Is_BidirectionalIterator<iterator_category>::value;	
}

template <typename InputIterator,typename Distance>
void advance_input_iterator(InputIterator& iter,Distance n)
{
	Debug("input iterator");
	
	assert(n >= 0);
	for(int i=0;i<n;++i,++iter);
}

template <typename BidirectionalIterator,typename Distance>
void advance_bidirectional_iterator(BidirectionalIterator& iter,Distance n)
{
	Debug("bidirectional iterator");
	
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
void advance_random_access_iterator(RandomAccessIterator& iter,Distance n)
{
	Debug("random access iterator");
	
	iter += n;
}

/*__advance()中的第3个参数仅仅是激活重载。但我们还需要一个提供上层统一的接口advance()，
 *在这一层中通过traits机制，将迭代器类型推导出来。
 */
template <typename InputIterator,typename Distance>
void __advance(InputIterator& iter,Distance n,input_iterator_tag)
{
	Debug("input iterator");
	
	assert(n >= 0);
	for(int i=0;i<n;++i,++iter);
}

template <typename BidirectionalIterator,typename Distance>
void __advance(BidirectionalIterator& iter,Distance n,bidirectional_iterator_tag)
{
	Debug("bidirectional iterator");
	
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
	Debug("random access iterator");
	
	iter += n;
}

#ifdef _ERROR_
/*（1）模板函数的实例化是在编译期进行的，而if-else语句属于运行期的条件判断，所以不能用于编译期的编译分支选择。
 *     编译器在实例化advance()模板函数时，会将所有的条件分支情况，都进行编译。这样只有传入的迭代器参数iter，
 *     同时支持++、--、+=和-=运算符，才能编译通过。因为随机访问迭代器支持输入迭代器、输出迭代器、前向迭代器和
 *     双向迭代器的所有操作，是支持运算最多的迭代器。所以只有传入随机访问迭代器时，advance()函数才不会编译报错。
 *（2）当调用advance()时需要做一个if-else判断，这样在执行时期才决定使用哪一个版本的迭代器移动函数，会影响程序效率。
 *     最好能够在编译期就选择正确的版本。重载__advance()函数机制可以达成这个目标。
 */
template <typename Iterator,typename Distance>
void advance(Iterator& iter,Distance n)
{
	if(is_random_access_iterator(iter))
	{
		advance_random_access_iterator(iter,n);     //需要迭代器支持+=和-=运算符
	}
	else if(is_bidirectional_iterator(iter))
	{
		advance_bidirectional_iterator(iter,n);     //需要迭代器支持++和--运算符
	}
	else
	{
		advance_input_iterator(iter,n);             //只需需要迭代器支持++运算符即可
	}
}
#else  //_ERROR_
#ifndef _CHANGE_WAY_
/*（1）advanced()函数的作用是使迭代器向前移动n步。在advance()函数中，通过判断不同迭代器类型来
 *     调用不同的函数，以达到最大的效率。
 *（2）判断出参数不同类型的2种方法：
 *  ① 第一种方法是多态，但运行期才确定未免成本太高，同时胡乱继承多态也是把问题复杂化。
 *  ② 第二种就是函数重载，我们可以事先标记不同迭代器类型，并将其作为第3个参数传给__advance()。
 */
template <typename Iterator,typename Distance>
void advance(Iterator& iter,Distance n)
{
	using std::iterator_traits;
	typedef typename iterator_traits<Iterator>::iterator_category iterator_category;
	
	if constexpr(isRandomAccessIterator<iterator_category>)  //C++17的constexpr if提供了编译时测试的新写法，让模板测试更加直观，提高了模板代码的可读性。
	{
		advance_random_access_iterator(iter,n);
	}
	else if constexpr(isBidirectionalIterator<iterator_category>)
	{
		advance_bidirectional_iterator(iter,n);
	}
	else
	{
		static_assert(!isRandomAccessIterator<iterator_category>,"iter is random access iterator");
		static_assert(!isBidirectionalIterator<iterator_category>,"iter is bidirectional iterator");
		
		advance_input_iterator(iter,n);
	}
}
#else
/*（1）因为gcc的标准库中也定义了同名的__advance()函数。为了避免函数调用的歧义，在调用自定义
 *     的__advance()函数，需要加“::”全局作用域符。在gcc编译器中将标准库私有的__advance()函数
 *     暴露了出来，而msvc编译器的标准库中则没有。
 *（2）重载__advance()函数机制可以实现编译期的函数选择。各个迭代器类型的具体重载实现已经写好，
 *     但是需要一个统一的advance()接口，这时候traits就可以出场了。traits在面对不同的输入类时，
 *     能找到合适的返回类型。当该类型对应有不同的函数重载时，能起到一个提取类型然后分流的作用。
 */
template <typename Iterator,typename Distance>
void advance(Iterator& iter,Distance n)
{
	typedef typename std::iterator_traits<Iterator>::iterator_category category;
	::__advance(iter,n,category());    //调用各类型的__advance()函数重载。gcc编译器中也可以改为std::__advance()，从而更改为调用标准库里的同名函数。
}
#endif  //_CHANGE_WAY_
#endif  //_ERROR_

auto main(int argc,char* argv[]) -> int
{
	UNUSED(argc);
	UNUSED(argv);

	//测试前向迭代器
	forward_list<int> forwardList = {0,1,2,3,4,5,6,7,8,9};
	forward_list<int>::iterator forward_iter = forwardList.begin();
	::advance(forward_iter,5);
	cout<<"*forward_iter ="<<*forward_iter<<endl;
	
	::advance(forward_iter,2);
	cout<<"*forward_iter ="<<*forward_iter<<endl;
	
	//测试双向迭代器
	list<double> myList = {3.14,2.718,0.618,1.414,9.78};
	list<double>::iterator bidirectional_iter = myList.begin();
	::advance(bidirectional_iter,4);
	cout<<"*bidirectional_iter ="<<*bidirectional_iter<<endl;
	
	::advance(bidirectional_iter,-2);
	cout<<"*bidirectional_iter ="<<*bidirectional_iter<<endl;
	
	//测试随机访问迭代器
	vector<char> vec = {'a','b','c','d','e'};
	vector<char>::iterator random_access_iter = vec.begin();
	::advance(random_access_iter,3);
	cout<<"*random_access_iter ="<<*random_access_iter<<endl;
	
	::advance(random_access_iter,2);
	cout<<"*random_access_iter ="<<*random_access_iter<<endl;
	
	//原始指针也属于随机访问迭代器
	int arr[] = {20,21,22,23,24,25,26,27,28,29};
	int *ptr = arr;
	::advance(ptr,5);
	cout<<"arr[5] ="<<*ptr<<endl;
	
	::advance(ptr,-2);
	cout<<"arr[3] ="<<*ptr<<endl;
	
	return 0;
}