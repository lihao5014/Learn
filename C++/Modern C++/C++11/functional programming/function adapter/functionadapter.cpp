/*1.unary_function/binary_function介绍：
 *（1）unary_function可以作为一个一元函数对象的基类，它只定义了参数和返回值的类型，
 *     本身并不重载（）操作符，这个任务应该交由派生类去完成。
 *（2）binary_function可以作为一个二元函数对象的基类，它只定义了参数和返回值的类型，
 *    本身并不重载（）操作符，这个任务应该交由派生类去完成。
 *（3）在定义一个普通的仿函数时，不会使用unary_function或binary_function，但是如果
 *     需要函数适配器，便需要使用它实现。
 *（4）标准库中的一些函数适配器，要求它们适配的函数对象已定义某些类型。比如std::not1
 *     要求要适配的函数对象拥有名为argument_type的类型。从unary_function导出函数对象
 *     是令它们与那些适配器兼容的简易方式。
 *（5）在C++标准库中提供了函数适配器bind2nd，把第二个参数绑定让一个二元函数变成一元的。 
 *     但一般的仿函数不能直接使用在bind2nd上，因为与bind2nd的concept不符合，需要继承自
 *     binary_function的仿函数才行。
 *（6）在C++98中unary_function和binary_function使用的很频繁，但在C++11中两者都被弃用了。
 */

/*1.unary_function一元仿函数基类源码：
 *	template <class Arg, class Result>
 *  struct unary_function
 *  {
 *  	typedef Arg argument_type;    //argument_type是第一个模板参数Arg的别名，用于()运算符重载的参数类型。
 *      typedef Result result_type;   //result_type是第二个模板参数Result的别名，用于()操作符重载的返回值类型。
 *  };
 */

/*2.binary_function二元函数对象基类源码：
 *	template <class Arg1, class Arg2, class Result>
 *	struct binary_function 
 *  {
 *  	typedef Arg1 first_argument_type;    //first_argument_type是第一个模板参数Arg1的别名，用于()运算符重载的第一个参数类型。
 *      typedef Arg2 second_argument_type;   //second_argument_type是第二个模板参数Arg2的别名，用于()运算符重载的第二个参数类型。
 *      typedef Result result_type;          //return_type是第三个模板参数Result的别名，用于()操作符重载的返回值类型。
 *  };
 **/

/*4.std::not1和std::not2：
 *（1）not1是构造一个与谓词结果相反的一元函数对象。
 *（2）not2是构造一个与谓词结果相反的二元函数对象。
 */

/*5.std::bind1st和std::bind2nd：
 *（1）std::bind1st和std::bind2nd函数用于将一个二元算子转换成一元算子。bind的意思是“绑定”，
 *     1st代表first，2nd代表second。
 *（2）bind1st和bind2nd的作用是将二元函数转换为一元函数。当在某些情况下我们需要固定二元函数
 *     的第一个参数或第二个参数，就使其变成了一元函数。
 *（3）bind1st相当于作这样的操作：x op value。
 *（4）bind2nd相当于作这样的操作：value op x。
 */

#include <iostream>
#include <functional>   //std::not1,std::not2,bind1st,bind2nd,unary_function,binary_function
#include <algorithm>    //std::less,std::greater,for_each(),all_of(),any_of()

using namespace std;

typedef double data_t;

template <typename T>
void print(const T& num)
{
	cout<<num<<" ";
}

class Display
{
public:
	void operator ()(double num)
	{
		cout<<num<<" ";
	}
};

void showArray(data_t arr[],int len)
{
	for(int i=0;i<len;++i)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}

//std::not1要求适配的函数对象拥有名为argument_type的类型，且()运算符重载必须为const类型。
template <typename T>
struct IsNegative:public unary_function<T,bool>
{
	typename unary_function<T,bool>::result_type operator ()(const typename unary_function<T,bool>::argument_type& num)const
	{
		return num < 0 ? true : false;
	}
};

struct IsEven:public unary_function<int,bool>
{
	result_type operator ()(const argument_type& num)const
	{
		return num % 2 == 1;
	}
};

struct Compare:public binary_function<double,double,bool>
{
	result_type operator ()(const first_argument_type& x,const second_argument_type& y)const
	{
		return x < y;
	}
};

int main(void)
{
	int arr[] = {2,4,5,8,9};
	int len = sizeof(arr)/sizeof(arr[0]);
	for_each(arr,arr + len,print<int>);
	cout<<endl;
	
	if(all_of(arr,arr + len,IsNegative<int>()))
	{
		cout<<"all the elements are negative numbers"<<endl;
	}
	
	if(all_of(arr,arr + len,std::not1(IsNegative<int>())))
	{
		cout<<"all the elements are not negative numbers"<<endl;
	}

	if(any_of(arr,arr + len,IsEven()))
	{
		cout<<"There are even elements in the range.\n";
	}
	
	if(any_of(arr,arr + len,std::not1(IsEven())))
	{
		cout<<"There are odd elements in the range.\n";
	}
	
	int ret = count_if(arr,arr + len,IsEven());
	cout<<"There are " << ret << " elements with even values.\n";
	
	ret = count_if(arr,arr + len,not1(IsEven()));
	cout<<"There are " << ret << " elements with odd values.\n"<<endl;

	double seq[] = {3.14,0.618,2.718,1.414,1.732};
	int size = sizeof(seq)/sizeof(double);
	for_each(seq,seq + size,Display());
	cout<<endl;
	
	sort(seq,seq + size,Compare());
	for_each(seq,seq + size,[](double num){cout<<num<<" ";});
	cout<<endl;
	
	sort(seq,seq + size,not2(Compare()));
	showArray(seq,size);
	cout<<endl;
	
	if(all_of(seq,seq + size,bind2nd(less<double>(),5.0)))
	{
		cout<<"all the elements are less than 5.0"<<endl;
	}
	
	ret = count_if(seq,seq + size,bind2nd(greater<double>(),2.0));
	cout<<"There are " << ret << " elements with greater than 2.0.\n";
	
	for_each(seq,seq + size,
		[](double num)
		{
			if(bind1st(Compare(),2.0)(num))
			{
				cout<<num<<" ";
			}
		}
	);
	cout<<endl;
	
	replace_if(seq,seq + size,bind1st(Compare(),2.0),6.0);
	for_each(seq,seq + size,Display());
	
	return 0;
}