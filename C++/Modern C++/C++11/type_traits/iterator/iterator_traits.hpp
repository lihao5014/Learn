/*1.iterator_traits迭代器特性萃取器：
 *（1）iterator_traits模板类型定义在头文件<iterator>中。这个模板为迭代器的类型特性定义了
 *     一套标准的类型别名，让算法既可以用迭代器，也可以用一般的指针。
 *（2）struct和class在本质上是相同的，除了结构体的成员默认是public。iterator_traits结构体
 *     模板中没有成员变量和成员函数，它的主体只包含类型别名的定义。这些别名以Iterator作为
 *     类型参数的模板。它在模板的类型别名difference_type、value_type和pointer等，以及用来
 *     生成迭代器模板实例的类型，与对应Iterator的类型参数之间定义了映射。这可以帮我们有效
 *     地解决了不知道模板定义中类型是什么的问题。
 *（3）当以迭代器为参数定义函数模板时，可以在模板中使用std::iterator_traits里定义的标准类型别名。
 *     MyIterator迭代器代表的指针类型总是可以作为std::iterator_traits<MyIterator>::pointer引用，
 *     因为它等同于MyIterator::pointer。当需要指定一个MyIterator迭代器所指向值的类型时，可以写作
 *     std::iterator_traits<MyIterator>::value_type，这将会被映射为Mylterator::value_type。
 *（4）模板不是代码，它是编译器用来生成代码的配方。iterator_traits模板只包含类型别名，因此不会产生
 *     可执行代码。编译器在生成C++代码的过程中会用到它。被编译的代码中将不会有iterator_traits模板的踪迹；
 *     它的唯一用武之地是在生成C++代码的过程中。
 *（5）
 */

/*2.iterator_traits迭代器特性萃取机中定义的5种类型别名：
 *（1）difference_type：表示两个迭代器之间差别值的类型。
 *（2）value_type：表示迭代器所指向值的类型。
 *（3）pointer：表示迭代器所指向值的地址类型。
 *（4）reference：表示迭代器所指向值的引用类型。
 *（5）iterator_category：迭代器的标签类型，它们有input_iterator_tag、output_iterator_tag、
 *     forward_iterator_tag、bidirectional_iterator_tag和random_access_iterator_tag这5种。
 *（6）一个满足STL要求的自定义迭代器类必须全部定义这些别名。但对于输出迭代器，除了iterator_category，
 *     所有的别名都可以定义为 void。这是因为输出迭代器指向对象的目的地址而不是对象。这套迭代器提供了
 *     我们所想知道的关于迭代器的一切。
 */

/*3.iterator_traits模板的普通指针特例化：
 *（1）为了让STL算法像接受迭代器一样接受普通指针。iterator_traits模板特化了类型T*和const T*的定义。
 *（2）当iterator_traits模板类型参数是指针类型时，特例化版本定义了对应于别名的类型。T*类型的指针
 *     value_type的别名总是为T。
 *（3）随机访问迭代器类别所要求的全部操作都可以运用到指针上。因此对于指针，iterator_categor的别名
 *     总是等同于std::random_access_iterator_tag类型。因而iterators_traits能否正常工作取决于模板
 *     类型参数是指针还是迭代器类类型。当模板类型参数是指针时，会选择使用iterators_traits针对指针
 *     的特例化模板；否则选择标准的模板定义。
 */

#ifndef _ITERATOR_TRAITS_HPP_
#define _ITERATOR_TRAITS_HPP_

namespace Learn {

struct input_iterator_tag {};
struct output_iterator_tag{};
struct forward_iterator_tag : public input_iterator_tag {};
struct bidirectional_iterator_tag : public forward_iterator_tag {};
struct random_access_iterator_tag : public bidirectional_iterator_tag {};

template <typename Iterator>
struct iterator_traits
{
	typedef typename Iterator::iterator_category iterator_category;
	typedef typename Iterator::value_type value_type;
	typedef typename Iterator::difference_type difference_type;
	typedef typename Iterator::pointer pointer;
	typedef typename Iterator::reference reference;
};

template <typename T>
struct iterator_traits<T*>
{
	typedef random_access_iterator_tag iterator_category;
	typedef T value_type;
	typedef ptrdiff_t difference_type;
	typedef T* pointer;
	typedef T& reference;
};

template <typename T>
struct iterator_traits<const T*>
{
	typedef random_access_iterator_tag iterator_category;
	typedef T value_type;
	typedef ptrdiff_t difference_type;
	typedef const T* pointer;
	typedef const T& reference;
};

}  // namespace Learn

#endif  //_ITERATOR_TRAITS_HPP_