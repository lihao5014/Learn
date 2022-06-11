#ifndef _SQRT_HPP_
#define _SQRT_HPP_

#include "conditional.hpp"

#define _CHANGE_WAY_  1<<2    ////1<<0 = 0b001, 1<<1 = 0b010, 1<<2 = 0b100

#if (_CHANGE_WAY_ & 0b001)
//������ʹ�ö��ַ������㷨����������ƽ����������ȡ����
template <int N,int Low = 0,int High = N>
struct Sqrt
{
	enum{Mid = (Low + High + 1)/2};
	
	/*��ģ��Ԫ����У�����Ҫ�������������������?:����ִ��·��ѡ����Ϊ��ᵼ��������֧��
	 *�ĵݹ�ģ�嶼�ᱻʵ���������������Ӵ��ʵ�����塣�������յ�ʵ����������Լ��N��2��
	 */
	enum{result = (N < Mid * Mid) ? Sqrt<N,Low,Mid-1>::result : Sqrt<N,Mid,High>::result};
};

//��ֹ�ݹ�ľֲ���������������Low����High�ĳ���
template <int N,int Mid>
struct Sqrt<N,Mid,Mid>
{
	enum{result = Mid};
};
#elif (_CHANGE_WAY_ & 0b010)
//������ʹ�ö��ַ������㷨����������ƽ����������ȡ����
template <int N,int Low = 0,int High = N>
struct Sqrt
{
	enum{Mid = (Low + High)/2};
	
	/*����Ӧ��ʹ�ñ���ʱ��֧�����ִ��·��ѡ����Conditional<bool,Then,Else>ģ����ػ���typeֻ����
	 *����һ�����ͣ�ע���Then/Else����typedef��type�����ᵼ�±�ʵ�����������ղ��ҽ��type::resultʱ��
	 *�ͻ�ʵ����type���ͣ��ɼ���ֻʵ������һ��Conditional�е�һ����֧�����յ�ʵ��������������lg(N)��
	 *�����ڶ��ֲ��ҵ�ʵ���У����������е�һ����֧���ͣ���󷵻�ʱӦ����Mid=Highʱ��Sqrt<N,Mid,High>��
	 *��˱����ṩһ��Mid=High���ػ�������Sqrtģ��ĵݹ飬���򻹻���ȥʵ����Sqrt<N,Mid,High>��
	 */
	typedef typename Conditional<(N < Mid*Mid),Sqrt<N,Low,Mid-1>,Sqrt<N,Mid+1,High>>::type resultType;
	
	//ִ�ж��ֲ��ң��õݹ�ģ�壬�ҵ���������ͣ�Ȼ�󷵻ؽ����
	enum{result = resultType::result};
};

//��ֹ�ݹ�ľֲ���������������Low����High�ĳ���
template <int N,int Mid>
struct Sqrt<N,Mid,Mid>
{
	enum{result = Mid};
};
#elif (_CHANGE_WAY_ & 0b100)
//������ʹ�õ��������㷨����������ƽ����������ȡ����
template <int N>
struct Number          //��װ����N��ģ�壬ʹN��Ϊһ������Number<N>
{
	enum{result = N};
};

//��0��ʼ���������ҵ�N��ƽ����������ȡ����
template <int N,int I=0>
struct Sqrt
{
	/*�ڵ������ҵ�ʵ���У���I*I>=Nʱģ��ݹ��������ʱ����Number<I>��֧��
	 *��Number<I>::resultֱ�ӷ��ؼ�����Ľ�����ݹ��������˲���Ҫ�ṩ
	 *Sqrt���ػ��������ݹ顣
	 */
	typedef typename Conditional<(I*I < N),Sqrt<N,I+1>,Number<I>>::type resultType;
	
	//ִ��ѭ���������õݹ�ģ�壬�ҵ���������ͣ�Ȼ�󷵻ؽ����
	enum{result = resultType::result};
};
#endif  //_CHANGE_WAY_

#endif  //_SQRT_HPP_