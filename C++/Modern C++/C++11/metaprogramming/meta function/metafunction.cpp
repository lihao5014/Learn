/*1.Ԫ��̣���C++���� = C���Եĳ��� + ������� + ��׼�⣩
 *��1��Ԫ�����ͨ����������ʵ�壬�ڱ���ʱ���������ʱ��Ҫ�ĳ��������ͺʹ���ķ�����
 *     һ��ı����ͨ��ֱ�ӱ�д����ͨ�����������룬����Ŀ����룬����������ʱִ�С�
 *     ����ͨ�ı�̲�ͬ��Ԫ������ǽ��������ṩ��ģ����ƣ�ͨ���������Ƶ����ڱ���ʱ���ɳ���
 *     Ԫ��̾����������Ƶ��õ��ĳ����ٽ�һ��ͨ�����������룬�������յ�Ŀ����롣
 *��2��Ԫ����ֱ���Ϊ������̡�����ʽ��̻�ģ��Ԫ��̡���Ԫ������һ�ж��ǿɼ���ģ�
 *     Ҳ����˵��ֵ���������Ͷ��ǿ��Լ����������������ڵĺ������ڲ��졣
 */

/*2.C++�е�������Ҫ������ƣ�
 *��1����������̣�Ϊ��ʵ����������̣�C++�ṩ����class����C++���������͹�����µ����͡�
 *��2��ģ���̣���ģ���̷���C++�ṩ��ģ��template����һ��ֱ�۵ķ�ʽ��ʾͨ�ø��
 */

/*3.ģ���̵�������Ҫ��
 *��1�����ͱ�̣�ע����ͨ�ø���ĳ������ͨ�õ����ͻ��㷨������Ҫ���ڹ��ı�����������ɾ���Ĵ��롣
 *     ģ�����Ƴ��Խ������ڷ��ͱ�̣������ݽṹ���㷨���г���
 *��2��Ԫ��̣�ע�������ģ���Ƶ�ʱ��ѡ��͵�����ͨ��ģ�弼����Ƴ�������Ԫ��̲�ͬ��һ��ı�̣�
 *     �ڳ�������ϸ�������ս�ԣ������ܵ������ѧ�ߺ͹���ʦ�Ĺ㷺��ע��
 */

#include <iostream>
#include "cppstd.h"

using namespace std;

/*C++��ģ��Ԫ����Ǻ���ʽ��̣����Ժ�����һ�ȹ���һ���ڱ����ڼ�ִ�еĺ��������Գ�ΪԪ������
 *Ԫ������struct/class��constexpr���ֶ��巽ʽ��C++98/03֮ǰֻ��ʹ��struct/classģ�嶨��Ԫ������
 *��C++11��׼�����ʹ��constexpr�������ʽ�����ķ�ʽ����Ԫ������constexpr������˼�ǳ������ʽ��
 *��˱��ʽ�ڲ���������������ڿ��Ըı������
 */
#ifndef HAS_CPP_11
template <int N,int M>
struct MetaFunc
{
	static const int value = N + M;
};
#else
constexpr int metaFunc(int x,int y)     //constexpr��C++11��׼������ӵĹؼ���
{
	return x + y;
}
#endif

/*ֻ��vs2015 update3���ϰ汾�ı�������֧��ʹ��/stdѡ��ָ��C++��׼����msvc������ֻ��ָ��C++14���ϱ�׼��
 *�޷�ָ��C++98��C++03��C++11��׼��
 */
#ifndef HAS_CPP_14
template <int n>
class IsOdd
{
public:
	static const bool value = ((n % 2 == 0) == 1);
};
#else
template <int n>
constexpr static bool isOdd = ((n % 2 == 0) == 1);
#endif

template <unsigned int val>
struct _IsZero
{
	static const bool value = false;
};

template <>
struct _IsZero<0>
{
	static const bool value = true;
};

#ifdef HAS_CPP_14
template <unsigned int val>
constexpr bool isZero = _IsZero<val>::value;    //����ģ����C++14�вŵõ�֧��
#endif

/*C++�в���ѭ���͵ݹ飬��ӡ��1��N����Ȼ��������print�Ǻ���ģ�壬����print<N>���õ�print<N-1>��������
 *��˲��ǵݹ顣��������ʵ����print<N>��ʱ��������������print<N-1>�������ڱ����ڻ�ݹ��ʵ������ȥ��
 *ֱ������ȫ�ػ���print<1>Ϊֹ��Ԫ������ñ������ڱ����ڵĵݹ���������ڵĵݹ飬������ƹ���ԭʼ��������ơ�
 */
template <int N>
void print()
{
	cout<<N<<" ";
	print<N-1>();
}

/*������Ȼ�ǵݹ飬���п��ܱ�ջ���������ݹ�ʵ����������������Ƶġ�clang3.4��Ĭ��������256�㣬
 *��gcc8.2��Ĭ��������900�㡣������һ���ƻ�����������Fatal error������ʧ�ܡ�
 */
template <>
void print<1>()
{
	cout<<1<<endl;
}

int main(void)
{
#if defined(__GNUC__) || defined(__clang__)
	cout<<"C++ version: "<<__cplusplus<<endl;
#elif defined(_MSC_VAR)
	cout<<"C++ version: "<<__MSVC_LANG<<endl;
#endif
	
#ifndef HAS_CPP_11
#pragma message("Don't have C++11 standard!")
	int arr[MetaFunc<2,3>::value] = {0};
#else
#pragma message("Have C++11 standard!")
	int arr[metaFunc(3,4)] = {0};
#endif
	cout<<"arr len ="<<sizeof(arr)/sizeof(arr[0])<<endl;

#ifndef HAS_CPP_14
#pragma message("Don't have C++14 standard!")
	bool ret = IsOdd<17>::value;
#else
#pragma message("Have C++14 standard!")
	bool ret = isOdd<17>;
#endif
	cout<<"17 is odd number"<<endl;

#if HAS_CPP_11
	static_assert(!_IsZero<5>::value,"5 != 0");
	static_assert(_IsZero<0>::value,"0 == 0");
#elif HAS_CPP_14
	static_assert(!isZero<1>,"1 != 0");
	static_assert(isZero<0>,"0 == 0");
#else
#pragma message("Using C++98 standard!")
	cout<<"_IsZero<5>::value == 0 ? "<<_IsZero<5>::value<<endl;    //static_assert()��̬���Թ�����C++11������ġ�
	cout<<"_IsZero<0>::value == 0 ? "<<_IsZero<0>::value<<endl;
#endif

	const int num = 10;
	print<num>();
	
	return 0;
}
