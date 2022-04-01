#include <iostream>
#include <list>
#include <initializer_list>
#include <functional>       //function,bind(),bind1st(),bind2nd(),not1(),not2()
#include <algorithm>        //for_each(),transform(),copy_if(),accumulate()
#include <numeric>          //accumulate()
#include <iterator>         //std::back_inserter

using namespace std;

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

template <typename T>
void ListWraper<T>::display()const
{
	for_each(m_ls.begin(),m_ls.end(),[](const T& n){cout<<n<<" ";});    //C++14标准才支持lambda模板
	cout<<endl;
}

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

