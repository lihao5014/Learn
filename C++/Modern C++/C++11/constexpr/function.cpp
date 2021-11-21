/*常量表达式是指值不会改变并且在编译过程就能得到计算结构的表达式。一个对象或表达式是不是常量表达式，
 *由它的数据类型和初始值共同决定。
 */

/*C++11规定允许将变量声明为constexpr类型以便由编译器来验证变量值是否是一个常量表达式。
 *声明为constexpr的变量一定是一个常量，而且必须用常量表达式初始化。
 */

/*尽管不能使用普通函数作为constexpr变量的初始值，但是新标准允许定义一种特殊的constexpr函数。
 *这种函数应该足够简单以使其在编译时就可以计算出结果，这样就可以使用constexpr函数去初始化constexpr变量了。
 */

/*算术类型、引用和指针都属于字面值类型。尽管指针和引用都能定义成constexpr，但它们的初始值却受到严格限制。
 *一个constexpr指针的初始值必须是nullptr或0，或者是存储于某个固定地址中的对象。
 */
 
//在constexpr声明中如果定义了一个指针，限定符constexpr仅对指针有效，与指针所指的对象无关。

/*1.constexpr修饰普通函数/成员函数使之成为常量表达式函数的条件：
 *（1）函数必须要有返回值，并且return返回的表达式必须是常量表达式。
 *（2）函数在使用之前，必须有对应的定义语句。
 *（3）整个函数的函数体中，不能出现非常量表达式之外的语句，using、typedef、return以及static_assert()断言除外。
 */

/*2.constexpr修饰模板函数：
 *constexpr可以修饰函数模板，但由于模板中类型的不确定性，因此函数模板实例化后的函数是否符合常量表达式函数的要求，
 *也是不确定的。如果constexpr修饰的模板函数实例化结果不满足常量表达式函数的要求，则constexpr会被自动忽略，
 *即该函数就等同于一个普通函数。
 */

/*3.constexpr修饰构造函数：
 *如果想用直接得到一个常量对象，也可以使用constexpr修饰一个构造函数，这样就可以得到一个常量构造函数了。
 *常量构造函数有一个要求：构造函数的函数体必须为空，并且必须采用初始化列表的方式为各个成员赋值。
 */

/*C++11提供了constexpr，让用户显式的声明函数或对象构造函数在编译期会成为常量表达式，
 *constexpr关键字明确的告诉编译器应该去验证其修饰的函数在编译期就应该是一个常量表达式。
 */

#include <iostream>

#define _ERROR_
#undef _ERROR_

using namespace std;

#ifdef _ERROR_           //constexpr并不能修饰任意函数的返回值，使之成为常量表达式函数。
constexpr void fun()     //函数没有返回值，不满足常量表达式函数要求
{
	const int num = 1;
}

constexpr int fun1()       //函数中存在非常量表达式语句，不满足常量表达式函数要求。
{
	cout<<"foo()"<<endl;
	return 5 + 3;
}

constexpr int fun2()     //函数返回值是一个变量，而不是常量表达式，不满足常量表达式函数要求
{
	int num = 7;         //整个函数的函数体中，不能出现非常量表达式之外的语句。
	return num;
}

/*C++11的标准下不能够通过编译，但在C++14标准中可以编译通过。即使用g++编译时，添加-std=c++11选项编译会报错，
 *添加-std=c++14选项编译会通过。
 */
constexpr int fun3()      //在C++11中的constexpr修饰的常量表达式函数，只能包含一个return的表达式。
{
	const int num = 9;    //从C++14开始，constexpr函数可以在内部使用局部变量、循环和分支等简单语句。
	return num;
}

constexpr int foo();     //constexpr修饰的函数在使用之前，必须有对应的定义语句

/*因为bar()是一个常量表达式函数，在函数体内部是不允许出现非常量表达式以外的操作，
 *所以函数体内部的for循环是一个非法操作。
 */
constexpr int bar()
{
	constexpr int a = 13;
	constexpr int b = 15;
	for(int i=0;i<10;++i)
	{
		cout<<"i ="<<i<<endl;
	}
	return a*a + b*b;
}
#else
constexpr int fun()     //在C++11和C++14标准中编译都可以通过。
{
	return 5 + 3;
}

constexpr int foo()     //常量表达式函数最好在声明的时候就给出函数的定义，而不要使用先声明后定义的方法。
{
	constexpr int num = 11;    //C++11的标准下不能够通过编译，但在C++14标准中可以编译通过。
	return num;
}

/*执行该初始化任务时，编译器把对constexpr函数的调用替换成其结果值。为了能在编译过程中随时展开，
 *constexpr函数被隐式地指定为内联函数。
 */
constexpr int bar()
{
	using mytype = int;
	constexpr mytype a = 13;
	constexpr mytype b = 15;
	constexpr mytype c = (a + b)*(a + b) - (a - b)*(a - b);
	
	return c / 4;
}
#endif

class Sample
{
public:
	constexpr int func()    //constexpr关键字不仅可以修饰普通函数，也可以修饰类的成员函数。
	{
		constexpr int var = 5;
		return 2 * var;
	}
};

struct Person
{
	const char* name;
	int age;
};

//函数模板baz()由于其返回值类型未定，因此在实例化之前无法判断其是否符合常量表达式函数的要求。
template <typename T>
constexpr T baz(T t)
{
	return t;
}

int main(int argc,char** argv)
{
	cout<<"C++ version: "<<__cplusplus<<endl;     //打印编译器支持的C++标准
	
	//一个变量或表达式是不是常量表达式由它的数据类型和初始值共同决定。
	const int a = 2;        //a是常量表达式
    const int b = a + 1;    //b是常量表达式
    int n = 6;              //n不是常量表达式
    const int m = n + 2;    //m不是常量表达式
	
	//constexpr修饰的变量一定是一个常量，而且必须用常量表达式初始化。
	constexpr int j = 4 * 8;

	fun();
	
	constexpr int num = foo();   //还没有定义foo()就直接调用了，应该将foo()函数的定义放到main()函数的上边。
	cout<<"num ="<<num<<endl;
	
	cout<<"bar() ="<<bar()<<endl;
	
	//由于编译期无法打印常量表达式函数的返回结果，所以使用定义数组的方式判断一个constexpr变量是不是常量。  
	Sample sample;
	constexpr int size = sample.func(); 
	int arr[size] = {0,1,2,3,4,5,6,7,8,9}; 
	for(int i=0;i<size;++i)
	{
		cout<<i<<" ";
	}
	cout<<endl;
	
	constexpr int ret = baz(20);   //由于模板函数bar()的参数是常量，符合常量表达式函数的要求，此时constexpr是有效的。
	cout<<"ret ="<<ret<<endl;
	
	struct Person person{"amy",22};
	struct Person person1 = baz(person);   //由于模板函数bar()的参数是变量，所以实例化后的函数不是常量表达式函数，此时constexpr是无效的。
	cout<<"name ="<<person1.name<<" ,age ="<<person1.age<<endl;
	
	constexpr Person person2{"lisa",23};
	constexpr Person person3 = baz(person2);  //由于模板函数bar()的参数是常量，符合常量表达式函数的要求，此时constexpr是有效的。
	cout<<"name ="<<person3.name<<" ,age ="<<person3.age<<endl;
	
	return 0;
}

#ifdef _ERROR_
constexpr int foo()
{
	constexpr int num = 11;
	return num;
}
#endif