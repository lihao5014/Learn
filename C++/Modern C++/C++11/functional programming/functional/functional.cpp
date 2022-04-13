/*1.函数式编程的概念：
 *（1）函数式编程是与“面向对象”和“过程化”编程并列的一种编程范式，也就是如何编写程序的方法论。
 *     它属于结构化编程的一种，主要思想是把运算过程尽量写成一系列嵌套的函数调用。
 *（2）函数式编程最主要的特征是，函数作为第一等公民。它将计算机运算看做是数学中函数的计算，
 *     强调将计算过程分解成可复用的函数，且避免了状态以及变量的概念。只有纯粹的、没有副作用
 *     的函数，才是合格的函数。
 */

/*2.函数式编程的特点：
 *（1）函数是第一等公民。所谓“第一等公民”指的是函数与其他数据类型一样，处于平等地位，
 *     可以赋值给其他变量，也可以作为参数，传入另一个函数，或者作为别的函数的返回值。
 *（2）只用表达式，不用语句。 “表达式”是一个单纯的运算过程，总是有返回值。“语句”是执行某种操作，
 *     没有返回值。函数式编程要求只使用表达式，而不使用语句。也就是说每一步都是单纯的运算，
 *     而且都有返回值。原因是函数式编程的开发动机，一开始就是为了处理运算，不考虑系统的I/O读写。
 *     语句属于对系统的读写操作，所以就被排斥在外。当然实际应用中不做I/O读写操作是不可能的。
 *     因此函数式编程过程中只要求把I/O限制到最小，不要有不必要的读写行为，保持计算过程的单纯性。
 *（3）没有副作用。所谓“副作用”指的是函数内部与外部互动，产生运算以外的其他结果，最典型的情况
 *     就是修改全局变量的值，函数式编程强调没有副作用，意味着函数要保持独立，所有功能就是返回
 *     一个新的值，没有其他行为，尤其是不得修改外部变量的值。
 *（4）不修改状态。函数式编程只是返回新的值，不修改系统变量。因此不修改变量也是它的一个重要特点。
 *     在其他编程范式的语言中，变量往往用来保存“状态”。不修改变量，意味着状态不能保存在变量中。
 *     函数式编程使用参数保存状态，最好的例子就是递归。由于使用了递归，函数式语言的运行速度比较慢，
 *     这是它长期不能在业界推广的主要原因。
 *（5）引用透明。“引用透明”指的是函数的运行不依赖于外部变量或状态，只依赖于输入的参数，
 *     任何时候只要参数相同，调用函数所得到的返回值总是相同的。在其他类型的编程语言中，
 *     函数的返回值往往与系统状态有关，不同的状态之下，返回值是不一样的。这就叫“引用不透明”，
 *     很不利于观察和理解程序的行为。
 */

/*3.函数式编程的优点：
 *（1）代码简洁，开发快速。函数式编程大量使用函数，减少了代码的重复，因此程序比较短，
 *     开发速度较快。
 *（2）接近自然语言，易于理解。函数式编程的自由度很高，可以写出很接近自然语言的代码。
 *（3）更方便的代码管理。函数式编程不依赖、也不会改变外界的状态，只要给定输入参数，
 *     返回的结果必定相同。因此每一个函数都可以被看做独立单元，很有利于进行单元测试和除错，
 *     以及模块化组合。
 *（4）易于并发编程。函数式编程不需要考虑死锁，因为它不修改变量，所以根本不存在锁线程的问题。
 *     不必担心一个线程的数据被另一个线程修改，所以可以很放心地把工作分摊到多个线程，部署并发编程。
 *     由于函数之间互不干扰，不会修改变量，谁先执行是无所谓的，所以可以放心地增加线程，把它们分配
 *     到多个线程上完成。其他类型的语言就做不到这一点，因为一个函数中可能会修改系统状态，而另外的
 *     函数中可能会用到这些状态，所以常常需要保证多个函数的执行顺序，自然也就不能部署到多个线程上。
 *     多核CPU是将来的潮流，所以函数式编程的这个特性非常重要。
 *（5）代码的热升级。函数式编程没有副作用，只要保证接口不变，内部实现是外部无关的。所以可以在运行
 *     状态下直接升级代码，不需要重启，也不需要停机。
 */

#include <stdio.h>
#include <iostream>
#include <string>

#define _CHANGE_WAY_
#undef _CHANGE_WAY_

using namespace std;

static int g_count = 5;

//因为increment()函数依赖于外部的数据，而且修改了外部数据的值，所以不属于函数式编程范式。
void increment()
{
    g_count++;
}

//函数式编程的准则：不依赖于外部的数据，而且也不改变外部数据的值，而是返回一个新的值给你
int increment(int num)
{
    return num+1;
}

class Number
{
public:
	Number(int n):m_value(n){}
	Number(const Number& other):m_value(other.m_value){}
	
	void setValue(int num){m_value = num;}
	int getValue()const{return m_value;}
	
	Number add(Number m){return Number(m_value + m.m_value);}
	Number subtract(Number m){return Number(m_value - m.m_value);}
	Number multiply(Number m){return Number(m_value * m.m_value);}
	
	friend Number add(Number x,Number y);
	friend Number subtract(Number x,Number y);
	friend Number multiply(Number x,Number y);
	
	friend ostream& operator <<(ostream &os,const Number& num)
	{
		os << num.m_value;
		return os;
	}
private:
	int m_value;
};

int add(int x,int y)
{
	return x + y;
}

int subtract(int x,int y)
{
	return x - y;
}

int multiply(int x,int y)
{
	return x * y;
}

Number add(Number x,Number y)
{
	return Number(x.m_value + y.m_value);
}

Number subtract(Number x,Number y)
{
	return Number(x.m_value - y.m_value);
}

Number multiply(Number x,Number y)
{
	return Number(x.m_value * y.m_value);
}

typedef int data_t;
typedef void (*pFun)(data_t);

void print(data_t n)
{
	cout<<n<<" ";
}

//因为foreach()接受其它函数作为参数，所以它是一个高阶函数。
#ifndef _CHANGE_WAY_
void foreach(data_t* beginPtr,data_t* endPtr,pFun fun)  //循环语句中使用了局部变量，所以不属于函数式编程。
{
	for(data_t* p = beginPtr;p != endPtr;++p)
	{
		fun(*p);
	}
}
#else
void foreach(data_t* beginPtr,data_t* endPtr,pFun fun)  //使用递归代替循环语句，才是函数式编程的范式。
{
	if(beginPtr == endPtr)
	{
		return;
	}
	else
	{
		fun(*beginPtr);
		return foreach(beginPtr + 1,endPtr,fun);
	}
}	
#endif

//将字符串逆序排列的函数，它演示了不同的参数如何决定了运算所处的"状态".
string stringReverse(string str)
{
	if(str.length() <= 1)
	{
		return str;
	}
	else
	{
		return stringReverse(str.substr(1,str.length())) + str.at(0);
	}
}

int main(void)
{
	increment();    //有状态函数是不可重入的，非函数式编程范式中推荐使用的函数类型。
	cout<<"g_count ="<<g_count<<endl;
	
	int count = 5;
	int ret = increment(count);    //无状态函数都是可重入的，便于并发程序设计，是函数式编程范式中推荐使用的函数类型。
	cout<<"ret ="<<ret<<endl<<endl;
	
	//传统的过程式编程中，使用函数式编程思想计算(1 + 2) * 3 - 4表达式，
	int a = 1 + 2;
	int b = a * 3;
	int c = b - 4;
	printf("(1 + 2) * 3 - 4 =%d\n",c);
	
	//函数式编程要求使用函数，我们可以把运算过程定义为不同的函数，即把最基础的表达式操作都封装成函数。
	ret = subtract(multiply(add(1,2),3),4);       //C语言函数式编程中的pipeline表现形式。
	printf("(1 + 2) * 3 - 4 =%d\n",ret);
	
	//因为使用add(1,2)会调用add(int,int)重载函数，为了显示调用add(Number,Number)只能使用add(Number(1),2)。
	Number num = add(Number(1),2).multiply(3).subtract(4);     //函数式编程中的pipeline表现形式。
	cout<<"(1 + 2) * 3 - 4 ="<<num<<endl<<endl;
	
	data_t arr[] = {2,4,6,7,0,8,1,5,9,3};
	foreach(arr,arr + sizeof(arr)/sizeof(arr[0]),print);
	cout<<endl<<endl;
	
	string str = "hello world";
	cout<<"str ="<<str<<" , reverse: "<<stringReverse(str)<<endl;
	
	return 0;
}