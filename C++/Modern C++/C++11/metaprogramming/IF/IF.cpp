/*1.元函数：
 *（1）C++的模板元编程是函数式编程，所以函数是一等公民。一切在编译期间执行的函数都可以称为元函数。
 *     元函数有struct/class和constexpr两种定义方式。C++98/03之前只能使用struct/class模板定义元函数，
 *     从C++11标准后可以使用constexpr常量表达式函数的方式定义元函数。constexpr字面意思是常量表达式，
 *     因此表达式内部不允许出现运行期可以改变的量。
 *（2）在元函数中一切都是可计算的，也就是说数值和类型都是可以计算的量。这和运行期的函数存在差异。
 *（3）只要能在编译期间完成计算，而且不会产生副作用的表达式，都可以作为元函数。
 */

/*2.编译时测试：
 *（1）编译时测试相当于面向过程编程中的选择语句，可以实现if else/switch的选择逻辑。编译时测试的
 *     对象主要包括两种：常量表达式和类型。
 *（2）在C++17之前，编译时测试是通过模板的实例化和特化实现的，即每次找到最特殊的模板进行匹配；
 *     而C++17提出了使用constexpr if的编译时测试方法。
 *（3）编译时测试表达式：类似于静态断言，编译时测试的对象是常量表达式，即编译时能得出结果的表达式。
 *     以不同的常量表达式作为参数，可以构造各种需要的模板重载。
 *（4）编译时测试类型：在元编程的很多应用场景中，需要对类型进行测试，即对不同的类型实现不同的功能。
 *     而常见的测试类型又分为2种：判断一个类型是否为特定的类型和判断一个类型是否满足某些条件。
 *     前者可以通过对模板的特化直接实现；后者既能通过替换失败不是错误SFINAE规则进行最优匹配，
 *     又能通过标签派发匹配可枚举的有限情况。
 */

/*3.SFINAE：(Substitution Failure Is Not An Error——替换失败不是错误)
 *（1）为了更好的支持SFINAE，C++11的type_traits类型特征头文件中除了提供类型检查的谓词模板is_*和has_*，
 *     还提供了两个重要的辅助模板std::enable_if和std::void_t。
 *（2）std::enable_if：将对条件的判断转化为常量表达式，类似测试表达式实现重载的选择，
 *     但需要添加一个冗余的函数参数/函数返回值/模板参数。
 *（3）std::void_t：直接检查依赖的成员/函数是否存在，不存在则无法重载，可以用于构造谓词，
 *     再通过std::enable_if判断条件。
 */

#include <iostream>
#include "cppstd.h"

#define _CHANGE_WAY_
// #undef _CHANGE_WAY_

using namespace std;

//编译时测试表达式：构造谓词isZero<Val>，编译时判断Val值是不是0。
template <unsigned int val>
struct _IsZero
{
	static const bool value = false;
};

template <>
struct _IsZero<0>
{
	static const bool value = true;
};

#ifdef HAS_CPP_14
template <unsigned int val>
constexpr bool isZero = _IsZero<val>::value;    //变量模板在C++14中才得到支持
#endif

//编译时测试类型：构造谓词isVoid<T>，编译时判断T类型是不是void。
template <typename T>
struct _IsVoid
{
	enum{value = false};
};

template <>
struct _IsVoid<void>
{
	enum{value = true};
};

#ifdef HAS_CPP_14
template <typename T>
constexpr bool isVoid = _IsVoid<T>::value;
#endif

/*struct类型的元函数TypeReplace完成类型转换的功能，用type表示传进来的数据类型，如果是int类型，
 *则转换成unsgned int类型，利用模板重载来实现。注意模板元函数的参数是在尖括号<>内部传入的，
 *这一点和运行期函数是不同的。
 */
template <typename T>
struct TypeReplace
{
	typedef T type;
};

template <>
struct TypeReplace<int>
{
	typedef unsigned int type;
};

template <typename T>
using typeReplace = typename TypeReplace<T>::type;

/*利用模板局部特化的能力，编译时的类型分支选择可以很容易做到。
 *元函数IF是模板元编程中最简单但运用得最多的基础设施。
 */
#ifndef _CHANGE_WAY_
template <bool B,typename T,typename U>
struct IF
{
	typedef T type;
};

template <typename T,typename U>
struct IF<false,T,U>                     //局部特化
{
	typedef U type;
};
#else
//有某些旧式编译器并不支持模板局部特化，这种情况下增加一层包装就可以巧妙地转为使用全局特化。
template <bool B>
struct IF_impl
{
	template <typename T,typename U>
	struct result
	{
		typedef T type;
	};
};

template <>
struct IF_impl<false>
{
	template <typename T,typename U>
	struct result
	{
		typedef U type;
	};
};

template <bool B,typename T,typename U>
struct IF
{
	typedef typename IF_impl<B>::template result<T,U>::type type;
};
#endif

int main(void)
{
#if defined(__GNUC__) || defined(__clang__)
	cout<<"C++ version: "<<__cplusplus<<endl;
#elif defined(_MSC_VAR)
	cout<<"C++ version: "<<__MSVC_LANG<<endl;
#endif

#if HAS_CPP_14
	static_assert(!isZero<1>,"1 != 0");    //尖括号就相当于实际的参数传入，只不过在编译期间完成计算。
	static_assert(isZero<0>,"0 == 0");
#elif HAS_CPP_11
	static_assert(!_IsZero<5>::value,"5 != 0");
	static_assert(_IsZero<0>::value,"0 == 0");
#else
#pragma message("Using C++98 standard!")
	cout<<"_IsZero<5>::value == 0 ? "<<_IsZero<5>::value<<endl;    //static_assert()静态断言功能是C++11才引入的。
	cout<<"_IsZero<0>::value == 0 ? "<<_IsZero<0>::value<<endl;
#endif	

#if HAS_CPP_14
	cout<<"isVoid<int>::value == ? "<<isVoid<int><<endl;
	cout<<"isVoid<void>::value == ? "<<isVoid<void><<endl;
#elif HAS_CPP_11
	cout<<"_IsVoid<int>::value =="<<_IsVoid<int>::value<<endl;
	cout<<"_IsVoid<void>::value =="<<_IsVoid<void>::value<<endl;
#endif

	TypeReplace<double>::type a = 3.14;
	TypeReplace<int>::type b = 5;
	typeReplace<char> c = 'a';
	typeReplace<int> d = -5;
	cout<<"a ="<<a<<" , "<<"b ="<<b<<" , "<<"c ="<<c<<" , "<<"d ="<<d<<endl;
	
	//定义一个指定字节数长度类型的变量。如果没有指定长度的类型，则编译报错。
	IF<true,int,double>::type x = 10;
	IF<false,int,double>::type y = 0.618;
	cout<<"x ="<<x<<" , "<<typeid(x).name()<<endl;
	cout<<"y ="<<y<<" , "<<typeid(y).name()<<endl;
	
	const int len = 4;
    typedef
		IF<sizeof(char) == len, char,
		IF<sizeof(short)==len, short,
        IF<sizeof(int)==len, int,
        IF<sizeof(long)==len, long,
        void>::type>::type>::type>::type lenType;
	
	lenType var = 20;
	cout<<"var ="<<var<<" , sizeof(var) ="<<sizeof(var)<<endl;
}