/*1.判断C++标准版本:
 *（1）clang和gcc编译器：判断__cplusplus宏的值。
 *（2）msvc编译器：判断_MSVC_LANG宏的值。
 */

/*2.不同C++标准版本中，__cplusplus和_MSVC_LANG所对应的值：
 *  C++17	    201703L
 *  C++14	    201402L
 *  C++11	    201103L
 *  C++03以下	199711L
 */

/*3.判断C++使用的编译器：
 *（1）msvc编译器：_MSC_VER
 *（2）clang编译器：__clang__
 *（2）gcc编译器：__GNUC__
 */

/*4.编译器切换支持的C++标准选项：
 *（1）gcc编译器：-std=c++98，-std=c++11，-std=c++14，-std=c++17。
 *（2）msvc编译器：/std:c++14，/std:c++17，/std:c++latest。注意VC++编译器的/std选项是从vs2015 Update3开始支持的，
 *     且不能切换到C++98、C++03或C++11标准，即msvc编译器没有/std:c++98，/std:c++03和/std:c++11选项。
 */

/*5. msvc编译器对C++标准版本的支持：
 *（1）默认情况下，Visual Studio始终为__cplusplus预处理器宏返回值“199711L”，__cplusplus预处理器宏通常用于报告。
 *     因为很多现有代码需要此宏的值与“199711L”匹配，所以编译器不会更改此宏的值，除非通过使用/Zc:__cplusplus
 *     编译器选项进行显式选择。 
 *（2）从Visual Studio 2017版本15.7开始便已提供/Zc:__cplusplus选项，该选项在默认情况下处于禁用状态。
 *（3）/Zc:__cplusplus编译器选项启用__cplusplus预处理器宏以针对最新的C++语言标准支持报告更新的值。
 *（4）在启用了/Zc:__cplusplus选项的情况下，__cplusplus报告的值取决于/std版本切换设置。
 *（5）_MSVC_LANG预定义宏向标准版本报告/Zc:__cplusplus是启用还是禁用状态。如果启用/Zc:__cplusplus，
 *     则__cplusplus == _MSVC_LANG。
 */

/*6._MSVC_LANG宏：
 *定义为指定编译器面向的C++语言标准的整数文本。 此宏仅在编译为C++的代码中设置。 默认情况下，
 *或者当指定了/std:c++14编译器选项时，此宏为整数文本值201402L。如果指定了/std:c++17编译器选项，
 *则此宏设置为201703L。如果指定了/std:c++20编译器选项，则此宏设置为202002L。当指定了/std:c++latest选项时，
 *它设置为更高的未指定值。其他情况下则不会定义此宏。从vs2015 Update3开始，提供_MSVC_LANG宏和/std编译器选项。
 */

/*7.宏操作系统判断宏:
 *（1）UNIX操作系统：_unix或_unix_
 *（2）Linux操作系统：_linux或_linux_
 *（3）Windows32操作系统：_WIN32
 *（4）Windows64操作系统：_WIN64
 *（5）IOS操作系统：__APPLE__
 *（6）Android操作系统：__ANDROID__
 */

#ifndef CPP_STANDARD_H
#define CPP_STANDARD_H

#if defined(__clang__) || defined(__GNUC__)
	#define CPP_STANDARD __cplusplus
#elif defined(_MSC_VER)
	#define CPP_STANDARD _MSVC_LANG
#endif
 
#if CPP_STANDARD >= 199711L
	#define HAS_CPP_98 1
	#define HAS_CPP_03 1
#endif

#if CPP_STANDARD >= 201103L
	#define HAS_CPP_11 1
#endif

#if CPP_STANDARD >= 201402L
	#define HAS_CPP_14 1
#endif

#if CPP_STANDARD >= 201703L
	#define HAS_CPP_17 1
#endif

#endif   //CPP_STANDARD_H