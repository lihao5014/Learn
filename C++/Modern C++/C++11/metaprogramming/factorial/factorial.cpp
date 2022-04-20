/*1.C++模板元编程的概念：
 *（1）元编程metaprogramming的前缀“meta-”表示“处于较高发展状态”的意思，从这个意义上讲，
 *     元编程指的就是高阶的编程，即编写一种程序，使得这种程序可以把某些程序作为输入数据，
 *     生成或操作其他的程序。一般而言这些高阶的程序运行在编译时。因此元编程并非一个新概念，
 *     事实上任何一种高级语言的编译器都可以视为元编程的工具，因为它们的程序必须被转换为
 *     汇编语言或者机器语言以后，才能够运行在计算机上。
 *（2）C++强大的模板机制赋予了模板在编译时的运算能力。模板特化可以用于实现编译期的分支结构。
 *     目前元编程已经成为C++语言的一项庞大分支，C++代码拥有了编译期和运行期的两段执行能力。
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