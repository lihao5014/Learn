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
 *     ������ֵ���д������������д洢�����ݱ��Ρ�
 *��2�����Ӿ���һ��ʵ����map��Լ�Ķ���ʹ�ú��ӿ���ʵ����ʽ��̡�����ʽ��̵����㲻ֱ�Ӳ���ֵ��
 *     �����ɺ�����ɡ�
 *��5�����԰Ѻ��������һ�����ӣ�����������װ��һ��ֵ����Ҫ���������е�ֵ��������Ҫ�����ӵ�map����
 *     ����һ������ֵ�ĺ������������������ֵ���д���������map��������һ��������ֵ�ĺ��ӣ����ӣ���
 */

#include <iostream>
#include <list>
#include <initializer_list>
#include <functional>       //function,bind(),bind1st(),bind2nd(),not1(),not2()
#include <algorithm>        //for_each(),transform(),copy_if(),accumulate()
#include <numeric>          //accumulate()
#include <iterator>         //std::back_inserter

using namespace std;

/*ListWraper������һ�����ӣ����Ժܷ����ʵ�ֺ���ʽ����е���ʽ����ʽ��
 *���е�map(),filter()��fold()���������ڸ߽׺�����
 */
template <typename T>
class ListWraper
{
public:
	ListWraper() = default;
	ListWraper(std::list<T> ls);
	ListWraper(std::initializer_list<T> ls);
	ListWraper(const ListWraper& other);
	
	ListWraper map(function<T(T)> fn);
	ListWraper filter(function<bool(T)> fn);
	
	T fold(T init);
	T fold(T init,function<T(T,T)> fn);

	void display()const;
private:
	std::list<T> m_ls;
};

template <typename T>
ListWraper<T>::ListWraper(std::list<T> ls)
	:m_ls(ls)
{
	
}

template <typename T>
ListWraper<T>::ListWraper(std::initializer_list<T> ls)
	:m_ls(ls)
{
	
}

template <typename T>
ListWraper<T>::ListWraper(const ListWraper& other)
	:m_ls(other.m_ls)
{
	
}

#ifndef _CHANGE_WAY_
template <typename T>
ListWraper<T> ListWraper<T>::map(function<T(T)> fn)
{
	std::list<T> out;
	for(const T& val : m_ls)
	{
		out.push_back(fn(val));
	}
	return ListWraper<T>(out);
}

template <typename T>
ListWraper<T> ListWraper<T>::filter(function<bool(T)> fn)
{
	std::list<T> out;
	for(const T& val : m_ls)
	{
		if(fn(val))
		{
			out.push_back(val);
		}
	}
	return ListWraper<T>(out);
}

template <typename T>
T ListWraper<T>::fold(T init)
{
	T ret = init;
	for(const T& val : m_ls)
	{
		ret += val;
	}
	return ret;
}

template <typename T>
T ListWraper<T>::fold(T init,function<T(T,T)> fn)
{
	T ret = init;
	for(const T& val : m_ls)
	{
		ret = fn(ret,val);
	}
	return ret;
}
#else
template <typename T>
ListWraper<T> ListWraper<T>::map(function<T(T)> fn)
{
	std::list<T> out;
	transform(m_ls.begin(),m_ls.end(),back_inserter(out),fn);
	return ListWraper<T>(out);
}

template <typename T>
ListWraper<T> ListWraper<T>::filter(function<bool(T)> fn)
{
	std::list<T> out;
	copy_if(m_ls.begin(),m_ls.end(),back_inserter(out),fn);
	return ListWraper<T>(out);
}

template <typename T>
T ListWraper<T>::fold(T init)
{
	return accumulate(m_ls.begin(),m_ls.end(),init);
}

template <typename T>
T ListWraper<T>::fold(T init,function<T(T,T)> fn)
{
	return accumulate(m_ls.begin(),m_ls.end(),init,fn);
}
#endif

/*��1��for each(in)�﷨��msvc��������չ��C++�﷨������C++��׼��gcc��������֧�֣�
 *     ���Բ��Ƽ�ʹ�á���׼C++��֧�ֵ��Ƿ�Χfor(:)ѭ����
 *��2��cl������ʹ��/Zeѡ������C++������չ(Ĭ��)��/Za����������չ��
 */
#ifndef _CHANGE_WAY_
template <typename T>
void ListWraper<T>::display()const
{
	for each(const T& val in m_ls)
	{
		cout<<val<<" ";
	}
	cout<<endl;
}
#else
template <typename T>
void ListWraper<T>::display()const
{
	for_each(m_ls.begin(),m_ls.end(),[](const T& n){cout<<n<<" ";});    //C++14��׼��֧��lambdaģ��
	cout<<endl;
}
#endif

int main(void)
{
	ListWraper<int> mylist = {4,5,8,9,3,1,7,2,6,0};
	mylist.map([](int x){return x + 10;}).display();
	mylist.map([](int x){return x + 10;}).filter(bind2nd(std::less<int>(),15)).display();
	
	int ret = mylist.map([](int x){return x + 10;}).filter(bind2nd(std::less<int>(),15)).fold(0);
	cout<<"ret ="<<ret<<endl;
	
	ret = mylist.map([](int x){return x + 10;}).filter(bind2nd(std::less<int>(),15)).fold(1,[](int x,int y){return x * y;});
	cout<<"ret ="<<ret<<endl;
	
	return 0;
}
