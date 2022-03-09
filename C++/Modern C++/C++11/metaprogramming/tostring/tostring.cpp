//使用元编程技巧，实现将C语言的基本类型数据，转换为std::string的函数ToString()。

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

//（1）首先定义三个变量模板：isNum/isStr/isBad，分别对应了三个类型条件的谓词。
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