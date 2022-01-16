#include <iostream>
#include <vector>
#include <list>
#include "cppstd.h"

using namespace std;

/*因为constexpr函数中不能使用cout、puts、printf等打印语句，所以要想在constexpr函数输出信息，
 *只能使用编译期的#pragma message()命令。
 */
#if HAS_CPP_14
#pragma message("Compiled using the C++14 standard")
constexpr int factorial(int n)     //C++14 constexpr函数可使用局部变量、选择语句和循环语句。
{
	int ret = 1;
    for(int i=n;n>=1;--n)
	{
		ret *= n;
	}
	return ret;
}
#elif HAS_CPP_11
#pragma message("Compiled using the C++11 standard")
constexpr int factorial(int n)     //C++11 constexpr函数使用递归而非迭代。
{
    return n <= 1 ? 1 : (n * factorial(n - 1));
}
#endif

/*默认情况下msvc编译器中__cplusplus宏的值始终为“199711L”。
 *但可以启用/Zc:__cplusplus选项和设置/std选项进行修改。
 */
int main()
{
#if defined(__GNUC__)
	cout<<"gcc c++ version: "<<__cplusplus<<endl;
#elif defined(_MSC_VER)
	cout<<"msvc c++ version: "<<_MSVC_LANG           //启用/Zc:__cplusplus选项后__cplusplus的值保持与_MSVC_LANG同步。
	    <<" , msvc __cplusplus: "<<__cplusplus<<endl;   //设置/std选项可以修改_MSVC_LANG宏的值。
#endif

#if HAS_CPP_11
	vector<list<int>> vec;     //before c++11 error: ‘>>’ should be ‘> >’ within a nested template argument list。
	cout<<"C++11: spaces in template expression is unnecessary"<<endl;
#elif HAS_CPP_98
	vector<list<int> > vec;    //ok in each C++ version
	cout<<"C++98/03: ‘>>’ should be ‘> >’ within a nested template argument"<<endl;
#endif

#if HAS_CPP_11
	cout<<"5! ="<<factorial(5)<<endl;
#endif

	return 0;
}