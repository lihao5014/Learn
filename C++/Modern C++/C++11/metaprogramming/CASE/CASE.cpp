#include <iostream>

using namespace std;

//通过模板特化来模拟实现编译期的switch/case分支选择功能。
template <int N>
struct Case
{
	static inline void run()
	{
		cout<<"default case"<<endl;
	}
};

template <>
struct Case<1>
{
	static inline void run()
	{
		cout<<"case 1"<<endl;
	}
};

template <>
struct Case<2>
{
	static inline void run()
	{
		cout<<"case 2"<<endl;
	}
};

int main(void)
{
	constexpr int value = 0;
	Case<value>::run();
	
	Case<1>::run();
	Case<2>::run();
	
	return 0;
}