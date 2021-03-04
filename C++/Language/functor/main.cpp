#include <cstdlib>   //rend(),srend()
#include <ctime>      //time()
#include <iostream>
#include <array>
#include <list>
#include <vector>
#include <algorithm>    //for_each(),find(),find_if(),replace(),replace_if(),sort(),is_sorted()
#include <functional>   //plus(),minus(),less(),greater(),equal_to(),less_equal(),greater_equal()
#include <numeric>      //accumulate()
#include "functor.h"

#define _CHANGE_WAY_
// #undef _CHANGE_WAY_

#define ARRAY_SIZE 10

using namespace std;

static void test_array();
static void test_list();
static void test_vector();

int main(void)
{
	srand((unsigned int)time(NULL));   //根据当前时间，设置随机数种子
	
	test_array();
	test_list();
	test_vector();
	
	return 0;
}

static void test_array()
{
	data_t arr[ARRAY_SIZE] = {7,1,9,0,5,4,3,6,2,8};
	display(arr,ARRAY_SIZE);
	
	if(!is_sorted(arr,arr + ARRAY_SIZE))
	{
#ifndef _CHANGE_WAY_
		sort(arr,arr+ARRAY_SIZE);
		display(arr,sizeof(arr)/sizeof(arr[0]));
#else
		sort(arr,arr + ARRAY_SIZE,descend);
		for_each(arr,arr + sizeof(arr)/sizeof(arr[0]),print);
		cout<<endl;
#endif
	}
	cout<<endl;
	
	array<data_t,ARRAY_SIZE> myarray = {5,7,9,1,8,4,2,3,6};   //std::array没有data()方法，std::vector才有data()方法
	for_each(myarray.begin(),myarray.end(),Show<data_t>());
	cout<<endl;
	
	if(!is_sorted(myarray.begin(),myarray.end()))
	{
#ifndef _CHANGE_WAY_
		stable_sort(myarray.begin(),myarray.end(),greater<data_t>());
#else
		stable_sort(myarray.begin(),myarray.end(),less<data_t>());
#endif
	}
	for_each(myarray.begin(),myarray.end(),[](data_t x){cout<<x<<" ";});
	cout<<endl<<endl;
}

void test_list()
{
	plus<int> plusobj;
	cout<<"3 + 4 ="<<plusobj(3,4)<<endl;
	
	minus<data_t> minusobj;
	cout<<"9 - 5 ="<<minusobj(9,5)<<endl;        //构建一个临时的minus对象来做减法
	cout<<"8 / 4 ="<<divides<int>()(8,4)<<endl;
	cout<<"12 == 12"<<equal_to<int>()(12,12)<<endl;
	
	bool ret = Compare<int>()(7,6);
	cout<<"7 > 6 ="<<ret<<endl<<endl;
	
	list<data_t> mylist;
	for(int i=0;i<ARRAY_SIZE;++i)
	{
		mylist.push_back(rand()%10);
	}
	for_each(mylist.begin(),mylist.end(),[](data_t& x){cout<<x<<" ";});
	cout<<endl;
	
	data_t mult = accumulate(mylist.begin(),mylist.end(),1,multiplies<data_t>());
	cout<<"mult ="<<mult<<endl;
	
	//std::list和std::forward_list自带了sort()方法，其他容器需要排序时，都只能使用std::sort()排序算法实现
	mylist.sort(less<data_t>());
	for_each(mylist.begin(),mylist.end(),print);
	cout<<endl;
	
	for_each(mylist.begin(),mylist.end(),[](data_t& x){x *= 2;});
	for_each(mylist.begin(),mylist.end(),Show<data_t>());
	cout<<endl;
	
	data_t sum = accumulate(mylist.begin(),mylist.end(),0);
	cout<<"sum ="<<sum<<endl<<endl;
}

void test_vector()
{
	vector<data_t> myvector;
	for(int i=0;i<ARRAY_SIZE;++i)
	{
		myvector.push_back(rand()%10);
	}
	display(myvector.data(),myvector.size());
	
	vector<data_t>::iterator iter = find(myvector.begin(),myvector.end(),5);   //find()算法不支持cbegin()和cend()迭代器
	if(iter != myvector.end())
	{
		cout<<"find 5 at index: "<<iter - myvector.begin()<<endl;
	
		replace(myvector.begin(),myvector.end(),5,15);
		for_each(myvector.data(),myvector.data() + myvector.size(),Show<data_t>());
		cout<<endl;
	}
	else
	{
		cout<<"don't find 5 in myvector"<<endl;
	}
	
	iter = find_if(myvector.begin(),myvector.end(),
				[](const data_t& x)->bool{
					return x % 7 == 1;
				}
			);
	if(iter != myvector.end())
	{
		cout<<*iter<<" % 7 == 1, index ="<<iter - myvector.begin()<<endl;
	}
	else
	{
		cout<<"can't find suitable number"<<endl;
	}
	
	replace_if(myvector.begin(),myvector.end(),[](const data_t& x){return x % 5 == 3;},18);
	for_each(myvector.begin(),myvector.end(),print);
}