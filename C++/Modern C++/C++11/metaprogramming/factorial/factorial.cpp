/*泛型编程主要就是利用模板实现“安全的宏”，而模板元编程区别于我们所知道的泛型编程，
 *它是一种较为复杂的模板编程，属于C++的高阶操作了，它最主要的优点就在于把计算过程
 *提前到编译期，能带来可观的性能提升。
 */

/*1.C++模板元编程的概念：
 *（1）元编程metaprogramming的前缀“meta-”表示“处于较高发展状态”的意思，从这个意义上讲，
 *     元编程指的就是高阶的编程，即编写一种程序，使得这种程序可以把某些程序作为输入数据，
 *     生成或操作其他的程序。一般而言这些高阶的程序运行在编译时。因此元编程并非一个新概念，
 *     事实上任何一种高级语言的编译器都可以视为元编程的工具，因为它们的程序必须被转换为
 *     汇编语言或者机器语言以后，才能够运行在计算机上。
 *（2）C++强大的模板机制赋予了模板在编译时的运算能力。模板特化可以用于实现编译期的分支结构。
 *     目前元编程已经成为C++语言的一项庞大分支，C++代码拥有了编译期和运行期的两段执行能力。
 */

/*2.模板元编程的基本用途：
 *（1）数值计算：数值计算是模板元编程的最简单直接的使用方法。数值计算主要利用模板的特化和局部特化
 *     能力进行递归演算，模板类被视为元函数，利用类中的一个静态常量保存结果。由于C++模板对非类型
 *     的参数有限制，一般只有整型和布尔型可以参加运算。元函数的结果一般放在一个静态的常量中，
 *     但对于整型而言还有一个更好的选择，就是可以放置在枚举中，其唯一的优点是静态常量是左值，
 *     必须在运行期占有内存地址，也就是分配了内存空间，而枚举值不能作为左值，所以不占用内存空间，
 *     显得有些微的优势。
 *（2）循环展开：编译期的循环展开可以通过模板特化来结束递归展开，达到运行期的for和while语句的功能。
 *（3）类型处理：对类型的处理是模板元编程最重要和最具有现实意义的应用。由于模板可以接受类型参数，
 *     也可以通过typedef或定义内嵌类建立模板类的成员类型，再加以强大的模板特化的能力，使得类型计算
 *     几乎能有着数值计算所有的全部能力。
 *（4）自动生成代码：泛型编程和循环展开技术其实已经是一种代码生成了。此外代码生成在设计模式中也有
 *     广泛的应用，可以避免传统设计模式耦合度较高的缺点，提高程序灵活性。
 */

/*3.模板元编程在数值计算上的不足：
 *（1）运算范围仅限于整型和布尔型，用途有限。
 *（2）递归式的编程难于实行和理解。
 *（3）C++编译器对编译期的递归都是有一定的限制的，C++标准建议进行17层递归实例化，
 *     这无疑不能满足稍复杂的程序。
 *（4）大量消耗编译器资源的同时，降低了编译效率。
 *（5）无论是编译期的递归还是运行期内存的节省，对比起模板元编程在数值计算上的不足，
 *     都显得有点得不偿失。因此用模板元编程作编译期数值计算，并不在实践中经常使用，
 *     但它作为一个“中心设施”在MPL库中发挥着重要的作用。
 */

/*4.模板元编程在类型处理中的应用：
 *（1）类型分支选择：利用模板局部特化的能力，编译时的类型选择可以很容易做到。
 *（2）类型的数据结构：把类型作为普通数据一样管理，这初看起来有点匪夷所思：普通数据可以运用
 *     struct或者array来组织，但C++并没有为类型提供一个专用的数据结构，可以利用的唯一设施是
 *     模板的参数列表。
 */

/*5.用合适的数据结构组织类型，可以得到以下好处：
 *（1）编译时可以根据情况自动决定选择的类型。
 *（2）由于模板中没有数据成员，它们在运行时不占用任何空间。
 *（3）可以运用于代码的自动生成，或者实现某种设计模式。
 */

#include <iostream>

#define _CHANGE_WAY_
#undef _CHANGE_WAY_

using namespace std;

/*Factorial在传统意义上是一个类模板，但用元编程的观点去看待则可以认为是一个元函数。
 *这个元函数接受一个整型的模板参数，它的返回值是元函数的一个静态成员。注意元函数
 *与普通的函数很不一样。一方面元函数往往需要定义一个以上的特化版本作为终结条件，
 *另一方面元函数的返回值需要显式地提取出来。
 */
#ifndef _CHANGE_WAY_
template <int N>
struct Factorial
{
	static const int value = N * Factorial<N - 1>::value;
};

//借助于模板的特化能力形成递归，所有运算都在编译时完成。
template <>
struct Factorial<1>
{
	static const int value = 1;    //静态常量是左值必须为其分配内存空间。
};
#else
template <int N>
struct Factorial
{
	enum{value = N * Factorial<N - 1>::value};
};

template <>
struct Factorial<1>
{
	enum{value = 1};    //枚举值不能作为左值，所以不占用内存空间
};
#endif

#ifndef _CHANGE_WAY_
constexpr int factorial_11(int n)   //C++11中constexpr常量表达式函数里面，只能包含一条return语句。
{
	return n == 1 ? 1 : n * factorial_11(n - 1);
}
#else
template <int N>
constexpr int factorial_11()
{
	return N * factorial_11<N - 1>();
}

template <>
constexpr int factorial_11<1>()
{
	return 1;
}
#endif

#ifndef _CHANGE_WAY_
constexpr int factorial_14(int n)   //C++14中constexpr函数体里面可以使用局部变量、选择语句和循环语句。
{
	if(1 == n) return 1;
	return n * factorial_14(n - 1);
}
#else
constexpr int factorial_14(int n)
{
	int ret = 1;
	for(int i=1;i<=n;++i)
	{
		ret *= i;
	}
	return ret;
}
#endif

template <int N>
struct constN
{
	constN(){cout<<"constN: "<<N<<endl;}
};

int main()
{
	static_assert(Factorial<4>::value == 24,"Factorial<4>::value != 24");
	cout<<"Factorial<4>::value ="<<Factorial<4>::value<<endl;

#ifndef _CHANGE_WAY_
	int arr[factorial_11(3)] = {0};
	cout<<"arr len ="<<sizeof(arr)/sizeof(arr[0])<<endl;
#else
	constN<factorial_11<5>()> out;
#endif
	
	enum{
		a = factorial_14(3),
		b = factorial_14(4),
		c = factorial_14(5)
	};
	cout<<"b ="<<b<<endl;
	
	return 0;
}