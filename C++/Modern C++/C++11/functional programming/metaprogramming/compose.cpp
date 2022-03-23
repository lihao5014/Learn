/*1.元编程与函数式编程：
 *（1）由于模板元编程借助的是C++模板的特化能力，使它的设计方法迥异于普通的C++编程习惯。
 *     不能够在元函数中使用变量，编译期显然只可能接受静态定义的常量。因此我们不能够使用
 *     传统意义上的循环；要实现任何分支选择，唯一的方法是调用其它元函数或者使用递归。
 *     这种编程风格正是具有重要理论意义的函数式编程。
 *（2）模板元编程具有的数值计算能力，但主要用到的还是它的类型处理能力。
 */

/*2.函数式编程的特点：
 *（1）所有的过程都是函数，并且严格地区分输入值（参数）和输出值（结果）。
 *（2）没有变量或赋值。变量被参数替代。
 *（3）没有循环。循环被递归调用替代。
 *（4）函数的值只取决于它的参数的值而与求得参数值的先后或者调用函数的路径无关。
 *（5）函数是一类值。
 */
 
/*函数是一类值是函数式编程的一个很重要的性质，指的是函数和值是同等的概念，
 *一个函数可以作为另外一个函数的参数，也可以作为值使用。如果函数可以作为一类值使用，
 *那么我们就可以写出一些函数，使得这些函数接受其它函数作为参数并返回另外一个函数。
 *比如定义了f()和g()两个函数，用compose(f,g)的风格就可以生成另外一个函数，
 *使得这个函数执行f(g(x))的操作，则可称compose为高阶函数。
 */

/*3.C语言不能进行函数式编程：
 *如果排除“函数是一类值”的特点，那么C语言已经能完整模拟出函数式编程的风格，但是在C语言中，
 *函数却并不能作为一类值。也许我们会想到函数指针，但是如果我们的函数需要返回另一个函数的指针，
 *因为C语言禁止在函数中定义函数，所以是不能通过编译的。
 */

/*4.C语言进行函数式编程，但遗憾的是该例子不能编译通过的。
typedef int(*IntProc) (int); 

IntProc compose(IntProc f, IntProc g)  
{  
    int tempProc(int x)    //C语言禁止在函数中定义函数
    {  
        return f(g(x));  
    }  
    return tempProc;  
}
*/

/*5.C++中进行函数式编程的方法：
 *（1）仿函数：在C++中利用类和模板来解决C语言函数内不能再定义其他函数的问题，因为C++允许重载()操作符，
 *     建立所谓的仿函数。因为仿函数类对象既可以作为值来传递，又可以像函数一样用obj(x)的语法来调用了。
 *     另一方面利用模板对返回值的控制，就可以避免函数里面无法定义内部函数的矛盾了。
 *（2）元编程：C++模板机制也可以满足将元函数作为一类值使用，即可以使用元编程来实现函数式编程中的高阶函数。
 *     不过解答稍稍有点复杂，并不像仿函数的解决方法一样优雅。
 */

/*6.模板元编程实现函数式编程/高阶函数的2个弊端：
 *（1）在compose的模板参数中，不能直接使用类似于template <class op1, class op2>的写法，
 *     原因是C++的模板机制严格区分模板和类，我们无法把模板直接作为另一个模板的参数，
 *     唯一可行的方法是使用“作为类模板的模板参数”，这样就把f和g的参数类型限制死了。
 *     不过我们似乎仍然可以勉强接受这个限制，事实上模板机制对非类型的模板参数本来就存在着限制，
 *     因为现在的C++标准禁止浮点数、类对象、字符串、全局指针或其他内部链接对象作为模板参数，
 *     所以非类型的模板参数实际上只剩下bool布尔型和int整型可用。由于模板参数是无法重载的，
 *     写成类似composeint和composebool的两个类仍然有可行性。
 *（2）其次同样是C++的模板机制严格区分模板和类的缘故，返回值return_type是一个模板，
 *     而并不是一个元函数或类。
 *（3）元编程实现高阶函数的2个弊端中都隐含着一个最大共同问题，即C++对“作为类模板的模板参数”
 *     作了很严格的限制，所以一旦定义了以后，其模板参数的个数不能改变。当然在STL里面我们似乎
 *     习惯了这个限制，并用重新定义函数的方式来避开这个限制。但在作为函数式编程的模板元编程里面，
 *     似乎应该要求以更优雅的方式来解决。
 *（4）虽然使用模板元编程实现高阶函数具有很多障碍，但通过增加包装层和使用lambda演算的概念，
 *     高阶函数依然能用上，使得模板元编程能够符合函数式编程的要求。
 */

/*由于C++模板能够使用函数式编程，那么也就意味着这个C++语言的子集已经是图灵完备的，
 *因为任何计算都可以使用函数来描述，理论上模板元编程应该能完成图灵机上的一切运算。
 *当然理论上的完备并不意味着实用性。尽管在C++中能够在某种程度上使用函数式编程的风格，
 *但是从实用性和效率来说，大概没有程序员使用纯粹的函数编程方式。不过在进行模板元编程的时候，
 *由于语法的特殊性，却不得不使用纯粹函数式编程。因此模板元编程与传统的C++命令式编程相差很大，
 *并不符合大多数C++程序员的习惯，不但会带来编写上的困难，而且还增加了许多程序理解上的难度。
 */

#include <iostream>

using namespace std;

//可惜元函数连double类型都不能计算，只能计算int或bool类型参数。
template <int N>
struct Foo
{
	static const int value = N * 2 + 1;    //元函数：f(x) = 2x + 1
};

template <int N>
struct Bar
{
	static const int value = N * N;        //元函数：g(x) = x^2
};

template <template<int N> class op1,template<int N> class op2>
struct Compose
{
	template <int N>
	struct return_type
	{
		static const int value = op1<op2<N>::value>::value;   //复合函数：h(x) = f(g(x))
	};
};

int main(void)
{
	//Foo和Bar是两个元函数，Compose接受Foo和Bar作为参数，生成了一个可以计算Foo(Bar(x))的新函数
	int ret = Compose<Foo,Bar>::return_type<5>::value;
	cout<<"Foo(Bar(x)) = (x * x)*2 + 1 : (5 * 5) * 2 + 1 ="<<ret<<endl;
	
	typedef Compose<Bar,Foo>::return_type<5> fun;
	cout<<"Bar(Foo(x)) = (x*2 + 1)^2 : (5 * 2 + 1)^2 ="<<fun::value<<endl;
	
	return 0;
}
