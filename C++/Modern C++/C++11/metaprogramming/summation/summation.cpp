#include <iostream>

#define _CHANGE_WAY_
// #undef _CHANGE_WAY_

using namespace std;

//C++98/03��ֻ��ʹ��ģ��Ԫ��̼��ɣ�ʵ�ֱ�������ֵ���㡣
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
constexpr int summation_11(int n)    //C++11��constexpr�������ʽ�������棬ֻ�ܰ���һ��return��䡣
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
constexpr int summation_14(int n)     //C++14��constexpr�������������ʹ�þֲ�������ѡ������ѭ����䡣
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
	/*static_assert��C++11��ӵ��¹ؼ��֣������������ڼ�Ķ��ԡ������һ�������������ʽ��ֵΪfalse��
	 *�����һ��������󣬴���λ�þ��Ǹ�static_assert��������У��ڶ����������Ǵ�����ʾ�ַ�����
	 */
	static_assert(Summation<5>::value == 15,"Summation<5>::value != 15");
	cout<<"Summation<5>::value ="<<Summation<5>::value<<endl;
	
	/*static_assertͬsizeofһ����C++�ؼ��֣�������һ������������sizeof��һ���������
	 *���Բ���Ҫ�����κ�ͷ�ļ��Ϳ���ʹ��static_assert()��sizeof();
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