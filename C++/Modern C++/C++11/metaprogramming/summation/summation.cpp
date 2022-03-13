#include <iostream>

#define _CHANGE_WAY_
// #undef _CHANGE_WAY_

using namespace std;

//C++98/03中只能使用模板元编程技巧，实现编译期数值计算。
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