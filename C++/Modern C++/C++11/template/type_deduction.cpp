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

//形参类型推导：通过利用函数模板的参数推导机制，获取迭代器所指对象的数据类型。
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
	/*函数模板参数要求是类型或编译期常量，而*iter迭代器解引用运算，被视为运行时的函数调用。
	 *所以编译不通过。
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

//返回值类型推导：函数模板的参数推导机制推导的只是参数，无法推导函数的返回值类型。
#ifdef _ERROR_
template <typename Iterator>
(*Iterator) add_98(Iterator iter1,Iterator iter2)   //编译失败。对于返回值的类型推导，正确的做法是通过构建一个模板类来推导出返回值的类型。
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