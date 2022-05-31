#include <iostream>

using namespace std;

template <bool condition>
struct IF
{
	static inline void run()
	{
		cout<<"it's true"<<endl;
	}
};

template <>
struct IF<false>
{
	static inline void run()
	{
		cout<<"it's false"<<endl;
	}
};

//ͨ��ģ���ػ���ģ��ʵ�ֱ����ڵ�switch/case��֧ѡ���ܡ�
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
	const bool flag = false;
	IF<flag>::run();
	
	constexpr int value = 0;
	Case<value>::run();
	
	Case<1>::run();
	Case<2>::run();
	
	return 0;
}