/*1.Ԫ������
 *��1��C++��ģ��Ԫ����Ǻ���ʽ��̣����Ժ�����һ�ȹ���һ���ڱ����ڼ�ִ�еĺ��������Գ�ΪԪ������
 *     Ԫ������struct/class��constexpr���ֶ��巽ʽ��C++98/03֮ǰֻ��ʹ��struct/classģ�嶨��Ԫ������
 *     ��C++11��׼�����ʹ��constexpr�������ʽ�����ķ�ʽ����Ԫ������constexpr������˼�ǳ������ʽ��
 *     ��˱��ʽ�ڲ���������������ڿ��Ըı������
 *��2����Ԫ������һ�ж��ǿɼ���ģ�Ҳ����˵��ֵ�����Ͷ��ǿ��Լ����������������ڵĺ������ڲ��졣
 *��3��ֻҪ���ڱ����ڼ���ɼ��㣬���Ҳ�����������õı��ʽ����������ΪԪ������
 */

/*2.����ʱ���ԣ�
 *��1������ʱ�����൱��������̱���е�ѡ����䣬����ʵ��if else/switch��ѡ���߼�������ʱ���Ե�
 *     ������Ҫ�������֣��������ʽ�����͡�
 *��2����C++17֮ǰ������ʱ������ͨ��ģ���ʵ�������ػ�ʵ�ֵģ���ÿ���ҵ��������ģ�����ƥ�䣻
 *     ��C++17�����ʹ��constexpr if�ı���ʱ���Է�����
 *��3������ʱ���Ա��ʽ�������ھ�̬���ԣ�����ʱ���ԵĶ����ǳ������ʽ��������ʱ�ܵó�����ı��ʽ��
 *     �Բ�ͬ�ĳ������ʽ��Ϊ���������Թ��������Ҫ��ģ�����ء�
 *��4������ʱ�������ͣ���Ԫ��̵ĺܶ�Ӧ�ó����У���Ҫ�����ͽ��в��ԣ����Բ�ͬ������ʵ�ֲ�ͬ�Ĺ��ܡ�
 *     �������Ĳ��������ַ�Ϊ2�֣��ж�һ�������Ƿ�Ϊ�ض������ͺ��ж�һ�������Ƿ�����ĳЩ������
 *     ǰ�߿���ͨ����ģ����ػ�ֱ��ʵ�֣����߼���ͨ���滻ʧ�ܲ��Ǵ���SFINAE�����������ƥ�䣬
 *     ����ͨ����ǩ�ɷ�ƥ���ö�ٵ����������
 */

/*3.SFINAE��(Substitution Failure Is Not An Error�����滻ʧ�ܲ��Ǵ���)
 *��1��Ϊ�˸��õ�֧��SFINAE��C++11��type_traits��������ͷ�ļ��г����ṩ���ͼ���ν��ģ��is_*��has_*��
 *     ���ṩ��������Ҫ�ĸ���ģ��std::enable_if��std::void_t��
 *��2��std::enable_if�������������ж�ת��Ϊ�������ʽ�����Ʋ��Ա��ʽʵ�����ص�ѡ��
 *     ����Ҫ���һ������ĺ�������/��������ֵ/ģ�������
 *��3��std::void_t��ֱ�Ӽ�������ĳ�Ա/�����Ƿ���ڣ����������޷����أ��������ڹ���ν�ʣ�
 *     ��ͨ��std::enable_if�ж�������
 */

#include <iostream>
#include "cppstd.h"

#define _CHANGE_WAY_
// #undef _CHANGE_WAY_

using namespace std;

//����ʱ���Ա��ʽ������ν��isZero<Val>������ʱ�ж�Valֵ�ǲ���0��
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

//����ʱ�������ͣ�����ν��isVoid<T>������ʱ�ж�T�����ǲ���void��
template <typename T>
struct _IsVoid
{
	enum{value = false};
};

template <>
struct _IsVoid<void>
{
	enum{value = true};
};

#ifdef HAS_CPP_14
template <typename T>
constexpr bool isVoid = _IsVoid<T>::value;
#endif

/*struct���͵�Ԫ����TypeReplace�������ת���Ĺ��ܣ���type��ʾ���������������ͣ������int���ͣ�
 *��ת����unsgned int���ͣ�����ģ��������ʵ�֡�ע��ģ��Ԫ�����Ĳ������ڼ�����<>�ڲ�����ģ�
 *��һ��������ں����ǲ�ͬ�ġ�
 */
template <typename T>
struct TypeReplace
{
	typedef T type;
};

template <>
struct TypeReplace<int>
{
	typedef unsigned int type;
};

template <typename T>
using typeReplace = typename TypeReplace<T>::type;

/*����ģ��ֲ��ػ�������������ʱ�����ͷ�֧ѡ����Ժ�����������
 *Ԫ����IF��ģ��Ԫ�������򵥵����õ����Ļ�����ʩ��
 */
#ifndef _CHANGE_WAY_
template <bool B,typename T,typename U>
struct IF
{
	typedef T type;
};

template <typename T,typename U>
struct IF<false,T,U>                     //�ֲ��ػ�
{
	typedef U type;
};
#else
//��ĳЩ��ʽ����������֧��ģ��ֲ��ػ����������������һ���װ�Ϳ��������תΪʹ��ȫ���ػ���
template <bool B>
struct IF_impl
{
	template <typename T,typename U>
	struct result
	{
		typedef T type;
	};
};

template <>
struct IF_impl<false>
{
	template <typename T,typename U>
	struct result
	{
		typedef U type;
	};
};

template <bool B,typename T,typename U>
struct IF
{
	typedef typename IF_impl<B>::template result<T,U>::type type;
};
#endif

int main(void)
{
#if defined(__GNUC__) || defined(__clang__)
	cout<<"C++ version: "<<__cplusplus<<endl;
#elif defined(_MSC_VAR)
	cout<<"C++ version: "<<__MSVC_LANG<<endl;
#endif

#if HAS_CPP_14
	static_assert(!isZero<1>,"1 != 0");    //�����ž��൱��ʵ�ʵĲ������룬ֻ�����ڱ����ڼ���ɼ��㡣
	static_assert(isZero<0>,"0 == 0");
#elif HAS_CPP_11
	static_assert(!_IsZero<5>::value,"5 != 0");
	static_assert(_IsZero<0>::value,"0 == 0");
#else
#pragma message("Using C++98 standard!")
	cout<<"_IsZero<5>::value == 0 ? "<<_IsZero<5>::value<<endl;    //static_assert()��̬���Թ�����C++11������ġ�
	cout<<"_IsZero<0>::value == 0 ? "<<_IsZero<0>::value<<endl;
#endif	

#if HAS_CPP_14
	cout<<"isVoid<int>::value == ? "<<isVoid<int><<endl;
	cout<<"isVoid<void>::value == ? "<<isVoid<void><<endl;
#elif HAS_CPP_11
	cout<<"_IsVoid<int>::value =="<<_IsVoid<int>::value<<endl;
	cout<<"_IsVoid<void>::value =="<<_IsVoid<void>::value<<endl;
#endif

	TypeReplace<double>::type a = 3.14;
	TypeReplace<int>::type b = 5;
	typeReplace<char> c = 'a';
	typeReplace<int> d = -5;
	cout<<"a ="<<a<<" , "<<"b ="<<b<<" , "<<"c ="<<c<<" , "<<"d ="<<d<<endl;
	
	//����һ��ָ���ֽ����������͵ı��������û��ָ�����ȵ����ͣ�����뱨��
	IF<true,int,double>::type x = 10;
	IF<false,int,double>::type y = 0.618;
	cout<<"x ="<<x<<" , "<<typeid(x).name()<<endl;
	cout<<"y ="<<y<<" , "<<typeid(y).name()<<endl;
	
	const int len = 4;
    typedef
		IF<sizeof(char) == len, char,
		IF<sizeof(short)==len, short,
        IF<sizeof(int)==len, int,
        IF<sizeof(long)==len, long,
        void>::type>::type>::type>::type lenType;
	
	lenType var = 20;
	cout<<"var ="<<var<<" , sizeof(var) ="<<sizeof(var)<<endl;
}