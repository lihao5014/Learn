/*1.模板元编程（Template Metaprogramming/TMP）：
 *（1）模板元编程是编写生成或操纵程序的程序，也是一种复杂且功能强大的编程范式。模板机制给C++提供了
 *     元编程的能力，但大部分用户对C++模板的使用并不是很频繁，大致限于泛型编程。在一些系统级的代码，
 *     尤其是对通用性、性能要求极高的基础库几乎不可避免在大量地使用C++模板以及模板元编程。
 *（2）模版元编程完全不同于普通的运行期程序，因为模版元程序的执行完全是在编译期，且模版元程序操纵的
 *     数据不能是运行时变量，只能是编译期常量，不可修改。另外它用到的语法元素也是相当有限，不能使用
 *     运行期的一些语法，如if-else、do-while、for和while等语句都不能用。因此模版元编程需要很多技巧，
 *     常常需要类型重定义、枚举常量、继承、模板偏特化等方法来配合，因此模版元编程比较复杂也比较困难。
 */

/*2.模板元编程的作用：
 *（1）C++模板最初是为实现泛型编程设计的，但人们发现模板的能力远远不止于那些设计的功能。 一个重要的理论
 *     结论就是：C++模板是图灵完备的，就是用C++模板可以模拟图灵机。理论上说C++模板可以执行任何计算任务，
 *     但实际上因为模板是编译期计算，其能力受到具体编译器实现的限制（如递归嵌套深度，C++11要求至少1024层，
 *     C++98要求至少17层）。C++模板元编程是“意外”功能而不是设计的功能，这也是C++模板元编程语法丑陋的根源。
 *（2）C++模板是图灵完备的，这使得C++代码存在两层次，其中执行编译计算的代码称为静态代码，执行运行期计算的
 *     代码称为动态代码，C++的静态代码由模板实现，编写C++的静态代码，就是进行C++的模板元编程。
 *（3）C++模板可以做以下事情：编译期数值计算、类型计算、自动生成代码和循环展开等，其中数值计算实际意义不大，
 *     而类型计算和代码计算可以使得代码更加通用、更加易用、性能更好。但同时也会造成代码更难阅读、更难调试、
 *     有时也会有代码膨胀问题。
 *（4）使用模板元编程的基本原则：就是将负载由运行时转移到编译时，同时保持原有的抽象层次。其中负载可以分为两类，
 *     一类就是程序运行本身的开销，一类则是程序员需要编写的代码。前者可以理解为编译时优化，后者则是为提高代码
 *     复用度，从而提高程序员的编程效率。
 */

/*3.模板元编程的组成要素：
 *（1）从编程范式上来说，C++模板元编程是函数式编程，用递归形式实现循环结构的功能，用C++模板的特例化提供
 *     了条件判断能力，这两点使得其具有和普通语言一样通用的能力，即图灵完备性。
 *（2）模版元程序由元数据和元函数组成，元数据就是元编程可以操作的数据，即C++编译器在编译期可以操作的数据。
 *     元数据不是运行期变量、只能是编译期常量、不能被修改。常见的元数据有enum枚举常量、const/constexpr常量、
 *     数值字面量、基本类型和自定义类型等。
 *（3）元函数是模板元编程中用于操作处理元数据的“构件”，可以在编译期被“调用”，因为它的功能和形式与运行时的
 *     函数类似而被称为元函数，它是元编程中最重要的构件。元函数实际上表现为C++的一个类、模板类或模板函数。
 *（4）模板元编程产生的源程序是在编译期执行的程序，因此它首先要遵循C++和模板的语法，但是它操作的对象不是
 *     运行时普通的变量，因此不能使用运行时的C++关键字（比如if-else、switch-case、for、while、do-while等），
 *     可用的语法元素相当有限。实际上模板元中的if-else可以通过type_traits来实现，它不仅仅可以在编译期做判断，
 *     还可以做计算、查询、转换和选择。模板元中的for等逻辑可以通过递归、重载和模板特化（偏特化）等方法实现。
 */

/*4.模板元编程中常用的C++语法元素：
 *（1）enum/static const/constexpr      //用来定义编译期的整数常量。
 *（2）typedef/using                    //用于定义元数据。
 *（3）T/Args...                        //声明元数据类型。
 *（4）template struct/class            //主要用于定义元函数。
 *（5）::                               //域运算符，用于解析类型作用域获取计算结果（元数据）。
 *（6）if constexpr                     //提供了编译时条件选择功能。
 */

/*5.模板元编程的控制逻辑:
 *（1）第一个C++模板元程序是计算小于给定数N的全部素数（又叫质数），程序并不运行（都不能通过编译），
 *     而是让编译器在错误信息中显示结果（直观展现了编译期计算结果），C++模板元编程不是设计的功能，
 *     更像是在戏弄编译器的把戏。从此C++模板元编程的能力开始被人们认识到。在模版元程序的具体实现时，
 *     由于其执行完全是在编译期，所以不能使用运行期的一些语法，如if-else、for和while等语句都不能用。
 *     这些控制逻辑需要通过特殊的方法来实现。
 *（2）if判断：从C++11开始，可以通过type_traits来实现模板元编程中的if判断。因为type_traits提供了编译期
 *     选择特性std::conditional，它在编译期根据一个判断式选择两个类型中的一个，和条件表达式的语义类似，
 *     类似于一个三元表达式。
 *（3）loop unrolling循环展开：编译期的循环展开可以通过模板特化来结束递归展开，达到运行期的for、while和
 *     do-while语句的功能。
 *（4）switch/case分支：同样可以通过模板特化来模拟实现编译期的switch/case分支选择功能。
 */

#include <iostream>

#define _CHANGE_WAY_
// #undef _CHANGE_WAY_

using namespace std;

/*C++模板元编程的函数式编程范式，对比结构化求和程序：for(int i=0;i<=N;++i) sum+=i。
 *用逐步改变存储（即变量sum）的方式来对计算过程进行编程，模板元程序没有可变的存储，
 *都是编译期常量，是不可改变的。要表达求和过程就要用很多个常量：Summation<0>::value、
 *Summation<1>::value...Summation<N>::value。函数式编程看上去似乎效率低下，因为它和
 *数学接近，而不是和硬件工作方式接近。但有自己的优势，描述问题更加简洁清晰，没有可变
 *的变量就没有数据依赖，方便进行并行化。
 */
#ifndef _CHANGE_WAY_
template <int N>
struct Summation
{
	static const int value = N + Summation<N - 1>::value;
};

template <>
struct Summation<1>
{
	static const int value = 1;
};
#else
template <int N>
struct Summation
{
	enum{value = N + Summation<N - 1>::value};
};

template <>
struct Summation<1>
{
	enum{value = 1};
};
#endif

#ifndef _CHANGE_WAY_
constexpr int summation_11(int n)    //C++11中constexpr常量表达式函数里面，只能包含一条return语句。
{
	return n == 1 ? 1 : n + summation_11(n - 1);
}
#else
template <int N>
constexpr int summation_11()
{
	return N + summation_11<N - 1>();
}


template <>
constexpr int summation_11<1>()
{
	return 1;
}
#endif

#ifndef _CHANGE_WAY_
constexpr int summation_14(int n)
{
	if(n == 1) return 1;
	return n + summation_14(n - 1);
}
#else
constexpr int summation_14(int n)     //C++14中constexpr函数体里面可以使用局部变量、选择语句和循环语句。
{
	int ret = 0;
	for(int i=1;i<=n;++i)
	{
		ret += i;
	}
	return ret;
}
#endif

template <int N>
int func()
{
	cout<<"func: "<<N<<endl;
	return N;
}

int main(void)
{
	/*static_assert是C++11添加的新关键字，用来做编译期间的断言。如果第一个参数常量表达式的值为false，
	 *会产生一条编译错误，错误位置就是该static_assert语句所在行，第二个参数就是错误提示字符串。
	 */
	static_assert(Summation<5>::value == 15,"Summation<5>::value != 15");
	cout<<"Summation<5>::value ="<<Summation<5>::value<<endl;
	
	/*static_assert同sizeof一样是C++关键字，而不是一个函数，并且sizeof是一个运算符。
	 *所以不需要导入任何头文件就可以使用static_assert()和sizeof();
	 */
#ifndef _CHANGE_WAY_
	int arr[summation_11(15)] = {0};
	cout<<"arr len ="<<sizeof(arr)/sizeof(int)<<endl;
#else
	func<summation_11<20>()>();
#endif
	
	constexpr int num = summation_14(4);
	switch(num){
	case summation_14(3):
		cout<<"summation_14(3) ="<<summation_14(3)<<endl;
		break;
	case summation_14(4):
		cout<<"summation_14(4) ="<<summation_14(4)<<endl;
		break;
	default:
		cout<<"unknow"<<endl;	
	}
	
	return 0;
}