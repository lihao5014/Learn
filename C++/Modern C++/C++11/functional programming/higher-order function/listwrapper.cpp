/*1.函数副作用：
 *函数副作用是指当调用函数时，除了返回函数值之外，还对主调用函数产生附加的影响。
 *副作用的函数不仅仅只是返回了一个值，而且还做了其他的事情。一般有状态函数会产生
 *函数副作用，纯函数或无状态函数不会产生函数副作用。
 */
 
/*2.常见的函数副作用：
 *（1）修改了一个变量。
 *（2）直接修改数据结构。
 *（3）设置一个对象的成员。
 *（4）抛出一个异常或以一个错误终止。
 *（5）打印到终端或读取用户输入。
 *（6）读取或写入一个文件。
 *（7）在屏幕上画图。
 */

/*3.函子：
 *（1）函子是一个特殊的容器，通过一个普通对象来实现，该对象具有map()方法，map()方法可以运行一个
 *     函数对值进行处理，将容器中存储的数据变形。
 *（2）函子就是一个实现了map契约的对象，使用函子可以实现链式编程。函数式编程的运算不直接操作值，
 *     而是由函子完成。
 *（5）可以把函子想象成一个盒子，这个盒子里封装了一个值。想要处理盒子中的值，我们需要给盒子的map方法
 *     传递一个处理值的函数，由这个函数来对值进行处理。最终map方法返回一个包含新值的盒子（函子）。
 */

#include <iostream>
#include <list>
#include <initializer_list>
#include <functional>       //function,bind(),bind1st(),bind2nd(),not1(),not2()
#include <algorithm>        //for_each(),transform(),copy_if(),accumulate()
#include <numeric>          //accumulate()
#include <iterator>         //std::back_inserter

using namespace std;

/*ListWraper就属于一个函子，可以很方便的实现函数式编程中的链式表达式，
 *其中的map(),filter()和fold()方法就属于高阶函数。
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

/*（1）for each(in)语法是msvc编译器扩展的C++语法，而非C++标准，gcc编译器不支持，
 *     所以不推荐使用。标准C++中支持的是范围for(:)循环。
 *（2）cl编译器使用/Ze选项启用C++语言扩展(默认)，/Za禁用语言扩展。
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
	for_each(m_ls.begin(),m_ls.end(),[](const T& n){cout<<n<<" ";});    //C++14标准才支持lambda模板
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

