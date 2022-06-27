#include <iostream>
#include <list>
#include <vector>
#include <iterator>    //iterator_traits,advance(),distance()
#include <algorithm>    //for_each()

#define _ERROR_
#undef _ERROR_

#define _CHANGE_WAY_
// #undef _CHANGE_WAY_

#define UNUSED(x) (void)x;

using namespace std;

//�β������Ƶ���ͨ�����ú���ģ��Ĳ����Ƶ����ƣ���ȡ��������ָ������������͡�
#ifndef _CHANGE_WAY_
template <typename Iterator,typename T>
void swap_impl_98(Iterator iter1,Iterator iter2,T t)
{
	T temp = *iter1;     //���ú���ģ��Ĳ����Ƶ����ƣ�����һ���ԡ���������ָ��������͡�Ϊ���͵ı�����
	*iter1 = *iter2;
	*iter2 = temp;
}

template <typename Iterator>
void swap_98(Iterator iter1,Iterator iter2)
{
	swap_impl_98(iter1,iter2,*iter1);     //����iter��*iter��ָ��ֵ�������Զ��Ƶ���
}
#else
/*���û��һ��swap_impl_98()�����ķ�װ�Ļ���ÿ�ζ�Ҫ��ʽ��˵��������ָ���������ͣ�
 *�����½�temp��������һ���װ�Ե���ˬ�ܶࡣ
 */
template <typename Iterator,typename T>
void swap_98(Iterator iter1,Iterator iter2)
{
	T temp = *iter1;
	*iter1 = *iter2;
	*iter2 = temp;
}
#endif

#ifndef _CHANGE_WAY_
template <typename Iterator>
void swap_03(Iterator iter1,Iterator iter2)
{
	typename Iterator::value_type temp = *iter1;
	*iter1 = *iter2;
	*iter2 = temp;
}
#else
//ʹ��iterator_traits����������ȡ����������ͳһ��������ԭʼָ��ĵ��ýӿڡ�
template <typename Iterator>
void swap_03(Iterator iter1,Iterator iter2)
{
	typename iterator_traits<Iterator>::value_type temp = *iter1;
	*iter1 = *iter2;
	*iter2 = temp;
}	
#endif

#ifndef _CHANGE_WAY_
template <typename Iterator>
void swap_11(Iterator iter1,Iterator iter2)
{
	auto temp = *iter1;
	*iter1 = *iter2;
	*iter2 = temp;
}
#else
template <typename Iterator>
void swap_11(Iterator iter1,Iterator iter2)
{
	decltype(*iter1 + 1) temp = *iter1;
	*iter1 = *iter2;
	*iter2 = temp;
}
#endif

//����ֵ�����Ƶ�������ģ��Ĳ����Ƶ������Ƶ���ֻ�ǲ������޷��Ƶ������ķ���ֵ���͡�
template <typename Iterator,typename T>
T sum_98(Iterator begin,Iterator end)
{
	T result = T(0);
	for(Iterator iter = begin;iter != end;++iter)
	{
		result += *iter;
	}
	
	return result;
}

#ifndef _CHANGE_WAY_
/*Iterator��������Ƕ����value_type��ʹ���ǿ���ֱ�ӻ�ȡ��������ָ��������͡�
 *�����Ϳ��������Ƶ������ķ���ֵ���͡����ǲ��������е���������class type��
 *ԭ��ָ��Ͳ��������͡��������class type�����޷�Ϊ��������Ƕ���͡�
 */
template <typename Iterator>
typename Iterator::value_type sum_03(Iterator begin,Iterator end)
{
	typename Iterator::value_type result = 0;
	for(Iterator iter = begin;iter != end;++iter)
	{
		result += *iter;
	}
	
	return result;
}
#else
/*ͨ��������Ƕ���ͣ����ǻ����֪��iterator��ָԪ�����͵ķ�����ͨ��traits������
 *������ģ�����ԭ��ָ����Զ���iterator�Ķ���ʵ����ͳһ��
 */
template <typename Iterator>
typename iterator_traits<Iterator>::value_type sum_03(Iterator begin,Iterator end)
{
	typename iterator_traits<Iterator>::value_type result = 0;
	for(Iterator iter = begin;iter != end;++iter)
	{
		result += *iter;
	}
	
	return result;
}
#endif

template <typename Iterator>
auto sum_11(Iterator begin,Iterator end) -> decltype(*begin + *end)
{
	auto result = *begin;
	for(Iterator iter = begin + 1;iter != end;++iter)
	{
		result += *iter;
	}
	
	return result;
}

template <typename Iterator>
auto sum_14(Iterator begin,Iterator end)
{
	decltype(*begin) result = 0;
	for(Iterator iter = begin;iter != end;++iter)
	{
		result += *iter;
	}
	
	return result;
}

template <typename Iterator>
static Iterator moveTo(Iterator iter,int n)
{
	Iterator tempIter = iter;
	std::advance(tempIter,n);
	return tempIter;
}

template <class T>
static void print(const T& n)
{
	cout<<n<<" ";
}

template <typename T>
class Display
{
public:
	void operator ()(const T& n)
	{
		cout<<n<<" ";
	}
};

auto main(int argc,char** argv) -> int
{
	UNUSED(argc);
	UNUSED(argv);
	
	double arr[] = {3.14,2.718,0.618,1.414,1.732};
	list<double> mylist(arr,arr + sizeof(arr)/sizeof(double));
	for_each(mylist.begin(),mylist.end(),print<double>);
	cout<<endl;
	
	list<double>::iterator listIter = mylist.begin();
	std::advance(listIter,2);
	cout<<"mylist.at(2) ="<<*listIter<<endl;

#ifndef _CHANGE_WAY_
	swap_98(mylist.begin(),listIter);
#else
	swap_98<list<double>::iterator,double>(mylist.begin(),listIter);
#endif
	for_each(mylist.begin(),mylist.end(),[](double n){cout<<n<<" ";});
	cout<<endl;

#ifdef _CHANGE_WAY_
	swap_03(arr,arr + 2);
	for_each(arr,arr + sizeof(arr)/sizeof(arr[0]),[](double n){cout<<n<<" ";});
	cout<<endl;
#endif
	swap_03(moveTo(mylist.begin(),1),++listIter);
	for_each(mylist.begin(),mylist.end(),[](double n){cout<<n<<" ";});
	cout<<endl;
	
	swap_11(mylist.begin(),moveTo(mylist.begin(),mylist.size() - 1));
	for_each(mylist.begin(),mylist.end(),Display<double>());
	cout<<endl;
	
	vector<int> vec = {1,2,3,4,5,6,7,8,9};
	for_each(vec.begin(),vec.end(),Display<double>());
	cout<<endl;
	
	vector<int>::iterator vecIter = vec.begin();
	std::advance(vecIter,4);
	cout<<"vec[4] ="<<*vecIter<<endl;

	cout<<"sum_98() ="<<sum_98<vector<int>::iterator,int>(vec.begin(),vec.end())<<endl;
#ifdef _CHANGE_WAY_
	cout<<"sum_03() ="<<sum_03(arr,arr + sizeof(arr)/sizeof(arr[0]))<<endl;
#endif
	cout<<"sum_03() ="<<sum_03(vec.begin(),vec.end())<<endl;
	cout<<"sum_11() ="<<sum_11(vec.begin(),vec.end())<<endl;
	cout<<"sum_14() ="<<sum_11(vec.begin(),vec.end())<<endl;
	
	return 0;
}