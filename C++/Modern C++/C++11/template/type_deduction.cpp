#include <iostream>
#include <list>
#include <vector>
#include <iterator>

#define _ERROR_
#undef _ERROR_

#define _CHANGE_WAY_
#undef _CHANGE_WAY_

#define UNUSED(x) (void)x;

using namespace std;

//�β������Ƶ���ͨ�����ú���ģ��Ĳ����Ƶ����ƣ���ȡ��������ָ������������͡�
#ifdef _ERROR_
template <typename Iterator,typename T>
void printTwice_impl_98(Iterator iter)
{
	T temp = *iter + *iter;
	cout<<"printTwice_98(): "<<*iter<<"x 2 ="<<temp<<endl;
}
#else
template <typename Iterator,typename T>
void printTwice_impl_98(Iterator iter,T t)
{
	T temp = *iter + *iter;
	cout<<"printTwice_98(): "<<*iter<<" x 2 ="<<temp<<endl;
}
#endif  //_ERROR_

#ifndef _CHANGE_WAY_
template <typename Iterator>
void printTwice_98(Iterator iter)
{
#ifdef _ERROR_
	/*����ģ�����Ҫ�������ͻ�����ڳ�������*iter���������������㣬����Ϊ����ʱ�ĺ������á�
	 *���Ա��벻ͨ����
	 */
	printTwice_impl_98<Iterator,*iter>(iter);
#else
	printTwice_impl_98(iter,*iter);
#endif  //_ERROR_
}
#else  //_CHANGE_WAY_
template <typename Iterator,typename T>
void printTwice_98(Iterator iter)
{
	T temp = *iter + *iter;
	cout<<"printTwice_98(): "<<*iter<<" x 2 ="<<temp<<endl;
}
#endif  //_CHANGE_WAY_

#ifndef _CHANGE_WAY_
template <typename Iterator>
void printTwice_03(Iterator iter)
{
	typename Iterator::value_type temp = *iter + *iter;
	cout<<"printTwice_03(): "<<*iter<<" x 2 ="<<temp<<endl;
}
#else
template <typename Iterator>
void printTwice_03(Iterator iter)
{
	typename iterator_traits<Iterator>::value_type temp = *iter + *iter;
	cout<<"printTwice_03(): "<<*iter<<" x 2 ="<<temp<<endl;
}
#endif

#ifndef _CHANGE_WAY_
template <typename Iterator>
void printTwice_11(Iterator iter)
{
	auto temp = *iter + *iter;
	cout<<"printTwice_11(): "<<*iter<<" x 2 ="<<temp<<endl;
}
#else
template <typename Iterator>
void printTwice_11(Iterator iter)
{
	decltype(*iter + *iter) temp = *iter + *iter;
	cout<<"printTwice_11(): "<<*iter<<" x 2 ="<<temp<<endl;
}
#endif

//����ֵ�����Ƶ�������ģ��Ĳ����Ƶ������Ƶ���ֻ�ǲ������޷��Ƶ������ķ���ֵ���͡�
#ifdef _ERROR_
template <typename Iterator>
(*Iterator) add_98(Iterator iter1,Iterator iter2)   //����ʧ�ܡ����ڷ���ֵ�������Ƶ�����ȷ��������ͨ������һ��ģ�������Ƶ�������ֵ�����͡�
{
	return *iter1 + *iter2;
}
#else
template <typename Iterator,typename T>
T add_98(Iterator iter1,Iterator iter2)
{
	return *iter1 + *iter2;
}
#endif

#ifndef _CHANGE_WAY_
template <typename Iterator>
typename Iterator::value_type add_03(Iterator iter1,Iterator iter2)
{
	return *iter1 + *iter2;
}
#else
template <typename Iterator>
typename iterator_traits<Iterator>::value_type add_03(Iterator iter1,Iterator iter2)
{
	return *iter1 + *iter2;
}
#endif

template <typename Iterator>
auto add_11(Iterator iter1,Iterator iter2) -> decltype(*iter1 + *iter2)
{
	return *iter1 + *iter2;
}

template <typename Iterator>
auto add_14(Iterator iter1,Iterator iter2)
{
	return *iter1 + *iter2;
}

int main(int argc,char** argv)
{
	UNUSED(argc);
	UNUSED(argv);
	
	list<double> mylist = {3.14,2.718,0.618,1.414,1.732};
	list<double>::iterator listIter = mylist.begin();
	
#ifndef _CHANGE_WAY_
	printTwice_98(listIter++);
	printTwice_03(listIter++);
	printTwice_11(listIter++);
#else
	printTwice_98<list<double>::iterator,double>(++listIter);
	printTwice_03(++listIter);
	printTwice_11(++listIter);
#endif

	vector<int> vec = {1,2,3,4,5,6,7,8,9};
	vector<int>::iterator vecIter = vec.begin();
#ifdef _ERROR_
	cout<<"add_98("<<*vecIter<<","<<*(vecIter + 1)<<") ="<<add_98(vecIter,vecIter + 1)<<endl;
#else
	cout<<"add_98("<<*vecIter<<","<<*(vecIter + 1)<<") ="<<add_98<vector<int>::iterator,int>(vecIter,vecIter + 1)<<endl;
#endif
	
	cout<<"add_03("<<*(vecIter + 2)<<","<<*(vecIter + 3)<<") ="<<add_03(vecIter + 2,vecIter + 3)<<endl;
	cout<<"add_11("<<*(vecIter + 4)<<","<<*(vecIter + 5)<<") ="<<add_11(vecIter + 4,vecIter + 5)<<endl;
	cout<<"add_14("<<*(vecIter + 6)<<","<<*(vecIter + 7)<<") ="<<add_14(vecIter + 6,vecIter + 7)<<endl;
	
	return 0;
}