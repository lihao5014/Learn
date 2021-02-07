#include <iostream>
#include <utility>         //std::move
#include "sample.h"

#define _EEROR_
#undef _EEROR_

#define _CHANGE_WAY_
#define _CHANGE_WAY_

static Sample g_sample("global sample",1001);

using namespace std;

/*1.fun函数的调用返回过程：
 *（1）先调用Sample类的构造函数，创建一个Sample类型的临时对象。
 *（2）再调用Sample类的移动构造函数，将先前创建的匿名对象资源转移到一个新的临时对象中，并将其作为fun()函数的返回值。
 *     先前创建的匿名对象被销毁。
 *（3）如果将fun()函数的返回值赋值给一个Sample类型的变量，那么会再调用一次移动构造函数或移动运算符，
 *     将fun()函数的返回值资源，移动到将要赋值给的Sample变量中，移动完成以后fun()函数返回的临时对象被析构。
 *     如果将fun()函数的返回值赋值给一个Sample类型的右值引用，那么这个右值引用将变为fun()函数返回值的别名，
 *     fun()函数返回值生命周期得到了延长，而不会立即被销毁。但由于fun()函数的返回值是一个临时对象，所以不能
 *     将其赋值给一个左值引用。
 */
Sample fun()
{
	return Sample("fun",31);
}

#ifndef _CHANGE_WAY_
/*2.foo函数的调用返回过程：
 *（1）先调用Sample类的构造函数，创建一个Sample类型的变量。
 *（2）再调用Sample类的移动构造函数，将先前创建的Sample对象资源移动到一个新的临时对象中，并将其作为foo()函数的返回值。
 *     先前创建的Sample对象由于函数返回而被销毁。
 *（3）如果将foo()函数的返回值赋值给一个Sample类型的变量，那么会再调用一次移动构造函数或移动运算符，
 *     将foo()函数的返回值资源，移动到将要赋值给的Sample变量中，移动完成以后foo()函数返回的临时对象被析构。
 *     如果将foo()函数的返回值赋值给一个Sample类型的右值引用，那么这个右值引用是foo()函数返回值一个别名，
 *     foo()函数返回值生命周期得到了延长，而不会立即被销毁。fun()函数的返回值由于是一个临时对象，所以不能
 *     将返回赋值给一个左值引用。
 */
Sample foo()
{
	Sample sample("foo",32);  //如果使用临时对象或局部变量作为函数返回值时，编译器会将它们作为右值对待调用到移动构造函数。因为函数执行返回以后，
	return sample;            //局部变量和临时对象都会被销毁，为了提高资源利用率，避免不必要的深拷贝操作。会调用移动构造函数来构造一个临时的匿名
}                             //对象返回主函数中。由于局部变量是左值，所以编译器自动调用移动构造函数前，肯定先调用std::move函数将左值转化为了右值。
#else
/*3.foo函数的调用返回过程：
 *（1）先调用Sample类的构造函数，创建一个Sample类型的变量。
 *（2）再调用Sample类的深拷贝构造函数，将先前创建的匿名对象复制一份到一个新的临时对象中，并将其作为foo()函数的返回值。
 *     先前创建的变量由于函数返回而被销毁。
 *（3）如果将foo()函数的返回值赋值给一个Sample类型的变量，那么会再调用一次移动构造函数或移动运算符，
 *     将foo()函数的返回值资源移动到将要赋值给的Sample变量中，移动完成以后foo()函数返回的临时对象被析构。
 *     如果将foo()函数的返回值赋值给一个Sample类型的右值引用，那么这个右值引用是foo()函数返回值一个别名，
 *     foo()函数返回值生命周期得到了延长，而不会立即被销毁。foo()函数的返回值由于是一个临时对象，所以不能
 *     将返回赋值给一个左值引用。
 */
Sample foo()
{
	const Sample sample("foo",32);
	return sample;
}
#endif


#ifdef _EEROR_
#ifndef _CHANGE_WAY_
//4.bar函数实现存在的错误：函数返回的左值引用不能绑定到一个右值或临时匿名对象上。
Sample& bar()
{
	return Sample("bar",33);
}
#else
//5.bar函数实现存在的错误：虽然函数返回的常量左值引用可以绑定到一个右值或匿名临时对象上。但由于该匿名
//临时对象在函数返回之后就被析构了，所以bar()函数再返回一个被析构了的对象引用，编译器会直接报语法错误。
const Sample& bar()
{
	return Sample("bar",33);
}
#endif
#else
Sample& bar()
{
	g_sample = Sample("bar",33);
	return g_sample;
}
#endif

#ifdef _EEROR_
#ifndef _CHANGE_WAY_
//6.baz函数实现存在的错误：虽然函数返回的左值引用可以绑定到一个左值或变量上。但由于该变量是一个局部变量
//在函数返回之后就被销毁了，所以baz()函数再返回一个被销毁了的对象引用，编译器会直接报语法错误。
Sample& baz()
{
	Sample sample("baz",34);
	return sample;
}
#else
//7.baz函数实现存在的错误：虽然函数返回的常量左值引用可以绑定到一个常量左值或const变量上。但由于该const变量是
//一个局部变量在函数返回之后就被销毁了，所以baz()函数再返回一个被销毁了的对象引用，编译器会直接报语法错误。
const Sample& baz()
{
	const Sample sample("baz",34);
	return sample;
}
#endif
#else
Sample& baz()
{
	static Sample sample;
	sample = Sample("baz",34);
	return sample;
}
#endif

#ifdef _EEROR_
#ifndef _CHANGE_WAY_
//8.qux函数实现存在的错误：函数返回的右值引用不能绑定到一个左值或变量上。
Sample&& qux()
{
	Sample sample("qux",35);
	return sample;
}
#else
//9.qux函数实现存在的错误：虽然函数返回的右值引用可以绑定到一个右值或临时对象上。但由于该临时对象
//在函数返回之后就被析构了，所以qux()函数再返回一个被析构了的对象引用，编译器会直接报语法错误。
Sample&& qux()
{
	return Sample("qux",35);
}
#endif
#else
Sample&& qux(Sample& sample)
{
	sample = Sample("qux",35);
	return std::move(sample);
}
#endif

#ifdef _EEROR_
//10.quz函数实现存在的错误：虽然可以使用std::move函数将一个左值/变量转化为右值，再绑定到函数返回的右值引用上。
//但由于该局部变量在函数返回之后就被析构了，所以quz()函数再返回一个被析构了的对象引用，编译器会直接报语法错误。
Sample&& quz()
{
	Sample sample("quz",36);
	return std::move(sample);
}
#else
Sample&& quz()
{
	static Sample sample;
	sample = Sample("quz",36);
	return std::move(sample);
}
#endif

static void constructor_test();
static void assign_test();
static void fun_test();
static void foo_test();
static void bar_test();
static void baz_test();
static void qux_test();
static void quz_test();

int main(int argc,char** argv)
{
	constructor_test();
	assign_test();
	fun_test();
	foo_test();
	bar_test();
	baz_test();
	qux_test();
	quz_test();

	return 0;
}

void constructor_test()
{
	Sample sample;
	sample.setName("default");
	sample.setData(10);
	sample.show();
	cout<<"default constructor"<<endl<<endl;
	
	const Sample sample1(11);
	sample1.show();
	cout<<"normal constructor 1"<<endl<<endl;
	
	Sample sample2("normal: 2",12);
	sample2.show();
	cout<<"normal constructor 2"<<endl<<endl;

#ifndef _CHANGE_WAY_
	Sample sample3(sample);   //调用Sample(Sample& other)版本构造函数
#else
	Sample sample3 = sample;
#endif
	sample.show();
	sample3.show();
	cout<<"shallowly copy or move constructor"<<endl<<endl;

#ifndef _CHANGE_WAY_
	Sample sample4(sample1);    //调用Sample(const Sample& other)版本深拷贝构造函数
#else
	Sample sample4 = sample1;
#endif
	sample4.show();
	cout<<"deeply copy constructor"<<endl<<endl;
	
#ifndef _CHANGE_WAY_
	Sample sample5(Sample("move",13));    //会被编译器直接优化为：Sample sample5("move",13)
#else
	Sample sample5 = Sample("move",13);   //g++使用-fno-elide-constructors选项关闭编译器优化，VC++使用/Od选项关闭编译器优化。
#endif
	sample5.show();
	cout<<"normal or move constructor"<<endl<<endl;

#ifndef _CHANGE_WAY_
	Sample sample6(move(sample2));
#else
	Sample sample6 = std::move(sample2);
#endif
	sample6.show();
	sample2.show();     //sample2对象中的name成员指针内存空间已经被转移了
	cout<<"move constructor"<<endl<<endl;
}

void assign_test()
{
	Sample sample("hello",20);
	sample.show();
	
	Sample sample1("world",21);
	sample1.show();
	
	sample = sample1;       //调用Sample& operator =(Sample& other)赋值运算符
	sample.show();
	sample1.show();
	cout<<"call: operator =(Sample& other)"<<endl<<endl;
	
	const Sample sample2("C++",22);
	sample2.show();
	
	sample = sample2;
	sample.show();
	cout<<"call: operator =(const Sample& other)"<<endl<<endl;
	
	sample = Sample("Qt",23);
	sample.show();
	cout<<"call operator =(Sample&& other)"<<endl<<endl;
	
	Sample sample3("JAVA",24);
	sample3.show();
	
	sample = std::move(sample3);
	sample.show();
	sample3.show();
	cout<<"call: operator =(Sample&& other)"<<endl<<endl;
	
	Sample& lref = sample1;     //左值引用只能引用变量/引用/左值。
	lref.setData(25);
	lref.show();
	sample1.show();
	cout<<endl;
	
	const Sample& lref1 = sample1;    //常量左值引用可以引用变量/const变量/引用/const引用/左值/常量左值/右值/常量右值/临时对象。
	lref1.show();
	cout<<endl;
	
	const Sample& lref2 = Sample("C",26);
	lref2.show();
	cout<<endl;
	
	Sample&& rref = Sample("C#",27);      //右值引用可以引用临时对象，也可以通过std::move函数引用到变量
	rref.setData(28);
	rref.show();
	cout<<endl;
	
	Sample&& rref1 = std::move(sample1);
	rref1.setName("JavaScript");          //右值引用的值改变，其通过std::move函数绑定的变量也会跟着改变
	rref1.setData(29);
	rref1.show();
	sample1.show();
}

static void fun_test()
{
	Sample sample("sample",31);
	sample = fun();     //调用移动赋值运算符，将fun()函数的返回值赋值给sample变量
	sample.show();
	cout<<endl;
	
	Sample sample1 = fun();   //调用移动构造函数，将将fun()函数的返回值赋值给sample对象
	sample1.show();
	cout<<endl;

#ifdef _EEROR_
	Sample& rsample = fun();
#else
	Sample&& rsample = fun();
#endif
	rsample.show();
}

static void foo_test()
{
	Sample sample("sample",41);
	sample = foo();     //调用移动赋值运算符，将fun()函数的返回值赋值给sample变量
	sample.show();
	cout<<endl;
	
	Sample sample1 = foo();   //调用移动构造函数，将将fun()函数的返回值赋值给sample对象
	sample1.show();
	cout<<endl;

#ifdef _EEROR_
	Sample& rsample = foo();   //左值引用无法绑定到匿名的临时对象上。
#else
	Sample&& rsample = foo();  //右值引用可以绑定到匿名的临时对象上
#endif
	rsample.show();
}

void bar_test()
{
	Sample sample("sample",51);
	sample = bar();         //调用移动赋值运算符，将bar()函数的返回值赋值给sample变量
	sample.show();
	cout<<endl;
	
	Sample sample1 = bar();  //调用移动构造函数，将将bar()函数的返回值赋值给sample对象
	sample1.show();
	cout<<endl;
	
#ifndef _EEROR_
	Sample& rsample = bar();   //左值引用可以绑定到bar()函数返回的左值引用上。
#else
	Sample&& rsample = bar();  //右值引用不可以绑定到bar()函数返回的左值引用上。
#endif
	rsample.show();
}

void baz_test()
{
	Sample sample("sample",61);
	sample = baz();         //调用移动赋值运算符，将baz()函数的返回值赋值给sample变量
	sample.show();
	cout<<endl;
	
	Sample sample1 = baz();  //调用移动构造函数，将将baz()函数的返回值赋值给sample对象
	sample1.show();
	cout<<endl;
	
#ifndef _EEROR_
	Sample& rsample = baz();   //左值引用可以绑定到baz()函数返回的左值引用上。
#else
	Sample&& rsample = baz();  //右值引用不可以绑定到baz()函数返回的左值引用上。
#endif
	rsample.show();
}

void qux_test()
{
#ifdef _EEROR_
	Sample sample("sample",71);
	sample = qux();         //调用移动赋值运算符，将baz()函数的返回值赋值给sample变量
	sample.show();
	cout<<endl;
	
	Sample sample1 = qux();  //调用移动构造函数，将将baz()函数的返回值赋值给sample对象
	sample1.show();
	cout<<endl;
	
#ifndef _CHANGE_WAY_
	Sample& rsample = qux();   //左值引用不可以绑定到baz()函数返回的右值引用上。
#else
	Sample&& rsample = qux();  //右值引用可以绑定到baz()函数返回的右值引用上。
#endif
	rsample.show();
#else    //_EEROR_
	Sample sample("sample",71);
	Sample sample1("sample",72);
	sample1 = qux(sample);         //调用移动赋值运算符，将baz()函数的返回值赋值给sample变量
	sample.show();
	sample1.show();
	cout<<endl;
	
	Sample sample2 = qux(sample);  //调用移动构造函数，将将baz()函数的返回值赋值给sample对象
	sample2.show();
	cout<<endl;

#ifdef _EEROR_
	Sample& rsample = qux(sample);   //左值引用不可以绑定到baz()函数返回的右值引用上。
#else
	Sample&& rsample = qux(sample);  //右值引用可以绑定到baz()函数返回的右值引用上。
#endif
	rsample.show();
#endif
}

void quz_test()
{
	Sample sample("sample",81);
	sample = quz();         //调用移动赋值运算符，将baz()函数的返回值赋值给sample变量
	sample.show();
	cout<<endl;
	
	Sample sample1 = quz();  //调用移动构造函数，将将baz()函数的返回值赋值给sample对象
	sample1.show();
	cout<<endl;
	
#ifdef _EEROR_
	Sample& rsample = quz();   //左值引用不可以绑定到baz()函数返回的右值引用上。
#else
	Sample&& rsample = quz();  //右值引用可以绑定到baz()函数返回的右值引用上。
#endif
	rsample.show();
}