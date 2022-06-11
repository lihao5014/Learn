/*1.ģ��Ԫ����г��õ��﷨Ԫ�أ�
 *��1��״̬������Ҳ����ģ�������
 *��2���������죨�൱��ѭ����䣩��ͨ���ݹ�ģ�塣
 *��3��·��ѡ���൱��������䣩��ͨ��ʹ���ػ����������ʽ��?:����
 *��4�����Ͷ����൱�ڱ���������enum�����ö��ֵ��static const������
 */

#ifndef _PRIME_HPP_
#define _PRIME_HPP_

#define _CHANGE_WAY_
// #undef _CHANGE_WAY_

#include <iostream>

template <bool B,typename Then,typename Else>
struct IF
{
	
};

template <typename Then,typename Else>
struct IF<true,Then,Else>
{
	typedef Then type;
};

template <typename Then,typename Else>
struct IF<false,Then,Else>
{
	using type = Else;
};

#ifndef _CHANGE_WAY_
template <bool B>
struct Boolean
{
	static const bool value = B;
};

template <int N,int I=2>
struct IsPrime
{
	typedef typename IF<(N%I == 0),Boolean<false>,IsPrime<N,I+1>>::type resultType;
	
	static const bool value = resultType::value;
};

template <int N>
struct IsPrime<N,N>
{
	static const bool value = true;
};

template <>
struct IsPrime<2,2>
{
	static const bool value = true;
};

template <>
struct IsPrime<1,2>
{
	static const bool value = true;
};

template <>
struct IsPrime<0,2>
{
             //0�Ȳ�������Ҳ���Ǻ���
};
#else
template <int N,int I=N-1>
struct IsPrime
{
	enum{value = (N%I != 0) && IsPrime<(I > 2) ? N : 2,I-1>::value};
};

template <>
struct IsPrime<2,1>
{
	enum{value = true};
};

template <>
struct IsPrime<1,0>
{
	enum{value = true};
};

template <>
struct IsPrime<0,-1>
{
             //0�Ȳ�������Ҳ���Ǻ���
};
#endif   //_CHANGE_WAY_

//��ӡN���µ���������
template <int N>
struct PrimePrinter
{
	enum{flag = IsPrime<N>::value};
	
	static void print()
	{
		if(flag)
		{
			std::cout<<N<<" ";
		}
		
		PrimePrinter<N - 1>::print();
	}
};

template <>
struct PrimePrinter<2>
{
	static void print()
	{
		std::cout<<std::endl;
	}
};

#endif  //_PRIME_HPP_