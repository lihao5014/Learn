/*1.C++ģ��Ԫ��̵ĸ��
 *��1��Ԫ���metaprogramming��ǰ׺��meta-����ʾ�����ڽϸ߷�չ״̬������˼������������Ͻ���
 *     Ԫ���ָ�ľ��Ǹ߽׵ı�̣�����дһ�ֳ���ʹ�����ֳ�����԰�ĳЩ������Ϊ�������ݣ�
 *     ���ɻ���������ĳ���һ�������Щ�߽׵ĳ��������ڱ���ʱ�����Ԫ��̲���һ���¸��
 *     ��ʵ���κ�һ�ָ߼����Եı�������������ΪԪ��̵Ĺ��ߣ���Ϊ���ǵĳ�����뱻ת��Ϊ
 *     ������Ի��߻��������Ժ󣬲��ܹ������ڼ�����ϡ�
 *��2��C++ǿ���ģ����Ƹ�����ģ���ڱ���ʱ������������ģ���ػ���������ʵ�ֱ����ڵķ�֧�ṹ��
 *     ĿǰԪ����Ѿ���ΪC++���Ե�һ���Ӵ��֧��C++����ӵ���˱����ں������ڵ�����ִ��������
 */

#include <iostream>

#define _CHANGE_WAY_
#undef _CHANGE_WAY_

using namespace std;

/*Factorial�ڴ�ͳ��������һ����ģ�壬����Ԫ��̵Ĺ۵�ȥ�����������Ϊ��һ��Ԫ������
 *���Ԫ��������һ�����͵�ģ����������ķ���ֵ��Ԫ������һ����̬��Ա��ע��Ԫ����
 *����ͨ�ĺ����ܲ�һ����һ����Ԫ����������Ҫ����һ�����ϵ��ػ��汾��Ϊ�ս�������
 *��һ����Ԫ�����ķ���ֵ��Ҫ��ʽ����ȡ������
 */
#ifndef _CHANGE_WAY_
template <int N>
struct Factorial
{
	static const int value = N * Factorial<N - 1>::value;
};

//������ģ����ػ������γɵݹ飬�������㶼�ڱ���ʱ��ɡ�
template <>
struct Factorial<1>
{
	static const int value = 1;    //��̬��������ֵ����Ϊ������ڴ�ռ䡣
};
#else
template <int N>
struct Factorial
{
	enum{value = N * Factorial<N - 1>::value};
};

template <>
struct Factorial<1>
{
	enum{value = 1};    //ö��ֵ������Ϊ��ֵ�����Բ�ռ���ڴ�ռ�
};
#endif

#ifndef _CHANGE_WAY_
constexpr int factorial_11(int n)   //C++11��constexpr�������ʽ�������棬ֻ�ܰ���һ��return��䡣
{
	return n == 1 ? 1 : n * factorial_11(n - 1);
}
#else
template <int N>
constexpr int factorial_11()
{
	return N * factorial_11<N - 1>();
}

template <>
constexpr int factorial_11<1>()
{
	return 1;
}
#endif

#ifndef _CHANGE_WAY_
constexpr int factorial_14(int n)   //C++14��constexpr�������������ʹ�þֲ�������ѡ������ѭ����䡣
{
	if(1 == n) return 1;
	return n * factorial_14(n - 1);
}
#else
constexpr int factorial_14(int n)
{
	int ret = 1;
	for(int i=1;i<=n;++i)
	{
		ret *= i;
	}
	return ret;
}
#endif

template <int N>
struct constN
{
	constN(){cout<<"constN: "<<N<<endl;}
};

int main()
{
	static_assert(Factorial<4>::value == 24,"Factorial<4>::value != 24");
	cout<<"Factorial<4>::value ="<<Factorial<4>::value<<endl;

#ifndef _CHANGE_WAY_
	int arr[factorial_11(3)] = {0};
	cout<<"arr len ="<<sizeof(arr)/sizeof(arr[0])<<endl;
#else
	constN<factorial_11<5>()> out;
#endif
	
	enum{
		a = factorial_14(3),
		b = factorial_14(4),
		c = factorial_14(5)
	};
	cout<<"b ="<<b<<endl;
	
	return 0;
}