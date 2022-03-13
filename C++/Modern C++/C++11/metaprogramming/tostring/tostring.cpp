/*C++元编程的出现是一个无心插柳的偶然，人们发现C++语言提供的模板抽象机制，
 *能很好的被应用于元编程上。借助元编程，可以写出类型安全、运行时高效的代码。
 *但是过度的使用元编程，一方面会增加编译时间，另一方面会降低程序的可读性。
 *不过在C++不断地演化中，新的语言特性被不断提出，为元编程提供更多的可能。
 */

/*1.元编程的基本应用：
 *（1）利用元编程可以很方便的设计出类型安全、运行时高效的程序。现在元编程已被广泛的应用于C++的编程实践中。
 *     尽管元编程的应用场景各不相同，但都是三类基本应用的组合：数值计算、类型推导和代码生成。
 *（2）数值计算：作为元编程的最早的应用，数值计算可以用于编译时常数计算和优化运行时表达式计算。
 *     编译时常数计算能让程序员写编译时确定的常量，而不是直接写常数或在运行时计算这些常数。
 *（3）类型推导：除了基本的数值计算之外，还可以利用元编程进行任意类型之间的相互推导。
 *（4）代码生成：和泛型编程一样，元编程也常常被用于代码的生成。但是和简单的泛型编程不同，
 *     元编程生成的代码往往是通过编译时测试和编译时迭代的演算推导出来的。
 */

/*2.元编程的主要难点：
 *（1）由于C++语言设计层面上没有专门考虑元编程的相关问题，所以实际元编程难度较大。
 *     元编程的难点主要有四类：复杂性、实例化错误、代码膨胀、调试模板。
 *（2）复杂性：由于元编程的语言层面上的限制较大，所以许多的元编程代码使用了很多的
 *     编译时测试和编译时迭代技巧，可读性都比较差。另外由于巧妙的设计出编译时能完成的
 *     演算也是很困难的，相较于一般的C++程序，元编程的可写性也不是很好。
 *（3）实例化错误：模板的实例化和函数的绑定不同。在编译前模板的实例化对传入的参数是什么，
 *     没有太多的限制，而函数的绑定则根据函数的声明，确定了应该传入参数的类型。
 *     而对于模板实参内容的检查，则是在实例化的过程中完成的。所以程序的设计者在编译前，
 *     很难发现实例化时可能产生的错误。为了减少可能产生的错误，C++之父提出了在语言层面上，
 *     给模板上引入概念。利用概念可以对传入的参数加上限制，即只有满足特定限制的类型才能
 *     作为参数传入模板。但是由于各种原因，这个语言特性一直没有能正式加入C++标准。尽管如此，
 *     编译时仍可以通过编译时测试和静态断言等方法实现检查。另外编译时模板的实例化出错位置，
 *     在调用层数较深处时，编译器会提示每一层实例化的状态，这使得报错信息包含了很多的无用信息，
 *     很难让人较快的发现问题所在。
 *（4）代码膨胀：由于模板会对所有不同模板实参都进行一次实例化，所以当参数的组合很多的时候，
 *     很可能会发生代码膨胀，即产生体积巨大的代码。这些代码可以分为死代码和有效代码2种。
 *     在元编程中，很多时候只关心推导的结果而不是过程。不需要中间过程中产生的临时模板。
 *     这些临时模板是死代码，即不被执行的代码。所以编译器会自动优化最终的代码生成，在链接时移
 *     除这些无用代码，使得最终的目标代码不会包含它们。另一种情况下，展开的代码都是有效代码，
 *     即都是被执行的，但是又由于需要的参数的类型繁多，最后的代码体积仍然很大。编译器很难优化
 *     这些代码，所以程序员应该在设计时防止代码膨胀。
 *（5）调试模板：元编程在运行时主要的难点在于对模板代码的调试。如果需要调试的是一段通过很多次的
 *     编译时测试和编译时迭代展开的代码，即这段代码是各个模板的拼接生成的，而且展开的层数很多，
 *     那么调试时需要不断地在各个模板的实例间来回切换。这种情景下，调试人员很难把具体的问题定位
 *     到展开后的代码上。 所以一些大型项目很少使用复杂的代码生成技巧，而是通过传统的代码生成器
 *     生成重复的代码，易于调试。
 */

/*3.现代C++也不断地增加语言的特性，致力于降低元编程的复杂性：
 *（1）C++11的别名模板提供了对模板中的类型的简记方法。
 *（2）C++14的变量模板提供了对模板中常量的简记方法。
 *（3）C++17的constexpr-if提供了编译时测试 的新写法。
 *（4）C++17的折叠表达式降低了编译时迭代 的编写难度。
 *（5）基于C++14的泛型lambda表达式，元编程库Boost.Hana提出了不用模板就能元编程的理念，
 *     宣告从模板元编程时代进入现代元编程时代。其核心思想是只需要使用C++14的泛型lambda
 *     表达式和C++11的constexpr/decltype就可以快速实现元编程的基本演算了。
 */

#include <iostream>
#include <string>         //std::to_string()
#include <type_traits>    //is_arithmetic(),is_same(),enable_if<>,enable_if_t<>

#if defined(__GNUC__) || defined(__clang__)
	#define CPP_STANDARD __cplusplus
#elif defined(_MSC_VER)
	#define CPP_STANDARD _MSVC_LANG
#endif

#if CPP_STANDARD < 201402L
	#error c++ version is less than c++14
#endif

#define _ERROR_
#undef _ERROR_

using namespace std;

/*使用元编程技巧，实现将C语言的基本类型数据，转换为std::string的函数ToString()。
 *（1）首先定义三个变量模板：isNum/isStr/isBad，分别对应了三个类型条件的谓词。
 */
template <typename T>
constexpr bool isNumber = is_arithmetic<T>::value;   //编译时测试一个类型是否为特定的类型。

template <typename T>
constexpr bool isString = is_same<T,const char*>::value;

template <typename T>
constexpr bool isBad = !isNumber<T> && !isString<T>;

//（2）然后根据SFINAE规则：使用std::enable_if重载函数ToString，分别对应了数值、C风格字符串和非法类型。
template <typename T>
typename enable_if<isNumber<T>,string>::type ToString(T num)   //编译时测试一个类型 是否满足某些条件。
{
	return to_string(num);
}

//enable_if<>模板C++11就已经提供了，而enable_if_t<>别名模板到C++14才提供。
template <typename T>
enable_if_t<isString<T>,string> ToString(T str)    //编译时测试一个类型 是否满足某些条件。
{
	return string(str);
}

/*（3）在前两个重载中：分别调用std::to_string和std::string构造函数。在最后一个重载中，
 *     通过类型依赖的false表达式sizeof(T) == 0静态断言直接报错。根据两阶段名称查找的规定，
 *     如果直接使用static_assert(false)断言，会在模板还没实例化的第一阶段就无法通过编译。
 */
template <typename T>
enable_if_t<isBad<T>,string> ToString(T bad)
{
	static_assert(sizeof(T) == 0,"neither number nor string");
}

#ifdef _ERROR_
/*1.编译时测试类型的错误用法:
 *（1）对于初次接触元编程的人，往往会使用if语句进行编译时测试。但这段代码是一种错误的写法，
 *     很代表性的体现了元编程和普通编程的不同之处。
 *（2）编译To_String()函数时，对于给定的类型T，需要进行两次函数绑定，即val作为参数分别调用
 *     std::to_string(val)和std::string(val)。再进行一次静态断言，即判断!isBad<T>是否为true。
 *     这会导致两次绑定中有一次会失败。假设调用To_String("hello world")，在编译这段代码时，
 *     string(const char*)可以正确的重载，但是to_string(const char*)并不能找到正确的重载，
 *     导致编译失败。
 *（3）在脚本语言中这段代码是没有问题的。因为脚本语言没有编译的概念，所有函数的绑定都在运行时完成；
 *     而静态语言的函数绑定是在编译时完成的。为了使得代码的风格用于元编程，C++17引入了constexpr if，
 *     为我们提供了按条件编译的功能。只需要把以上代码中的if改为if constexpr 就可以编译了。
 */
template <typename T>
string To_String(T val)   //代码错误的原因是：一个模板参数无法提供两种数据类型，同时满足to_string()和string()的传参要求。
{
	if(isNumber<T>)
	{
		return to_string(val);    //std::to_string()函数要求传入的参数类型是C语言的基本类型数据。
	}
	else if(isString<T>)
	{
		return string(val);       //std::string()构造函数要求传入的参数类型是const char*或string。
	}
	else
	{
		static_assert(!isBad<T>,"neither number nor string");
	}
}
#else
/*2.编译时测试类型的正确用法：
 *（1）constexpr if的引入让模板测试更加直观，提高了模板代码的可读性。可以使用constexpr if解决编译时选择的问题；
 *     而且最后的兜底语句，可以使用类型依赖的false表达式sizeof(T) == 0进行静态断言，不再需要isBad<T>谓词模板。
 *     但也不能直接使用static_assert(false)断言。
 *（2）constexpr if背后的思路早在Visual Studio 2012已出现了。其引入了__if_exists语句，用于编译时测试标识符是否存在。
 */
template <typename T>
string To_String(T val)
{
	if constexpr(isNumber<T>)    //C++17新特性中constexpr if为我们提供了按条件编译的功能。
	{
		return to_string(val);
	}
	else if constexpr(isString<T>)
	{
		return string(val);
	}
	else
	{
		static_assert(sizeof(T) == 0,"neither number nor string");
	}
}
#endif

int main(void)
{
	string a = ToString(5);	
	string b = ToString(3.14);
	string c = ToString("hello world");
	
	cout<<"a ="<<a<<" , "<<typeid(a).name()<<endl;
	cout<<"b ="<<b<<" , "<<typeid(b).name()<<endl;
	cout<<"c ="<<c<<" , "<<typeid(c).name()<<endl;
	
#ifdef _ERROR_
	// string d = ToString(string("hello c++"));
	// cout<<"d ="<<d<<" , "<<typeid(d).name()<<endl;
#endif
	
	string x = To_String(10);
	string y = To_String(2.718);
	string z = To_String("welcome qt");
	cout<<"x ="<<x<<" , y ="<<y<<" , z ="<<z<<endl;
	
	return 0;
}