/*1.traits特性萃取技术：
 *（1）在STL中容器与算法是分开的，彼此独立设计，容器与算法之间通过迭代器联系在一起。
 *     算法正是通过traits技术，从迭代器类中获取出容器元素的类型的。
 *（2）在C++中traits习惯上总是被实现为struct，它们被称为traits class。traits class的
 *     作用主要是用来为使用者提供类型信息。
 *（3）traits技术展现的是一种思想，将相同的操作复用，不同的操作进一步抽象成接口复用。
 *     traits技术是一种编译期实现技术。
 */

/*2.traits class的实现步骤：
 *（1）确认若干我们希望将来可取得的类型相关信息，如迭代器所指元素的类型。
 *（2）为该信息选择一个名称，如迭代器所指元素的类型起名为value_type。
 *（3）提供一个template和一组特化版本，内容包含我们希望支持的类型相关信息。
 */

#include <iostream>
#include <vector>

using namespace std;

//利用迭代器可以实现很多通用算法，迭代器在容器与算法之间搭建了一座桥梁。
template <typename Iterator>
typename Iterator::value_type sum(Iterator begin,Iterator end)   //迭代器所指对象的类型，称为该迭代器的value_type。
{
	typename Iterator::value_type result(0);
	for(Iterator iter=begin;iter != end;++iter)
	{
		result += *iter;
	}
	
	return result;
}

/*如果想让sum()函数对指针参数也能工作，毕竟迭代器就是模拟指针，但指针没有嵌套类型value_type，
 *可以定义sum()对指针类型的特例，但更好的办法是在函数参数和value_type之间多加一层特性traits。
 */
template <typename T>
T sum(T* begin,T* end)
{
	T result = 0;
	for(T* p=begin;p != end;++p)
	{
		result += *p;
	}
	
	return result;
}

/*其实C++标准定义了与Traits类似的std::iterator_trait（另一个经典例子是std::numeric_limits）。
 *特性对类型的信息（如value_type、reference）进行包装，使得上层代码可以以统一的接口访问这些信息。
 *C++模板元编程会涉及大量的类型计算，很多时候要提取类型的信息（typedef、常量值等），如果这些类型
 *信息的访问方式不一致（如上面的迭代器和指针），我们将不得不定义特例，这会导致大量重复代码的出现，
 *从而导致代码膨胀，而通过加一层特性可以很好的解决这一问题。另外特性不仅可以对类型的信息进行包装，
 *还可以提供更多信息，当然因为加了一层也带来复杂性。特性是一种提供元信息的手段。
 */
template <typename Iter>
struct Traits
{
	using value_type = typename Iter::value_type;    //内嵌类型声明
};

template <typename T>
struct Traits<T*>         //局部特例化、偏特化
{
	typedef T value_type;
};

/*total()函数在传入Iter类型参数的时候，会首先把Iter类型传到萃取器中，然后萃取器就
 *匹配最适合的value_type。萃取器会先匹配最特别的版本，当你传进一个原生指针的时候，
 *首先匹配的是带<T*>的偏特化版本，这样value_type就是T类型，而不是没有事先声明的
 *Iter::value_type。这样就可以使用typename Traits<Iter>::value_type来知道返回类型。
 */
template <typename Iter>
typename Traits<Iter>::value_type total(Iter begin,Iter end)
{
	typename Traits<Iter>::value_type result(0);
	for(Iter i=begin;i != end;++i)
	{
		result += *i;
	}
	
	return result;
}

int main(void)
{
	int arr[] = {0,1,2,3,4,5,6,7,8,9};
	int ret = sum(arr,arr + sizeof(arr)/sizeof(arr[0]));
	cout<<"sum 0~9: "<<ret<<endl;
	
	vector<double> vec = {0.5,1.5,2.5,3.5,4.5,5.5,6.5,7.5,8.5,9.5};
	double result = sum(vec.begin(),vec.end());
	cout<<"sum 0.5~9.5: "<<result<<endl;
	
	ret = total(arr,arr + sizeof(arr)/sizeof(arr[0]));
	cout<<"total 0~9: "<<ret<<endl;
	
	result = total(vec.begin(),vec.end());
	cout<<"total 0.5~9.5: "<<result<<endl;
	
	return 0;
}