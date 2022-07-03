/*STL中实现了很多算法（<algorithm>头文件）。如果项目是基于STL构建，那么能够最大化使用现有代码，
 *大大提高软件开发的效率。在STL中容器和算法之间的桥梁是迭代器。所以在定义好自定义类型的容器后，
 *接下来就是迭代器的实现。
 */

/*1.iterator迭代器：
 *（1）迭代器是一种抽象的设计概念，现实程序语言中并没有直接对应于这个概念的实物。
 *     在设计模式中迭代器模式是指：提供一种方法，使之能够依序访问某个聚合物（容器）
 *     所含的各个元素，而又无须暴露该聚合物的内部表述方式。
 *（2）迭代器是STL的关键所在：将数据容器和算法分开，彼此独立设计，最后再用桥梁将
 *     它们联系在一起，这个桥梁就是迭代器。
 *（3）std::iterator是提供以简化迭代器所要求类型定义的基类。在C++17标准中<iterator>
 *     头文件已被弃用。
 *（4）STL定义了iterator迭代器模板，用来帮助我们在自己的迭代器类中包含要求的类型别名。
 *     iterator是一个结构体模板，它定义了5个来自于std::iterator_traits模板的类型别名。
 */

/*2.iterator迭代器源码：
 *	template <typename Category,                 // iterator::iterator_category
 *            typename T,                        // iterator::difference_type
 *            typename Distance = ptrdiff_t,     // iterator::value_type
 *			  typename Pointer = T*,             // iterator::pointer
 *            typename Reference = T&>           // iterator::reference
 *  struct iterator
 *  {
 *      typedef Category iterator_category;
 *      typedef T value_type;
 *      typedef Distance difference_type;
 *      typedef Pointer pointer;
 *      typedef Reference reference;
 *  };
 *
 *（1）迭代器模式是一种经典的设计模式，而STL的迭代器实现用到了模板的一些特性和技能，
 *     在std::iterator的源码中，大量使用typedef定义类型别名，是为了给后面的算法多态
 *     和萃取时使用的。其中的Category和T模板参数没有默认值，需要自己给参数的。
 *（2）value_type：是指对象的类型，每一个打算与STL算法完美搭配的class，都应该定义
 *     自己的value_type内嵌类型。
 *（3）difference_type：用来表示2个迭代器的距离，因此它可以用来表示容器的最大容量。
 *     通常用于STL中泛型算法提供的计数功能。例如STL中的count()和distance()。
 *（4）reference：表示迭代器所指之物。以迭代器所指之物的内容是否允许改变，可以将迭代器
 *     分为2类，constant iterator和mutable iterator。
 *  ① constant iterator：不允许改变“所指对象之内容者”称为constant iterator。
 *  ② mutable iterator；允许改变“所指对象之内容者”称为mutable iterator。
 *（5）pointer：表示迭代器所指之物的地址。
 *（6）iterator_category：表示迭代器的种类。根据移动特性与施行操作迭代器被分为5类。
 *  ① Input Iterator输入迭代器：所指的对象，不允许外界改变，只读。
 *  ② Output Iterator输出迭代器：所指的对象，不允许外界读取，只写。
 *  ③ Forward Iterator前向迭代器：允许写入型算法在此种迭代器所形成的区间上进行读写操作。
 *  ④ Bidirectional Iterator双向迭代器：可双向移动，某些算法需要逆向走访某个区间。
 *  ⑤ Random Access Iterator随机访问迭代器：支持operator[]、+n、-n、+=n或-=n等运算操作。
 *（7）前4种迭代器只提供一部分指针算术能力，前3种支持operator++，第4种支持operator--，
 *     第5种则涵盖所有指针算术能力，包括operator[]。
 */
 
/*3.模板元编程中的标签tag：
 *标签tag一般是一个空类，其作用是作为一个独一无二的类型名字，用于标记一些东西。典型的例子是STL
 *中迭代器的五种类型的名字：input_iterator_tag、output_iterator_tag、random_access_iterator_tag、
 *bidirectional_iterator_tag和forward_iterator_tag。实际上vector<int>::iterator::iterator_category
 *就是random_access_iterator_tag，可以使用type_traits的特性is_same来判断类型是否相同。有了这样的判断，
 *还可以根据判断结果做更复杂的元编程逻辑（如一个算法以迭代器为参数，根据迭代器标签进行特例化以对某种
 *迭代器特殊处理）。标签还可以用来分辨函数重载。
 */

/*4.STL迭代器的5种标签tag：
 *（1）struct input_iterator_tag {};
 *（2）struct output_iterator_tag {};
 *（3）struct forward_iterator_tag : public input_iterator_tag {};
 *（4）struct bidirectional_iterator_tag : public forward_iterator_tag {};
 *（5）struct random_access_iterator_tag : public bidirectional_iterator_tag {};
 */

/*5.使用tag标签区分迭代器种类的原因：
 *因为我们在设计算法时，应该针对某种强化的迭代器提供另一种定义，这样才能提供最大的效率。
 *任何一个迭代器，其类型应该落在"该迭代器所隶属的各种类型中最强化的那个"，例如int*既是
 *RandomAccess Iterator，又是Bidirectional Iterator，同时也是Forward Iterator，而且也是
 *Input Iterator，那么其类型应该归属为RandomAccess iterator。
 */

#include <iostream>
#include <algorithm>
#include "array.hpp"
#include "algorithm.hpp"

#define UNUSED(x) (void)x;

using namespace	Study;

template <class T>
void print(const T& t)
{
	std::cout<<t<<" ,";
}

auto main(int argc,char* argv[]) -> int
{
	UNUSED(argc);
	UNUSED(argv);
	
	int seq[] = {0,1,2,5,5,5,5,7,8,9};
	
	/*因为使用了traits技法将Study::swap()函数模板对于原生指针和自定义迭代器的支持实现了统一。
	 *所以调用Study::swap()函数时，即可传入普通指针，也可以传入迭代器。
	 */
	Study::swap(seq,seq + 5);
	
	Study::foreach(seq,seq + sizeof(seq)/sizeof(int),print<int>);
	std::cout<<std::endl;
	
	/*直接使用普通指针也可以调用Study::count()函数，因为STL通过模板偏特化技术使得迭代器也支持
	 *原生指针。把访问容器中元素的功能都交给了迭代器，我们就可以对所有的容器用统一的方式访问了，
	 *而不用暴露每个容器的实现细节。
	 */
	int ret = Study::count(seq,seq + sizeof(seq)/sizeof(seq[0]),5);
	std::cout<<"count 5 in seq: "<<ret<<std::endl;
	
	int* p = std::find(seq,seq + sizeof(seq)/sizeof(int),7);
	if(p != seq + sizeof(seq)/sizeof(int))
	{
		std::cout<<"find 7 in seq: "<<p - seq<<std::endl;
	}
	else
	{
		std::cout<<"can't find 7 in seq!"<<std::endl;
	}
	
	Array<int> arr1(3);
	::foreach(arr1.begin(),arr1.end(),print<int>);   //调用自定义的foreach()算法函数。
	std::cout<<std::endl;
	
	arr1.front() = 1;
	arr1[2] = 5;
	arr1.back() = 7;
	std::cout<<"arr1.at(1) ="<<arr1.at(1)<<" ,arr1.size() ="<<arr1.size()<<" ,arr1.empty() ="<<arr1.empty()<<std::endl;
	
	Array<int>::const_iterator citer = arr1.cbegin();
	for(;citer != arr1.cend();++citer)
	{
		std::cout<<*citer<<" ,";
	}
	std::cout<<std::endl;

#ifndef _CHANGE_WAY_
	int n = Study::count(arr1.cbegin(),arr1.cend(),3);
	Array<int>::iterator iter = ::find(arr1.begin(),arr1.end(),5);
#else
	int n = std::count(arr1.cbegin(),arr1.cend(),3);
	Array<int>::iterator iter = std::find(arr1.begin(),arr1.end(),5);
#endif
	std::cout<<"count 3 in arr1: "<<n<<std::endl;
	
	if(iter != arr1.end())
	{
		std::cout<<"find 5 in arr1: "<<iter - arr1.begin()<<std::endl;
	}
	else
	{
		std::cout<<"can't find 5 in arr1!"<<std::endl;
	}
	
	/*（1）自定义迭代器ArrayIterator的设计遵循的了STL标准库中迭代器设计规则，
	 *     所以可以使用ArrayIterator迭代器调用<algorithm>头文件的通用算法函数。
	 *（2）自定义容器Array和标准的std::array，用迭代器去访问，并通过迭代器使用
	 *     std::for_each()函数，可以看到用法完全一样.
	 */
	Array<double,5> arr2 = {3.14,2.718,1.414,0.618,1.732};
	std::for_each(arr2.cbegin(),arr2.cend(),print<typename Array<double,5>::data_type>);     //调用STL标准库中的for_each()算法函数。
	std::cout<<std::endl;
	
	::swap(arr2.begin(),2 + arr2.begin());
	for(auto val : arr2)        //自定义的容器只要提供了begin()/end()成员函数或std::begin()/std::end()函数重载，就可以支持范围for循环。
	{
		std::cout<<val<<" ,";
	}
	std::cout<<std::endl;
	
	return 0;
}