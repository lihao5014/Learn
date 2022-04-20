/*1.编译时迭代:
 *（1）编译时迭代和面向过程编程中的循环语句类似，用于实现与for/while/do类似的循环逻辑。
 *     编译时迭代又分为两种：定长模板的迭代和变长模板的迭代。
 *（2）在C++17之前，编译时迭代与普通的编程不同，因为元编程的演算规则只是针对于纯函数的，
 *     不能通过变量迭代实现编译时迭代，只能用递归和特化的组合实现。一般思路是提供两类重载，
 *     一类接受任意参数，内部递归调用自己；另一类是前者的模板特化或函数重载，直接返回结果，
 *     相当于递归终止条件。它们的重载条件可以是表达式或类型。而C++17提出了折叠表达式的语法，
 *     化简了编译时迭代的写法。
 */

/*2.变长模板与折叠表达式：
 *（1）C++11引入变长模板时，就支持了在模板内直接展开参数包的语法，但该语法仅支持对参数包
 *     里的每个参数进行一元操作，为了实现参数间的二元操作，必须借助额外的模板实现。
 *（2）C++17引入了折叠表达式，允许直接遍历参数包里的各个参数，对其应用二元运算符进行左折叠或右折叠。
 */

#include <iostream>
#include "cppstd.h"

#define _CHANGE_WAY_
// #undef _CHANGE_WAY_

using namespace std;

//定长模板的迭代
template <int M,int N>
struct Power
{
	static const long value = M * Power<M,N - 1>::value;
};

template <int M>
struct Power<M,1>
{
	static const long value = M;
};

#ifdef HAS_CPP_14
#ifndef _CHANGE_WAY_
template <int M,int N>
const long power = Power<M,N>::value;   //在msvc编译器中，认为此时const修饰的power不是常量，而是只读变量。
#else
template <int M,int N>
constexpr long power = Power<M,N>::value;	
#endif
#endif

//变长模板的迭代：为了遍历变长模板的每个参数，可以使用编译时迭代实现循环遍历。
template <typename T>
constexpr auto Accumulate()    //Accumulate()函数没有参数的重载。
{
	return T(0);
}

/*函数Accumulate()有两个重载：一个是对没有函数参数的情况，一个是对函数参数个数至少为1的情况。
 *和定长模板的迭代类似，这里也是通过递归调用实现参数遍历。
 */
template <typename T,typename... Ts>
constexpr auto Accumulate(T arg,Ts... args)
{
	return arg + Accumulate<T>(args...);
}

//使用折叠表达式化简编译时迭代：代码使用初始值为0的左折叠表达式，对代码进行改进。
template <typename... Ts>
constexpr auto summation(Ts... args)
{
	return (0 + ... + args);
}

int main(void)
{
#if defined(__GNUC__) || defined(__clang__)
	cout<<"C++ version: "<<__cplusplus<<endl;
#elif defined(_MSC_VAR)
	cout<<"C++ version: "<<__MSVC_LANG<<endl;
#endif

	int arr[Power<3,2>::value] = {0};
	cout<<"arr len ="<<sizeof(arr)/sizeof(arr[0])<<endl;

#ifdef HAS_CPP_14
	enum {
		a = Power<2,2>::value,
		b = Power<2,3>::value,
		c = power<2,4>,
		d = power<2,5>
	};
	
	cout<<"a ="<<a<<" , "<<"b ="<<b<<" , "<<"c ="<<c<<" , "<<"d ="<<d<<endl;
#endif

	constexpr double x = Accumulate(1.0,3.14,2,0.618,3,2.718);
	cout<<"x ="<<x<<endl;
	
	const double y = summation(1.0,3.14,2,0.618,3,2.718);
	cout<<"y ="<<y<<endl;

	return 0;
}