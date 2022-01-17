/*1.判断C++标准版本:
 *（1）clang和gcc判断__cplusplus。
 *（2）msvc判断_MSVC_LANG。
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

/*4. MSVC编译器对C++标准版本的支持：
 *（1）默认情况下，Visual Studio始终为__cplusplus预处理器宏返回值“199711L”，__cplusplus预处理器宏通常用于报告。
 *     因为很多现有代码需要此宏的值与“199711L”匹配，所以编译器不会更改此宏的值，除非通过使用/Zc:__cplusplus
 *     编译器选项进行显式选择。 
 *（2）从Visual Studio 2017版本15.7开始便已提供/Zc:__cplusplus选项，该选项在默认情况下处于禁用状态。
 *（3）/Zc:__cplusplus编译器选项启用__cplusplus预处理器宏以针对最新的C++语言标准支持报告更新的值。
 *（4）在启用了/Zc:__cplusplus选项的情况下，__cplusplus报告的值取决于/std版本切换设置。
 *（5）_MSVC_LANG预定义宏向标准版本报告/Zc:__cplusplus是启用还是禁用状态。如果启用/Zc:__cplusplus，
 *     则__cplusplus == _MSVC_LANG。
 */

/*5.MSVC编译器的/std选项：
 *（1）/std选项功能：用于指定MSVC编译器支持的C/C++标准版本。
 *（2）/std可以使用预处理器宏来检测C++编译期间_MSVC_LANG生效的选项。
 *（3）/std:c++14选项：启用由编译器实现的C++14标准MSVC功能。它从vs2015 update3开始提供。
 *（4）/std:c++17选项：启用由编译器实现的C++17标准MSVC功能。 它从vs2017开始此选项可用。
 *（5）/std:c++latest选项：支持为下一个草稿标准建议的所有当前实现的编译器和标准库功能，
 *     以及一些进行中和实验性功能。 此选项从vs2015 update3开始可用。
 */

/*6._MSVC_LANG宏：
 *定义为指定编译器面向的C++语言标准的整数文本。 此宏仅在编译为C++的代码中设置。 默认情况下，
 *或者当指定了/std:c++14编译器选项时，此宏为整数文本值201402L。如果指定了/std:c++17编译器选项，
 *则此宏设置为201703L。如果指定了/std:c++20编译器选项，则此宏设置为202002L。当指定了/std:c++latest选项时，
 *它设置为更高的未指定值。其他情况下则不会定义此宏。从vs2015 Update3开始，提供_MSVC_LANG宏和/std编译器选项。
 */

#include <cstdio>
#include <cstring>
#include <iostream>
#include <stdexcept>

#if defined(__GNUC__) || defined(__clang__)
	#define CPP_STANDARD __cplusplus
#elif defined(_MSC_VER)
	#define CPP_STANDARD _MSVC_LANG
#endif

using namespace std;

class ConstString
{
public:
	template<std::size_t N>
	constexpr ConstString(const char (&str)[N])     //const char (&str)[N]为数组的引用
		:m_str(str)
		,m_size(N)
	{
			
	}
	
	constexpr char operator [](size_t n)const    //constexpr函数通过抛异常来提示错误。
	{
		return n < m_size ? m_str[n] : throw std::out_of_range("out of range error");
	}
	
	constexpr size_t size()const
	{
		return m_size;
	}
	
	void display()const
	{
		cout<<m_str<<endl;
	}
private:
	const char* m_str;
	std::size_t m_size;
};

//C++11标准中constexpr函数必须把一切放在单条return语句中，而C++14中取消了这样的限制。
#if CPP_STANDARD >= 201402L
constexpr size_t countLower(ConstString cstr,size_t n = 0,size_t c = 0)
{
	if(n == cstr.size())
	{
		return c;
	}
	
	if('a' <= cstr[n] && cstr[n] <= 'z')
	{
		return countLower(cstr,n + 1,c + 1);
	}
	else
	{
		return countLower(cstr,n + 1,c);
	}
}

constexpr size_t countUpper(ConstString cstr,size_t n = 0,size_t c = 0)
{
	while(n < cstr.size())
	{
		if('A' <= cstr[n] && cstr[n] <= 'Z')
		{
			c++;
		}
		n++;
	}
	
	return c;
}
#elif CPP_STANDARD >= 201103L
constexpr size_t countLower(ConstString cstr,size_t n = 0,size_t c = 0)
{
	return n == cstr.size() ? c : (('a' <= cstr[n] && cstr[n] <= 'z') ? countLower(cstr,n + 1,c + 1) : countLower(cstr,n + 1,c));
}

constexpr size_t countUpper(ConstString cstr,size_t n = 0,size_t c = 0)
{
	return n == cstr.size() ? c : (('A' <= cstr[n] && cstr[n] <= 'Z') ? countUpper(cstr,n + 1,c + 1) : countUpper(cstr,n + 1,c));
}
#endif

template <int N>
class constN
{
public:
	constN(){cout<<"constN: "<<N<<endl;}
};

template <int N>
void printN()
{
	cout<<"printN: "<<N<<endl;
}

int main(int argc,char** argv)
{
#if defined(__GNUC__) || defined(__clang__)
	cout<<"gcc/clang C++ version: "<<__cplusplus<<endl;
#elif defined(_MSC_VER)
	cout<<"msvc C++ version: "<<_MSVC_LANG<<endl;
#endif
	
	char buf[] = "hello world";
	cout<<"buf ="<<buf<<" , size ="<<strlen(buf) + 1<<endl;
	
	char (&arr)[12] = buf;      //定义数组的引用时，必须指定数组大小。
	arr[0] = 'a';
	arr[4] = 'a';
	cout<<"arr ="<<arr<<" , buf ="<<buf<<endl;

#ifdef _MSC_VER
	constexpr const char str[] = "Study Const Express";
	constexpr ConstString cstr(str);
#elif defined(__GNUC__)
	constexpr ConstString cstr("Study Const Express");
#endif
	int seq[cstr.size()] = {0};
	cout<<"seq array len ="<<sizeof(seq)/sizeof(seq[0])<<endl;
	
	cstr.display();
	cout<<"cstr[7] ="<<cstr[7]<<endl;
	
	cout<<"lower: ";
	constN<countLower(cstr)> out;
	
	cout<<"upper: ";
	printN<countUpper(cstr)>();
	
	try{
		cout<<"cstr[16] ="<<cstr[16]<<endl;
	}catch(std::out_of_range& err){
		cout<<err.what()<<endl;
	}catch(...){
		cout<<"default exceptions"<<endl;
	}
	
	return 0;
}