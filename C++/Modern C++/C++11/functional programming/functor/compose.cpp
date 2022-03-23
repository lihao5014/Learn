/*在函数式语言中函数作为一等公民，可以在函数内或函数外等任何地方定义，可以作为函数的参数和返回值，
 *可以对函数进行组合。命令式编程语言也可以通过类似函数指针的方式来实现高阶函数，函数式的优点主要
 *是不可变性带来的。没有可变的状态，函数就是引用透明的和没有副作用。
 */

/*1.函数式编程的概念：
 *（1）函数式编程：把函数当作普通的值类型一样使用，包括可以用函数进行赋值、传参、从函数中返回等操作。
 *（2）行为参数化：将一个函数行为当作参数传递给另一个函数的方式。
 *（3）高阶函数：如果一个函数接受至少一个函数作为参数或返回的结果是一个函数，该函数就可以称为高阶函数。
 *（4）科里化：将具备多个参数的函数转化为使用一个参数的函数，并且这个函数的返回值也是一个函数，
 *     它会作为新函数的一个参数。后者的返回值和初始函数的返回值相同。
 */

/*2.函数式编程是一种编程范式，它具有以下特征：
 *（1）函数是一等公民，可以像数据一样传来传去。
 *（2）高阶函数。
 *（3）递归。
 *（4）pipeline。
 *（5）惰性求值。
 *（6）柯里化。
 *（7）偏应用函数。
 */

/*3.C++中函数式编程的实现：
 *C++98/03中的模板元编程和函数对象，C++11中的Lambda表达式、std::function和std::bind让C++的函数式编程
 *变得容易。我们可以利用C++11/14里的新特性来实现高阶函数、链式调用、惰性求值和柯理化等函数式编程特性。
 */

/*4.高阶函数：
 *（1）高阶函数就是参数为函数或返回值为函数的函数，经典的高阶函数就是map、filter、fold和compose函数。
 *（2）有的高阶函数是参数为函数，有的高阶函数是参数和返回值都是函数。高阶函数不仅语义上更加抽象泛化，
 *     还能实现“函数是一等公民”，将函数像数据一样传来传去或组合，非常灵活。其中compose还可以实现惰性求值，
 *     compose的返回结果是一个函数，我们可以保存起来，在后面需要的时候调用。
 */

/*5.Scala语言中常见的高阶函数：
 *（1）map映射：对列表中的每个元素应用一个函数，返回应用后的元素所组成的列表。
 *     例如：numbers.map((i: Int) => i * 2)，将整数序列中的所有元素都变为原来的2倍。
 *（2）filter过滤：移除任何对传入函数计算结果为false的元素。
 *     例如：numbers.filter((i: Int) => i % 2 == 0)，过滤掉整数序列中所有偶数元素。
 *（3）fold折叠：将一个初始值和一个二元函数的结果累加起来。
 *     例如：numbers.fold(0){(z, i) => z + i}，将整数序列中的所有元素求和。
 *（4）compose组合：将f(x)和g(x)函数组合形成一个新函数f(g(x))。
 */

/*6.compose1()与compose2():
 *（1）GCC的STL中有一个不属于C++标准的compose1()函数，可以接受两个定义了()操作符的对象作为函数参数，
 *     并返回一个能进行f(g(x))运算的对象。
 *（2）compose1()和compose2()均是用于参数合成。但这两个配接器并未纳入STL标准，是SGI STL的私有产品。
 *（3）compose1()实际实现是函数对象unary_compose。compose1()函数接受两个参数，代表两个操作，
 *     操作op1的返回值类型作为合并后的一元函数对象unary_compose的返回值类型，操作op2的参数类型
 *     作为合并后的一元函数对象unary_compose中重载函数()的参数类型。
 *（4）compose2()实际实现是函数对象binary_compose。compose2()函数接受三个参数，代表三个操作，
 *    操作op1的返回值类型作为合并后的一元函数对象binary_compose的返回值类型，操作op2的
 *    参数类型作为合并后的一元函数对象binary_compose中重载函数()的参数类型。
 */

#include <iostream>
#include <list>
#include <iterator>     //distance()
#include <functional>   //binary_function与unary_function,bind1st(),bind2nd(),not1(),not2()
#include <algorithm>    //for_each(),transform()
#include <numeric>      //accumulate()

#define _CHANGE_WAY_
#undef _CHANGE_WAY_

using namespace std;

template <typename T>
void print(T x)
{
	cout<<x<<" ";
}

template <typename T>
class Show
{
public:
	void operator ()(T x)
	{
		cout<<x<<" ";
	}
};

class IsOdd:public unary_function<int,bool>
{
public:
	bool operator ()(int num)const    //一定要加const，否则调用函数适配器not1(IsOdd())时，编译会报错。
	{
		return num%2 == 0;
	}
};

template <class Operation1,class Operation2>
class unary_compose:public unary_function<typename Operation2::argument_type,typename Operation1::result_type>
{
public:
	unary_compose(const Operation1& op1,const Operation2& op2)
		:m_op1(op1),m_op2(op2)
	{
		
	}
	
	typename Operation1::result_type operator ()(const typename Operation2::argument_type& x)const
	{
		return m_op1(m_op2(x));
	}

protected:
	Operation1 m_op1;
	Operation2 m_op2;
};

template <class Operation1,class Operation2>
inline unary_compose<Operation1,Operation2> compose1(const Operation1& op1,const Operation2& op2)
{
	return unary_compose<Operation1,Operation2>(op1,op2);
}

template <class Operation1,class Operation2,class Operation3>
class binary_compose:public unary_function<typename Operation2::argument_type,typename Operation1::result_type>
{
public:
	binary_compose(const Operation1& op1,const Operation2& op2,const Operation3& op3)
		:m_op1(op1),m_op2(op2),m_op3(op3)
	{
		
	}
	
	typename Operation1::result_type operator ()(const typename Operation2::argument_type& x)const
	{
		return m_op1(m_op2(x),m_op3(x));
	}

protected:
	Operation1 m_op1;
	Operation2 m_op2;
	Operation3 m_op3;
};

template <class Operation1,class Operation2,class Operation3>
inline binary_compose<Operation1,Operation2,Operation3> compose2(const Operation1& op1,const Operation2& op2,const Operation3& op3)
{
	return binary_compose<Operation1,Operation2,Operation3>(op1,op2,op3);
}

class Foo:public unary_function<double,double>
{
public:
	result_type operator ()(const argument_type& x)const  //必须带const，原因是unary_compose的operator()带const
	{
		return x * 2 + 1;
	}
};

struct Bar:public unary_function<double,double>
{
	result_type operator ()(const argument_type& x)const  //必须带const，原因是unary_compose的operator()带const
	{
		return x * x;
	}
};

struct Qux:public binary_function<double,double,double>
{
	result_type operator ()(const first_argument_type& x,const second_argument_type& y)const
	{
		return x + y;
	}
};

int main(void)
{
	//Scala语言中的map()映射函数，对应C++中的std::for_each()或std::transform()。
	list<int> numbers = {4,5,8,2,1,6,9,7,3,0};
	for_each(numbers.begin(),numbers.end(),print<int>);
	cout<<endl;
	
	list<int> seq(numbers.size());
	transform(numbers.begin(),numbers.end(),seq.begin(),[](int n){return n + 1;});
	for_each(seq.begin(),seq.end(),Show<int>());
	cout<<endl;
	
	for_each(seq.begin(),seq.end(),[](int& n){n *= 2;});
	for_each(seq.begin(),seq.end(),[](int n){cout<<n<<" ";});
	cout<<endl<<endl;
	
	//Scala语言中的filter()过滤函数，对应C++中的std::remove_if或std::copy_if()。
	list<int> arr(numbers.size());
#ifndef _CHANGE_WAY_
	list<int>::iterator iter = copy_if(numbers.begin(),numbers.end(),arr.begin(),IsOdd());
#else
	list<int>::iterator iter = copy_if(numbers.begin(),numbers.end(),arr.begin(),not1(IsOdd()));
#endif
	arr.resize(distance(arr.begin(),iter));
	for_each(arr.begin(),arr.end(),print<int>);
	cout<<endl;

#ifndef _CHANGE_WAY_
	iter = remove_if(arr.begin(),arr.end(),bind2nd(less<int>(),5));
#else
	iter = remove_if(arr.begin(),arr.end(),[](int n){return n < 5;});
#endif
	arr.resize(distance(arr.begin(),iter));
	for_each(arr.begin(),arr.end(),Show<int>());
	cout<<endl<<endl;
	
	//Scala语言中的fold()折叠函数，对应C++中的std::accumulate()。
#ifndef _CHANGE_WAY_
	int sum = accumulate(numbers.begin(),numbers.end(),0);
#else
	int sum = accumulate(numbers.begin(),numbers.end(),100);
#endif
	cout<<"sum ="<<sum<<endl<<endl;
	
	//Scala语言中的compose()组合函数，对应C++中的compose1()与compose2()。
	Foo f;
	Bar g;
	
	double ret = compose1(f,g)(5);
	cout<<"Foo(Bar(x)) = (x * x)*2 + 1 : (5 * 5) * 2 + 1 ="<<ret<<endl;

#ifndef _CHANGE_WAY_
	std::function<double(double)> h = compose1(g,f);
#else
	auto h = compose1(Bar(),Foo());
#endif
	cout<<"Bar(Foo(x)) = (x*2 + 1)^2 : (5 * 2 + 1)^2 ="<<h(5)<<endl;
	
	Qux z;
	ret = compose2(z,f,g)(3.14);
	cout<<"x*2 + 1 + x^2 : 3.14*2 + 1 + 3.14^2 ="<<ret<<endl;

#ifndef _CHANGE_WAY_
	std::function<double(double)> t = compose2(z,g,f);
#else
	auto t = compose2(Qux(),Bar(),Foo());
#endif
	cout<<"Qux(Bar(x),Foo(x)) = x^2 + x*2 + 1 : 2.618^2 + 2.618*2 + 1 ="<<t(2.618)<<endl;

	return 0;
}
