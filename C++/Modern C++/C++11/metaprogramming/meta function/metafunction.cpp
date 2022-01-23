/*1.元编程：（C++语言 = C语言的超集 + 抽象机制 + 标准库）
 *（1）元编程是通过操作程序实体，在编译时计算出运行时需要的常数、类型和代码的方法。
 *     一般的编程是通过直接编写程序，通过编译器编译，产生目标代码，并用于运行时执行。
 *     与普通的编程不同，元编程则是借助语言提供的模板机制，通过编译器推导，在编译时生成程序。
 *     元编程经过编译器推导得到的程序，再进一步通过编译器编译，产生最终的目标代码。
 *（2）元编程又被成为两级编程、生成式编程或模板元编程。在元函数中一切都是可计算的，
 *     也就是说数值和数据类型都是可以计算的量。这和运行期的函数存在差异。
 */

/*2.C++中的两种主要抽象机制：
 *（1）面向对象编程：为了实现面向对象编程，C++提供了类class，用C++的已有类型构造出新的类型。
 *（2）模板编程：在模板编程方面C++提供了模板template，以一种直观的方式表示通用概念。
 */

/*3.模板编程的两种主要：
 *（1）泛型编程：注重于通用概念的抽象，设计通用的类型或算法，不需要过于关心编译器如何生成具体的代码。
 *     模板的设计初衷仅是用于泛型编程，对数据结构和算法进行抽象。
 *（2）元编程：注重于设计模板推导时的选择和迭代，通过模板技巧设计程序。由于元编程不同于一般的编程，
 *     在程序设计上更具有挑战性，所以受到了许多学者和工程师的广泛关注。
 */

#include <iostream>
#include "cppstd.h"

using namespace std;

/*C++的模板元编程是函数式编程，所以函数是一等公民。一切在编译期间执行的函数都可以称为元函数。
 *元函数有struct/class和constexpr两种定义方式。C++98/03之前只能使用struct/class模板定义元函数，
 *从C++11标准后可以使用constexpr常量表达式函数的方式定义元函数。constexpr字面意思是常量表达式，
 *因此表达式内部不允许出现运行期可以改变的量。
 */
#ifndef HAS_CPP_11
template <int N,int M>
struct MetaFunc
{
	static const int value = N + M;
};
#else
constexpr int metaFunc(int x,int y)     //constexpr是C++11标准中新添加的关键字
{
	return x + y;
}
#endif

/*只有vs2015 update3以上版本的编译器才支持使用/std选项指定C++标准，且msvc编译器只能指定C++14以上标准。
 *无法指定C++98、C++03和C++11标准。
 */
#ifndef HAS_CPP_14
template <int n>
class IsOdd
{
public:
	static const bool value = ((n % 2 == 0) == 1);
};
#else
template <int n>
constexpr static bool isOdd = ((n % 2 == 0) == 1);
#endif

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

/*C++中不用循环和递归，打印从1至N的自然数。由于print是函数模板，所以print<N>调用的print<N-1>并非自身，
 *因此不是递归。编译器在实例化print<N>的时候，由于它调用了print<N-1>，所以在编译期会递归地实例化下去，
 *直到遇见全特化的print<1>为止。元编程利用编译器在编译期的递归替代运行期的递归，巧妙地绕过了原始问题的限制。
 */
template <int N>
void print()
{
	cout<<N<<" ";
	print<N-1>();
}

/*不过既然是递归，就有可能爆栈。编译器递归实例化的深度是有限制的。clang3.4的默认限制是256层，
 *而gcc8.2的默认限制是900层。超过这一限制会引发编译器Fatal error而编译失败。
 */
template <>
void print<1>()
{
	cout<<1<<endl;
}

int main(void)
{
#if defined(__GNUC__) || defined(__clang__)
	cout<<"C++ version: "<<__cplusplus<<endl;
#elif defined(_MSC_VAR)
	cout<<"C++ version: "<<__MSVC_LANG<<endl;
#endif
	
#ifndef HAS_CPP_11
#pragma message("Don't have C++11 standard!")
	int arr[MetaFunc<2,3>::value] = {0};
#else
#pragma message("Have C++11 standard!")
	int arr[metaFunc(3,4)] = {0};
#endif
	cout<<"arr len ="<<sizeof(arr)/sizeof(arr[0])<<endl;

#ifndef HAS_CPP_14
#pragma message("Don't have C++14 standard!")
	bool ret = IsOdd<17>::value;
#else
#pragma message("Have C++14 standard!")
	bool ret = isOdd<17>;
#endif
	cout<<"17 is odd number"<<endl;

#if HAS_CPP_11
	static_assert(!_IsZero<5>::value,"5 != 0");
	static_assert(_IsZero<0>::value,"0 == 0");
#elif HAS_CPP_14
	static_assert(!isZero<1>,"1 != 0");
	static_assert(isZero<0>,"0 == 0");
#else
#pragma message("Using C++98 standard!")
	cout<<"_IsZero<5>::value == 0 ? "<<_IsZero<5>::value<<endl;    //static_assert()静态断言功能是C++11才引入的。
	cout<<"_IsZero<0>::value == 0 ? "<<_IsZero<0>::value<<endl;
#endif

	const int num = 10;
	print<num>();
	
	return 0;
}
