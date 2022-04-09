/*2.函数式编程中的闭包:（闭包 = 状态 + 函数 = 类）
 *（1）函数和对其周围状态的引用捆绑在一起构成闭包。也就是说，闭包可以让你从内部函数访问外部函数作用域。
 *（2）闭包又称词法闭包或函数闭包，是引用了自由变量的函数。这个被引用的自由变量将和这个函数一同存在，
 *     即使已经离开了创造它的环境也不例外。所以有另一种说法认为，闭包是由函数和与其相关的引用环境组合
 *     而成的实体。闭包在运行时可以有多个实例，不同的引用环境和相同的函数组合可以产生不同的实例。
 *（3）闭包就是能够读取其他函数内部变量的函数。即“引用了自由变量的函数”、“带有上下文的函数”或
 *     “有状态的函数”的特殊函数。
 *（4）闭包是可以包含自由变量的代码块，这些变量不是在这个代码块内或者任何全局上下文中定义的，
 *     而是在定义代码块的环境中定义（局部变量）。闭包是要执行的代码块和为自由变量提供绑定的
 *     计算环境（作用域）两者的结合。
 *（5）闭包是带有上下文的函数或有状态的函数。可以说闭包就是面向对象编程中的类在函数式编程中
 *     换了个名字而已。函数带上了状态就变成了闭包，带上状态的意思是这个闭包有属于自己的变量，
 *     这些个变量的值是创建闭包的时候设置的，并在调用闭包的时候，可以访问这些变量。
 *（6）函数是代码，状态是一组变量，将代码和一组变量捆绑就形成了闭包。但内部包含static静态变量
 *     的函数不是闭包，因为static静态变量不能捆绑。我们不能捆绑不同的static静态变量，因为这个
 *     在编译的时候已经确定了。闭包的状态捆绑，必须发生在运行时。
 */

#include <iostream>
#include <functional>

#define _ERROR_
#undef _ERROR_

using namespace std;

/*因为lambda表达式可以通过捕获列表，访问到lambda外部作用域中的变量。
 *所以lamdba表达式是天生支持函数式编程的闭包特性的。
 */
function<void(void)> once()
{
	static bool flag = true;
	return []{                  //静态变量可以在lambda中直接访问，而不需要捕获。
				if(flag)
				{
					cout<<"function call once!"<<endl;
				}
				flag = false;
			};
}

/*闭包就是能够读取其他函数内部变量的函数。只有函数内部的子函数才能读取局部变量，
 *所以闭包可以理解成“定义在一个函数内部的函数“。在本质上闭包是将函数内部和函数
 *外部连接起来的桥梁。
 */
#ifndef _ERROR_
function<int(int)> accumulator()
{
	int sum = 0;               //因为函数内部定义了局部变量，所以该闭包属于有状态、有变量的闭包。
	return [=](int n)mutable{
				sum += n;
				return sum;
			};
}
#else
function<int(int)> accumulator()
{
	int sum = 0;              //出了函数作用域局部变量就被销毁了，所以实现有状态的闭包时，不介意使用引用捕获。
	return [&sum](int n){
				sum += n;
				return sum;
			};
}
#endif

function<int(int)> adder(int x)    //无状态、无变量的闭包
{
	return [x](int y){return x + y;};
}

#ifndef _ERROR_
function<int(void)> fibonacci()    //使用闭包实现斐波那契数列
{
	int a = 1,b = 1;
	return [=]()mutable{
				int temp = a;
				a = b;
				b = temp + b;
				return a;
			};
}
#else
function<int(void)> fibonacci()
{
	int a = 0,b = 1;           //出了函数作用域局部变量就被销毁了，所以实现有状态的闭包时，不介意使用引用捕获。
	return [&](){
				int temp = a;
				a = b;
				b = temp + b;
				return a;
			};
}	
#endif

int main(void)
{
	auto foo = once();
	foo();
	
	function<void(void)> bar = once();
	foo();
	
	function<int(int)> sum = accumulator();    //普通闭包调用
	sum(1);
	sum(2);
	int ret = sum(3);
	cout<<"1 + 2 + 3 ="<<ret<<endl;
	
	auto plus = adder(0);            //无状态、无变量的闭包调用
	for(int i=1;i<10;++i)
	{
		ret = plus(i);
		plus = adder(ret);
	}
	cout<<"1 + 2 + ... + 9 ="<<ret<<endl;
	
	auto fun = fibonacci();
	for(int i=0;i<10;++i)
	{
		cout<<fun()<<" ";
	}
	cout<<endl;
	
	return 0;
}