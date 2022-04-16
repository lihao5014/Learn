/*1.���������ã�
 *������������ָ�����ú���ʱ�����˷��غ���ֵ֮�⣬���������ú����������ӵ�Ӱ�졣
 *�����õĺ���������ֻ�Ƿ�����һ��ֵ�����һ��������������顣һ����״̬���������
 *���������ã�����������״̬��������������������á�
 */
 
/*2.�����ĺ��������ã�
 *��1���޸���һ��������
 *��2��ֱ���޸����ݽṹ��
 *��3������һ������ĳ�Ա��
 *��4���׳�һ���쳣����һ��������ֹ��
 *��5����ӡ���ն˻��ȡ�û����롣
 *��6����ȡ��д��һ���ļ���
 *��7������Ļ�ϻ�ͼ��
 */

/*3.���ӣ�
 *��1��������һ�������������ͨ��һ����ͨ������ʵ�֣��ö������map()������map()������������һ��
 *     ������ֵ���д����������д洢�����ݱ��Ρ�
 *��2�����Ӿ���һ��ʵ����map��Լ�Ķ���ʹ�ú��ӿ���ʵ����ʽ��̡�����ʽ��̵����㲻ֱ�Ӳ���ֵ��
 *     �����ɺ�����ɡ�
 *��5�����԰Ѻ��������һ�����ӣ�����������װ��һ��ֵ����Ҫ��������е�ֵ��������Ҫ�����ӵ�map����
 *     ����һ������ֵ�ĺ������������������ֵ���д�������map��������һ��������ֵ�ĺ��ӣ����ӣ���
 */

#include <iostream>
#include <list>
#include <vector>
#include <initializer_list>
#include <functional>       //function,bind(),bind1st(),bind2nd(),not1(),not2()
#include <algorithm>        //for_each(),transform(),copy_if(),accumulate()
#include <numeric>          //accumulate()
#include <iterator>         //std::back_inserter

using namespace std;

/*ContainerProxy������һ�����ӣ����Ժܷ����ʵ�ֺ���ʽ����е�pipeline������ʽ��
 *���е�map(),filter()��fold()���������ڸ߽׺�����
 */
template <typename T,class C = std::vector<T>>
class ContainerProxy
{
public:
	ContainerProxy() = default;
	ContainerProxy(C seq);
	ContainerProxy(std::initializer_list<T> ls);
	ContainerProxy(const ContainerProxy& other);
	
	ContainerProxy map(function<T(T)> fn);
	ContainerProxy filter(function<bool(T)> fn);
	
	T fold(T init);
	T fold(T init,function<T(T,T)> fn);

	void display()const;
private:
	C m_seq;
};

template <typename T,class C>
ContainerProxy<T,C>::ContainerProxy(C seq)
	:m_seq(seq)
{
	
}

template <typename T,class C>
ContainerProxy<T,C>::ContainerProxy(std::initializer_list<T> ls)
	:m_seq(ls)
{
	
}

template <typename T,class C>
ContainerProxy<T,C>::ContainerProxy(const ContainerProxy& other)
	:m_seq(other.m_seq)
{
	
}

#ifndef _CHANGE_WAY_
template <typename T,class C>
ContainerProxy<T,C> ContainerProxy<T,C>::map(function<T(T)> fn)
{
	C out;
	for(const T& val : m_seq)
	{
		out.push_back(fn(val));
	}
	return ContainerProxy<T,C>(out);
}

template <typename T,class C>
ContainerProxy<T,C> ContainerProxy<T,C>::filter(function<bool(T)> fn)
{
	C out;
	for(const T& val : m_seq)
	{
		if(fn(val))
		{
			out.push_back(val);
		}
	}
	return ContainerProxy<T,C>(out);
}

template <typename T,class C>
T ContainerProxy<T,C>::fold(T init)
{
	T ret = init;
	for(const T& val : m_seq)
	{
		ret += val;
	}
	return ret;
}

template <typename T,class C>
T ContainerProxy<T,C>::fold(T init,function<T(T,T)> fn)
{
	T ret = init;
	for(const T& val : m_seq)
	{
		ret = fn(ret,val);
	}
	return ret;
}
#else
template <typename T,class C>
ContainerProxy<T,C> ContainerProxy<T,C>::map(function<T(T)> fn)
{
	C out;
	transform(m_seq.begin(),m_seq.end(),back_inserter(out),fn);
	return ContainerProxy<T,C>(out);
}

template <typename T,class C>
ContainerProxy<T,C> ContainerProxy<T,C>::filter(function<bool(T)> fn)
{
	C out;
	copy_if(m_seq.begin(),m_seq.end(),back_inserter(out),fn);
	return ContainerProxy<T,C>(out);
}

template <typename T,class C>
T ContainerProxy<T,C>::fold(T init)
{
	return accumulate(m_seq.begin(),m_seq.end(),init);
}

template <typename T,class C>
T ContainerProxy<T,C>::fold(T init,function<T(T,T)> fn)
{
	return accumulate(m_seq.begin(),m_seq.end(),init,fn);
}
#endif

/*��1��for each(in)�﷨��msvc��������չ��C++�﷨������C++��׼��gcc��������֧�֣�
 *     ���Բ��Ƽ�ʹ�á���׼C++��֧�ֵ��Ƿ�Χfor(:)ѭ����
 *��2��cl������ʹ��/Zeѡ������C++������չ(Ĭ��)��/Za����������չ��
 */
#ifndef _CHANGE_WAY_
template <typename T,class C>
void ContainerProxy<T,C>::display()const
{
	for each(const T& val in m_seq)
	{
		cout<<val<<" ";
	}
	cout<<endl;
}
#else
template <typename T,class C>
void ContainerProxy<T,C>::display()const
{
	for(const T& val : m_seq)
	{
		cout<<val<<" ";
	}
	cout<<endl;
}
#endif

int main(void)
{
#ifndef _CHANGE_WAY_
	ContainerProxy<int,list<int>> containerProxy = {4,5,8,9,3,1,7,2,6,0};
#else
	ContainerProxy<int,vector<int>> containerProxy = {6,7,3,8,5,4};
#endif

	containerProxy.map([](int x){return x + 10;}).display();
	containerProxy.map([](int x){return x + 10;}).filter(bind2nd(std::less<int>(),15)).display();
	
	int ret = containerProxy.map([](int x){return x + 10;}).filter(bind2nd(std::less<int>(),15)).fold(0);
	cout<<"ret ="<<ret<<endl;
	
	ret = containerProxy.map([](int x){return x + 10;}).filter(bind2nd(std::less<int>(),15)).fold(1,[](int x,int y){return x * y;});
	cout<<"ret ="<<ret<<endl;
	
	return 0;
}
