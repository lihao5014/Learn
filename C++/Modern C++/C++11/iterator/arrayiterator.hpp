/*1.迭代器的作用：
 *迭代器对于任何自定义的类序列都是一个强大的附加工具。它允许我们将算法运用到有
 *自定义类元素的容器上。可能会出现一种情形，没有可以满足我们需要的标准STL容器，
 *这时候就需要定义一个自己的容器。我们的容器类可能需要迭代器。通过深入理解什么
 *样的类（定义了迭代器）才能被STL所接受，可以让我们了解到STL内部发生了些什么。
 */

/*2.STL迭代器的要求：
 *（1）STL对定义了迭代器的类类型有一些特定的要求。这是为了保证所有接受这种迭代器的算法
 *     都可以正常工作。算法不需要知道，也不在乎它所处理的元素来自何种容器，但是它们在意
 *     传给它们作为参数的迭代器的特性。不同的算法要求不同功能的迭代器。STL中有5类迭代器：
 *     输入迭代器、输出迭代器、前向迭代器、双向迭代器和随机访问迭代器。我们总是可以在需要
 *     低级别迭代器的地方使用高级别迭代器。
 *（2）定义算法的模板需要决定可传入迭代器的类别，用来验证所传入的迭代器的功能是否足够。
 *     知道迭代器参数的类别能为算法的应用提供潜在的优势，可以充分利用任何最少的额外功能
 *     让算法更加高效。
 *（3）一般来说，必须用标准的方式确认迭代器的功能。不同类别的迭代器意味着需要为迭代器类
 *     定义不同的成员函数集。我们知道迭代器类别具有功能叠加性，这当然也会反映到每种类别
 *     的成员函数集上。
 *（4）如果想要定义自己容器的迭代器，并想通过迭代器调用STL的算法函数的话。首先继承iteroter，
 *     然后实现必要的操作符即可。不过具体的算法函数对迭代器类型是有要求的，这个需要自己把握。
 */

/*3.使用STL迭代器存在的问题：
 *（1）定义一个参数中有迭代器的函数模板会产生一个问题，我们并不总是知道在函数模板中要用到
 *     哪些类型的迭代器，因为不同迭代器支持的运算各不相同。
 *（2）函数模板参数为迭代器类型时，如果在函数体中需要定义一个迭代器所指向对象类型的临时变量，
 *     即使我们知道迭代器指向值的类型却无计可施，因为直到模板生成实例时，才能确定对象的类型。
 *     在不知道对象的类型时，我们无法定义这个临时变量。在C++11中可以使用auto/decltype关键字
 *     进行自动类型推导。
 */

#ifndef _ARRAY_ITERATOR_HPP_
#define _ARRAY_ITERATOR_HPP_

#ifndef _ARRAY_PRIVATE_HEADER_
	#error "arrayiterator.h can only be included by array.h"
#endif

#include <iterator>

namespace Study {

template <typename T,int N>
class Array;

/*随机访问迭代器支持输入迭代器、输出迭代器、前向迭代器和双向迭代器的所有操作，
 *是支持运算最多的迭代器，
 */
template <typename U>
class ArrayIterator:public std::iterator<std::random_access_iterator_tag,U>
{
	template <typename T,int N>
	friend class Array;
	
	/*因为自定义的模板迭代器继承std::iterator迭代器基类时，编译器会认为它继承自std::iterator
	 *迭代器基类的一个特例化std::iterator<std::random_access_iterator_tag,U>，而特例化版本中
	 *不包含使用typedef定义的5种类型别名，所以自定义的模板迭代器继承不了value_type、pointer、
	 *reference、difference_type和iterator_category这5种自定义类型。基于这个原因C++17中已经
	 *弃用了<iterator>头文件。
	 */
	// using base = std::iterator<std::random_access_iterator_tag, U>;
	// using typename base::iterator_category;
	// using typename base::value_type;
	// using typename base::difference_type;
    // using typename base::pointer;
    // using typename base::reference;
public:
	/*****所有类型的迭代器都支持以下4种操作*****/
	ArrayIterator(const ArrayIterator& other);
	ArrayIterator& operator =(const ArrayIterator& other);
	
	ArrayIterator& operator ++();              //重载前缀递增运算符（++a）
	ArrayIterator operator ++(int);     //重载后缀递增运算符（a++）
	
	/*****输入迭代器特有操作，只有输出迭代器不支持以下2种操作*****/
	bool operator ==(const ArrayIterator& other)const;
	bool operator !=(const ArrayIterator& other)const;
	
	/*****以下2种操作在输入迭代器和输出迭代器中的定义不相同*****/
	U& operator *()const;         //输入迭代器中定义为: const U& operator *()const;
	U* operator ->()const;        //输入迭代器中定义为: const U* operator ->()const;
	
	/*****双向迭代器特有操作，只有输入迭代器、输出迭代器和前向迭代器不支持以下3种操作*****/
	ArrayIterator& operator --();              //重载前缀递增运算符（++a）
	ArrayIterator operator --(int);   
	
	/*****随机迭代器特有操作，输入迭代器、输出迭代器、前向迭代器和双向迭代器都不支持以下操作*****/
	bool operator <(const ArrayIterator& other)const;
	bool operator >(const ArrayIterator& other)const;
	
	bool operator <=(const ArrayIterator& other)const;
	bool operator >=(const ArrayIterator& other)const;
	
	ArrayIterator& operator +=(int n);
	ArrayIterator& operator -=(int n);

	U& operator [](int index)const;
	
	/*（1）对继承自std::iterator的迭代器进行模板化时，因为编译器不能排除您尝试提供std::iterator的特殊化，
	 *     所以编译器会认为你正在对继承的std::iterator模板进行特例化，而difference_type不属于它的类型定义，
	 *     所以在模板定义时，从属名称永远不能解释为typedef。
	 *（2）使用typename ArrayIterator<U>::difference_type向编译器指示difference_type是成员类型。
	 *（3）虽然每次都可以使用typename显式限定它们，但您可以做的是这样声明一次，并在ArrayIterator定义的其余
	 *     部分中依靠该声明：
	 *     using base = std::iterator<std::random_access_iterator_tag, U>;
	 *     using typename base::iterator_category;
	 *     using typename base::value_type;
     *     using typename base::pointer;
     *     using typename base::reference;
     *     using typename base::difference_type;
	 */
	typename ArrayIterator<U>::difference_type operator -(const ArrayIterator<U>& iter)const;
	
	template <typename T>
	friend ArrayIterator<T> operator +(const ArrayIterator<T>& iter,int n);
	
	template <typename T>
	friend ArrayIterator<T> operator +(int n,const ArrayIterator<T>& iter);
	
	template <typename T>
	friend ArrayIterator<T> operator -(const ArrayIterator<T>& iter,int n);
	
private:
	ArrayIterator(U* p);    //不能显式的构造ArrayIterator迭代器，只能通过Array友元类或拷贝构造函数来创建ArrayIterator迭代器。
	
	U* m_ptr;   //实际的内容指针，通过该指针跟容器连接
};

template <typename U>
ArrayIterator<U>::ArrayIterator(U* p)
	:m_ptr(p)
{
	
}

template <typename U>
ArrayIterator<U>::ArrayIterator(const ArrayIterator<U>& other)
	:m_ptr(other.m_ptr)
{
	
}

template <typename U>
ArrayIterator<U>& ArrayIterator<U>::operator =(const ArrayIterator<U>& other)
{
	m_ptr = other.m_ptr;
	return *this;
}

template <typename U>
ArrayIterator<U>& ArrayIterator<U>::operator ++()
{
	m_ptr++;
	return *this;
}

template <typename U>
ArrayIterator<U> ArrayIterator<U>::operator ++(int)
{
	ArrayIterator<U> temp = *this;
	
	m_ptr++;
	return temp;
}

template <typename U>
bool ArrayIterator<U>::operator ==(const ArrayIterator<U>& other)const
{
	return m_ptr == other.m_ptr;
}

template <typename U>
bool ArrayIterator<U>::operator !=(const ArrayIterator<U>& other)const
{
	return m_ptr != other.m_ptr;
}

template <typename U>
U& ArrayIterator<U>::operator *()const
{
	return *m_ptr;
}

template <typename U>
U* ArrayIterator<U>::operator ->()const
{
	return m_ptr;
}

template <typename U>
ArrayIterator<U>& ArrayIterator<U>::operator --()
{
	m_ptr--;
	return *this;
}

template <typename U>
ArrayIterator<U> ArrayIterator<U>::operator --(int)
{
	ArrayIterator<U> temp(m_ptr);
	
	m_ptr--;
	return temp;
}

template <typename U>
bool ArrayIterator<U>::operator <(const ArrayIterator<U>& other)const
{
	return m_ptr < other.m_ptr;
}

template <typename U>
bool ArrayIterator<U>::operator >(const ArrayIterator<U>& other)const
{
	return m_ptr > other.m_ptr;
}

template <typename U>
bool ArrayIterator<U>::operator <=(const ArrayIterator<U>& other)const
{
	return m_ptr <= other.m_ptr;
}

template <typename U>
bool ArrayIterator<U>::operator >=(const ArrayIterator<U>& other)const
{
	return m_ptr >= other.m_ptr;
}

template <typename U>
ArrayIterator<U>& ArrayIterator<U>::operator +=(int n)
{
	m_ptr += n;
	return *this;
}

template <typename U>
ArrayIterator<U>& ArrayIterator<U>::operator -=(int n)
{
	m_ptr -= n;
	return *this;	
}

template <typename U>
U& ArrayIterator<U>::operator [](int index)const
{
	return m_ptr[index];
}

template <typename T>
typename ArrayIterator<T>::difference_type ArrayIterator<T>::operator -(const ArrayIterator<T>& iter)const
{
	return m_ptr - iter.m_ptr;
}

template <typename T>
ArrayIterator<T> operator +(const ArrayIterator<T>& iter,int n)
{
	ArrayIterator<T> temp = iter;
	
	temp.m_ptr += n;
	return temp;
}

template <typename T>
ArrayIterator<T> operator +(int n,const ArrayIterator<T>& iter)
{
	return iter + n;
}

template <typename T>
ArrayIterator<T> operator -(const ArrayIterator<T>& iter,int n)
{
	ArrayIterator<T> temp= iter;
	
	temp.m_ptr -= n;
	return temp;	
}

}  //namespace Study

#endif  //_ARRAY_ITERATOR_HPP_