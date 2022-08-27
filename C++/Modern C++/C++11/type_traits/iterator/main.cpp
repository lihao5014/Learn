#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <iostream>
#include <utility>      //std::move()
#include <algorithm>
#include <iterator>
#include "array.hpp"
#include "linklist.hpp"
#include "doublelist.hpp"
#include "circularlist.hpp"
#include "algorithm.hpp"

#define _ERROR_
#undef _ERROR_

using std::cout;
using std::endl;

using namespace Learn;

static int randomNumber()
{
	return rand() % 100;
}

struct
{
	int m_current = 0;        //C++11中的类内部初始化。
	int operator()()
	{
		return m_current++;
	}
}uniqueNumber;

static void test_Array();
static void test_LinkList();
static void test_DoubleList();
static void test_CircularList();
static void test_advance();
static void test_distance();

auto main(int argc,char* argv[]) -> int
{
	srand((unsigned int)time(NULL));
	
	// test_Array();
	// test_LinkList();
	// test_DoubleList();
	 // test_CircularList();
	test_advance();
	// test_distance();
	
	return 0;
}

void test_Array()
{
#ifdef _ERROR_
	//Array构造函数中使用了static_assert关键字，进行了静态断言。限制了数组长度小于等于0的情况。
	Array<char,0> vec;
#endif

	Array<int,5> arr(5);
	for(Array<int,5>::const_iterator iter = arr.cbegin();iter != arr.cend();++iter)
	{
		cout<<*iter<<" ";
	}
	cout<<"\n";
	
	cout<<"arr.size() ="<<arr.size()<<" ,arr.empty() ="<<arr.empty()<<" ,arr.at(3) ="<<arr.at(3)<<endl;
	
	arr[3] = 10;
	cout<<"arr[0] ="<<arr[0]<<" ,arr[3] ="<<arr[3]<<endl;
	
	Learn::fill(arr.begin(),arr.end(),15);
	::foreach(arr.cbegin(),arr.cend(),[](const int& n){cout<<n<<" ";});
	cout<<"\n";
	
	generate(arr.begin(),arr.end(),randomNumber);
	Learn::foreach(arr.begin(),arr.end(),[](const int& n){cout<<n<<" ";});
	cout<<"\n";
	
	::generate(arr.begin(),arr.end(),uniqueNumber);
	foreach(arr.begin(),arr.end(),[](const int& n){cout<<n<<" ";});
	cout<<"\n";
	
	Array<double,5> seq = {3.14,2.718,0.618,1.414,9.78};
	foreach(seq.cbegin(),seq.cend(),[](const double& n){cout<<n<<" ";});
	cout<<endl;
	
	Array<double,5> series = seq;
	std::for_each(series.begin(),series.end(),[](const double& n){cout<<n<<" ";});
	cout<<"\n";
	
	if(series == seq)
	{
		cout<<"series is equal seq"<<endl;
	}
	else
	{
		cout<<"series isn't equal seq"<<endl;
	}
	
	series = Array<double,5>{1.5,2.5,3.5,4.5,5.5};
	for(const double& n : series)
	{
		cout<<n<<" ";
	}
	cout<<endl;	
	
	Learn::swap(series.begin(),series.begin() + 2);
	std::for_each(series.begin(),series.end(),[](const double& n){cout<<n<<" ";});
	cout<<"\n";
	
	Array<double,5>::iterator itr = Learn::find_if(series.begin(),series.end(),[](const double& n){return n > 1 && n < 2;});
	if(itr != series.end())
	{
		cout<<"find greater than 3 and less than 4 number in series: "<<*itr<<" ,at "<<itr - series.begin()<<endl;
	}
	else
	{
		cout<<"can't find greater than 4 and less than 4 number in series"<<endl;
	}
	
	itr = series.begin();
	itr += 4;
	cout<<"*itr ="<<*itr<<endl;
	
	itr -= 2;
	cout<<"*itr ="<<*itr<<endl;
}

//C++函数作用域中可以定义struct结构体或class类。
void test_LinkList()
{
	struct Print
	{
		void operator ()(const char& ch)
		{
			cout<<ch<<" ";
		}
	};
	
	LinkList<char> ls;
	ls.push_front('a');
	ls.push_front('b');
	ls.push_front('c');
	ls.push_front('d');
	ls.push_front('e');
	std::for_each(ls.begin(),ls.end(),Print());
	cout<<"\n";
	
	cout<<"ls.size() ="<<ls.size()<<" ,ls.empty() ="<<ls.empty()<<" ,ls.front() ="<<ls.front()<<endl;
	
	ls.front() = 'z';
	ls.remove('b');
	LinkList<char>::iterator iter = ls.begin();
	for(;iter != ls.end();++iter)
	{
		cout<<*iter<<" ";
	}
	cout<<endl;
	
	iter = ls.begin();
	iter++;
	iter = ls.erase_after(iter);
	iter = ls.insert_after(iter,'x');
	iter = ls.insert_after(iter,'y');
	ls.pop_front();
	for(iter = ls.begin();iter != ls.end();iter++)
	{
		cout<<*iter<<" ";
	}
	cout<<"\n";
	
	ls.clear();
	cout<<"ls.size() ="<<ls.size()<<" ,ls.empty() ="<<ls.empty()<<endl;
	
	LinkList<int> series = {1,2,3,4,5,6,7,8,9};
	foreach(series.begin(),series.end(),[](const int& n){cout<<n<<" ";});
	cout<<"\n";
	
	series.pop_front();
	series.pop_front();
	
	LinkList<int>::iterator itr = series.begin();
	itr++;
	++itr;
	itr = series.erase_after(itr);
	itr = series.erase_after(itr);
	
	cout<<"series.size() ="<<series.size()<<" ,series.empty() ="<<series.empty()<<" ,series.front() ="<<series.front()<<endl;
	
	LinkList<int> sequence = series;
	for(const int& n : sequence)
	{
		cout<<n<<" ";
	}
	cout<<endl;
	
	LinkList<int> range;
	range = series;
	std::for_each(range.begin(),range.end(),[](const auto& n){cout<<n<<" ";});
	cout<<endl;
	
	LinkList<int> seq(std::move(series));
	cout<<"series.size() ="<<series.size()<<" ,series.empty() ="<<series.empty()<<endl;
	foreach(seq.begin(),seq.end(),[](const int& n){cout<<n<<" ";});
	cout<<"\n";
	
	itr = series.begin();
	itr = series.insert_after(itr,15);
	itr = series.insert_after(itr,16);
	series.push_front(17);
	series.push_front(18);
	cout<<"series.size() ="<<series.size()<<" ,series.empty() ="<<series.empty()<<endl;
	std::for_each(series.begin(),series.end(),[](const int& n){cout<<n<<" ";});
	cout<<"\n";
	
	seq = std::move(series);
	cout<<"series.size() ="<<series.size()<<" ,series.empty() ="<<series.empty()<<endl;
	foreach(seq.begin(),seq.end(),[](const int& n){cout<<n<<" ";});
	cout<<"\n";
}

void test_DoubleList()
{
	struct
	{
		void operator ()(const int& n)
		{
			cout<<n<<" ";
		}
	}show;
	
	DoubleList<int> ls;
	ls.push_back(1);
	ls.push_back(2);
	ls.push_back(2);
	ls.push_front(3);
	ls.push_front(4);
	ls.push_front(4);
	std::for_each(ls.cbegin(),ls.cend(),show);
	cout<<"\n";
	
	DoubleList<int>::const_iterator citer = ls.rcbegin();    //倒序打印
	for(;citer != ls.rcend();--citer)
	{
		cout<<*citer<<" ";
	}
	cout<<endl;
	
	cout<<"ls.size() ="<<ls.size()<<" ,ls.empty() ="<<ls.empty()<<"\n"
		<<"ls.front() ="<<ls.front()<<" ,ls.back() ="<<ls.back()<<endl;
	
	ls.front() *= 2;
	ls.back() *= 3;
	ls.remove(2);
	for(citer = ls.cbegin();citer != ls.cend();++citer)
	{
		cout<<*citer<<" ";
	}
	cout<<"\n";
	 
	for(citer = ls.rcbegin();citer != ls.rcend();--citer)    //倒序打印
	{
		cout<<*citer<<" ";
	}
	cout<<endl;
	
	citer = ls.cbegin();
	citer++;
	++citer;
	cout<<"debug: *citer ="<<*citer<<endl;
#ifdef _ERROR_
	*citer = 0;
#endif
	
	DoubleList<int>::iterator iter = ls.begin();
	iter++;
	iter = ls.erase(iter);
	++iter;
	iter = ls.erase(iter);
	*iter *= 10;
	iter = ls.insert(iter,10);
	iter = ls.insert(iter,11);
	iter = ls.insert(iter,12);
	ls.pop_front();
	ls.pop_front();
	ls.pop_back();
	ls.pop_back();
	for(iter = ls.begin();iter != ls.end();iter++)
	{
		cout<<*iter<<" ";
	}
	cout<<"\n";

	for(iter = ls.rbegin();iter != ls.rend();--iter)    //倒序打印
	{
		cout<<*iter<<" ";
	}
	cout<<endl;
	
	ls.clear();
	cout<<"ls.size() ="<<ls.size()<<" ,ls.empty() ="<<ls.empty()<<endl;
	
	DoubleList<double> series = {1.25,2.25,3.25,4.25,5.25,6.25,7.25,8.25,9.25};
	Learn::foreach(series.begin(),series.end(),[](const double& n){cout<<n<<" ";});
	cout<<"\n";
	
	series.pop_front();
	series.push_front(1.50);
	series.pop_back();
	series.push_back(9.50);
	
	DoubleList<double>::iterator itr = series.begin();
	itr++;
	itr = series.erase(itr);
	++itr;
	itr = series.erase(itr);
	
	cout<<"series.size() ="<<series.size()<<" ,series.empty() ="<<series.empty()<<"\n"
		<<"series.front() ="<<series.front()<<" ,series.back() ="<<series.back()<<endl;

	for(itr = series.rbegin();itr != series.rend();itr--)
	{
		cout<<*itr<<" ";
	}
	cout<<endl;
	
	DoubleList<double> sequence = series;
	for(const double& n : sequence)
	{
		cout<<n<<" ";
	}
	cout<<endl;
	
	DoubleList<double> range;
	range = series;
	std::for_each(range.begin(),range.end(),[](const auto& n){cout<<n<<" ";});
	cout<<endl;
	
	DoubleList<double> seq(std::move(series));
	cout<<"series.size() ="<<series.size()<<" ,series.empty() ="<<series.empty()<<endl;
	foreach(seq.begin(),seq.end(),[](const double& n){cout<<n<<" ";});
	cout<<"\n";
	
	itr = series.begin();
	itr = series.insert(itr,13.3);
	itr = series.insert(itr,14.3);
	series.push_front(15.3);
	series.push_front(16.3);
	series.push_back(17.3);
	series.push_back(18.3);
	cout<<"series.size() ="<<series.size()<<" ,series.empty() ="<<series.empty()<<endl;
	std::for_each(series.begin(),series.end(),[](const double& n){cout<<n<<" ";});
	cout<<"\n";
	
	seq = std::move(series);
	cout<<"series.size() ="<<series.size()<<" ,series.empty() ="<<series.empty()<<endl;
	foreach(seq.begin(),seq.end(),[](const double& n){cout<<n<<" ";});
	cout<<"\n";

	for(itr = seq.rbegin();itr != seq.rend();itr--)
	{
		cout<<*itr<<" ";
	}
	cout<<endl;
	
	// ::getchar();     //阻塞test_DoubleList()函数返回，以调试DoubleList的析构函数。
}

void test_CircularList()
{
	struct
	{
		void operator ()(const int& n)
		{
			cout<<n<<" ";
		}
	}show;
	
	CircularList<int> ls;
	ls.push_back(1);
	ls.push_back(2);
	ls.push_back(2);
	ls.push_back(2);
	ls.push_front(3);
	ls.push_front(4);
	ls.push_front(4);
	std::for_each(ls.cbegin(),ls.cend(),show);         //正序打印
	cout<<"\n";

	CircularList<int>::const_iterator citer = --ls.cend();    //倒序打印
	for(;citer != --ls.cbegin();--citer)
	{
		cout<<*citer<<" ";
	}
	cout<<endl;
	
	cout<<"ls.size() ="<<ls.size()<<" ,ls.empty() ="<<ls.empty()<<"\n"
		<<"ls.front() ="<<ls.front()<<" ,ls.back() ="<<ls.back()<<endl;
	
	ls.front() *= 2;
	ls.back() *= 3;
	ls.remove(2);
	for(citer = ls.cbegin();citer != ls.cend();++citer)    //正序打印
	{
		cout<<*citer<<" ";
	}
	cout<<endl;
	
	for(citer = ls.rcbegin();citer != ls.rcend();--citer)  //倒序打印
	{
		cout<<*citer<<" ";
	}
	cout<<"\n";
	
	citer = ls.cbegin();
	citer++;
	++citer;
	cout<<"debug: *citer ="<<*citer<<endl;
#ifdef _ERROR_
	*citer = 0;
#endif
	
	CircularList<int>::iterator iter = ls.begin();
	iter++;
	iter = ls.erase(iter);
	++iter;
	iter = ls.erase(iter);
	*iter *= 10;
	iter = ls.insert(iter,10);
	iter = ls.insert(iter,11);
	iter = ls.insert(iter,12);	
	ls.pop_front();
	ls.pop_front();
	ls.pop_back();
	ls.pop_back();
	for(iter = ls.begin();iter != ls.end();iter++)
	{
		cout<<*iter<<" ";
	}
	cout<<endl;
	
	for(iter = ls.rbegin();iter != ls.rend();--iter)  //倒序打印
	{
		cout<<*iter<<" ";
	}
	cout<<"\n";

	ls.clear();
	cout<<"ls.size() ="<<ls.size()<<" ,ls.empty() ="<<ls.empty()<<endl;
	
	CircularList<double> series = {1.25,2.25,3.25,4.25,5.25,6.25,7.25,8.25,9.25};
	Learn::foreach(series.begin(),series.end(),[](const double& n){cout<<n<<" ";});
	cout<<"\n";
		
	series.pop_front();
	series.push_front(1.50);
	series.pop_back();
	series.push_back(9.50);
	
	CircularList<double>::iterator itr = series.begin();
	itr++;
	itr = series.erase(itr);
	++itr;
	itr = series.erase(itr);
	
	cout<<"series.size() ="<<series.size()<<" ,series.empty() ="<<series.empty()<<"\n"
		<<"series.front() ="<<series.front()<<" ,series.back() ="<<series.back()<<endl;

	for(itr = series.rbegin();itr != series.rend();itr--)
	{
		cout<<*itr<<" ";
	}
	cout<<endl;

	CircularList<double> sequence = series;
	for(const double& n : sequence)
	{
		cout<<n<<" ";
	}
	cout<<endl;
	
	CircularList<double> range;
	range = series;
	std::for_each(range.begin(),range.end(),[](const auto& n){cout<<n<<" ";});
	cout<<endl;
	
	CircularList<double> seq(std::move(series));
	cout<<"series.size() ="<<series.size()<<" ,series.empty() ="<<series.empty()<<endl;
	::foreach(seq.begin(),seq.end(),[](const double& n){cout<<n<<" ";});
	cout<<"\n";
	
	itr = series.begin();
	itr = series.insert(itr,12.3);
	itr = series.insert(itr,13.3);
	itr = series.insert(itr,14.3);
	series.push_front(15.3);
	series.push_front(16.3);
	series.push_back(17.3);
	series.push_back(18.3);
	cout<<"series.size() ="<<series.size()<<" ,series.empty() ="<<series.empty()<<endl;
	foreach(series.begin(),series.end(),[](const double& n){cout<<n<<" ";});
	cout<<"\n";
	
	seq = std::move(series);
	cout<<"series.size() ="<<series.size()<<" ,series.empty() ="<<series.empty()<<endl;
	std::for_each(seq.begin(),seq.end(),[](const double& n){cout<<n<<" ";});
	cout<<"\n";
	
	for(itr = seq.rbegin();itr != seq.rend();itr--)
	{
		cout<<*itr<<" ";
	}
	cout<<endl;
	
	// ::getchar();     //阻塞test_DoubleList()函数返回，以调试DoubleList的析构函数。	
}

void test_advance()
{
	//测试前向迭代器
	LinkList<char> ls = {'a','b','c','d','e'};
	LinkList<char>::iterator forward_iter = ls.begin();
	Learn::advance(forward_iter,3);
	cout<<"*forward_iter ="<<*forward_iter<<endl;	
	
	//测试双向迭代器
	DoubleList<int> seq = {30,31,32,33,34,35,36,37,38,39};
	DoubleList<int>::const_iterator bidirectional_citer = seq.cbegin();
	::advance(bidirectional_citer,5);
	cout<<"*bidirectional_citer ="<<*bidirectional_citer<<endl;
	
	advance(bidirectional_citer,-2);
	cout<<"*bidirectional_citer ="<<*bidirectional_citer<<endl;

#ifdef _ERROR_
	bidirectional_citer = seq.cend();      //DoubleList的cend()迭代器是一个指向nullptr的虚位置，不能执行"--"操作。
	advance(bidirectional_citer,-3);
	cout<<"*bidirectional_citer ="<<*bidirectional_citer<<endl;
#endif
	
	bidirectional_citer = seq.rcbegin();
	advance(bidirectional_citer,-3);
	cout<<"*bidirectional_citer ="<<*bidirectional_citer<<endl;

	CircularList<int> series = {40,41,42,43,44,45,46,47,48,49};
	CircularList<int>::iterator bidirectional_iter = series.begin();
	::advance(bidirectional_iter,5);
	cout<<"*bidirectional_iter ="<<*bidirectional_iter<<endl;
	
	advance(bidirectional_iter,-2);
	cout<<"*bidirectional_iter ="<<*bidirectional_iter<<endl;

	bidirectional_iter = series.end();
	advance(bidirectional_iter,-3);
	cout<<"*bidirectional_iter ="<<*bidirectional_iter<<endl;
	
	bidirectional_iter = series.rbegin();
	advance(bidirectional_iter,-3);
	cout<<"*bidirectional_iter ="<<*bidirectional_iter<<endl;
	
	//测试随机访问迭代器
	Array<double,5> vec = {3.14,2.718,0.618,1.414,9.78};
	Array<double,5>::iterator random_access_iter = vec.begin();
	Learn::advance(random_access_iter,4);
	cout<<"*random_access_iter ="<<*random_access_iter<<endl;
	
	::advance(random_access_iter,-3);
	cout<<"*random_access_iter ="<<*random_access_iter<<endl;
	
	//原始指针属于随机访问迭代器
	int arr[] = {40,41,42,43,44,45,46,47,48,49};
	int *ptr = arr;
	advance(ptr,7);
	cout<<"arr[7] ="<<*ptr<<endl;
	
	::advance(ptr,-4);
	cout<<"arr[3] ="<<*ptr<<endl;
}

void test_distance()
{
	//原始指针属于随机访问迭代器
	int arr[] = {0,1,2,3,4,5,6,7,8,9};
	int *p = arr;
	int num = Learn::distance(p,p + sizeof(arr)/sizeof(int));
	cout<<"raw pointer: num ="<<num<<endl;

	//测试前向迭代器
	LinkList<char> ls = {'a','b','c','d','e'};
	LinkList<char>::iterator forward_iter = ls.begin();
	
	for(int i=0;i<2;i++,forward_iter++);
	num = ::distance(forward_iter,ls.end());
	cout<<"*forward_iter ="<<*forward_iter<<" ,num ="<<num<<endl;

	//测试双向迭代器
	DoubleList<int> seq = {30,31,32,33,34,35,36,37,38,39};
	DoubleList<int>::const_iterator bidirectional_citer = seq.cbegin();
	
	for(int i=0;i<3;i++,bidirectional_citer++);
	num = distance(seq.cbegin(),bidirectional_citer);
	cout<<"*bidirectional_citer ="<<*bidirectional_citer<<" ,num ="<<num<<endl;
	
	//测试随机访问迭代器
	Array<double,5> vec = {3.14,2.718,0.618,1.414,9.78};
	Array<double,5>::const_iterator random_access_citer = vec.cbegin();

	num = Learn::distance(random_access_citer,random_access_citer + 3);
	cout<<"*random_access_citer ="<<*random_access_citer<<" ,num ="<<num<<endl;
}