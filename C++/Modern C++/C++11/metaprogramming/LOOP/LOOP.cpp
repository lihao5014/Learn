/*1.����ʱ����:
 *��1������ʱ������������̱���е�ѭ��������ƣ�����ʵ����for/while/do���Ƶ�ѭ���߼���
 *     ����ʱ�����ַ�Ϊ���֣�����ģ��ĵ����ͱ䳤ģ��ĵ�����
 *��2����C++17֮ǰ������ʱ��������ͨ�ı�̲�ͬ����ΪԪ��̵��������ֻ������ڴ������ģ�
 *     ����ͨ����������ʵ�ֱ���ʱ������ֻ���õݹ���ػ������ʵ�֡�һ��˼·���ṩ�������أ�
 *     һ���������������ڲ��ݹ�����Լ�����һ����ǰ�ߵ�ģ���ػ��������أ�ֱ�ӷ��ؽ����
 *     �൱�ڵݹ���ֹ���������ǵ��������������Ǳ��ʽ�����͡���C++17������۵����ʽ���﷨��
 *     �����˱���ʱ������д����
 */

/*2.�䳤ģ�����۵����ʽ��
 *��1��C++11����䳤ģ��ʱ����֧������ģ����ֱ��չ�����������﷨�������﷨��֧�ֶԲ�����
 *     ���ÿ����������һԪ������Ϊ��ʵ�ֲ�����Ķ�Ԫ������������������ģ��ʵ�֡�
 *��2��C++17�������۵����ʽ������ֱ�ӱ�����������ĸ�������������Ӧ�ö�Ԫ������������۵������۵���
 */

#include <iostream>
#include "cppstd.h"

#define _CHANGE_WAY_
// #undef _CHANGE_WAY_

using namespace std;

//����ģ��ĵ���
template <int M,int N>
struct Power
{
	static const long value = M * Power<M,N - 1>::value;
};

template <int M>
struct Power<M,1>
{
	static const long value = M;
};

#ifdef HAS_CPP_14
#ifndef _CHANGE_WAY_
template <int M,int N>
const long power = Power<M,N>::value;   //��msvc�������У���Ϊ��ʱconst���ε�power���ǳ���������ֻ��������
#else
template <int M,int N>
constexpr long power = Power<M,N>::value;	
#endif
#endif

//�䳤ģ��ĵ�����Ϊ�˱����䳤ģ���ÿ������������ʹ�ñ���ʱ����ʵ��ѭ��������
template <typename T>
constexpr auto Accumulate()    //Accumulate()����û�в��������ء�
{
	return T(0);
}

/*����Accumulate()���������أ�һ���Ƕ�û�к��������������һ���ǶԺ���������������Ϊ1�������
 *�Ͷ���ģ��ĵ������ƣ�����Ҳ��ͨ���ݹ����ʵ�ֲ���������
 */
template <typename T,typename... Ts>
constexpr auto Accumulate(T arg,Ts... args)
{
	return arg + Accumulate<T>(args...);
}

//ʹ���۵����ʽ�������ʱ����������ʹ�ó�ʼֵΪ0�����۵����ʽ���Դ�����иĽ���
template <typename... Ts>
constexpr auto summation(Ts... args)
{
	return (0 + ... + args);
}

int main(void)
{
#if defined(__GNUC__) || defined(__clang__)
	cout<<"C++ version: "<<__cplusplus<<endl;
#elif defined(_MSC_VAR)
	cout<<"C++ version: "<<__MSVC_LANG<<endl;
#endif

	int arr[Power<3,2>::value] = {0};
	cout<<"arr len ="<<sizeof(arr)/sizeof(arr[0])<<endl;

#ifdef HAS_CPP_14
	enum {
		a = Power<2,2>::value,
		b = Power<2,3>::value,
		c = power<2,4>,
		d = power<2,5>
	};
	
	cout<<"a ="<<a<<" , "<<"b ="<<b<<" , "<<"c ="<<c<<" , "<<"d ="<<d<<endl;
#endif

	constexpr double x = Accumulate(1.0,3.14,2,0.618,3,2.718);
	cout<<"x ="<<x<<endl;
	
	const double y = summation(1.0,3.14,2,0.618,3,2.718);
	cout<<"y ="<<y<<endl;

	return 0;
}