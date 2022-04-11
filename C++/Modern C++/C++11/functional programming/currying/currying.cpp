/*1.函数式编程的三大特性：
 *（1）不可变数据（immutable data）：默认上变量是不可变的，如果要改变变量，需要把变量copy出去修改。
 *     这样可以让程序少很多Bug。因为程序中的状态不好维护，在并发的时候更不好维护。
 *（2）头等函数（first class functions）：可以让函数就像变量一样来使用。即函数可以像变量一样被创建、
 *     修改、传递、返回或是在函数中嵌套函数。
 *（3）尾递归优化（tail recursion optimization）：递归的害处是如果递归很深的话stack受不了，并会导致
 *     性能大幅度下降。尾递归优化技术每次递归时，都会重用stack，这样一来能够提升性能，当然这需要语言
 *     或编译器的支持。C++标准库并不保证尾递归优化能够执行，但是主流的C++编译器（如GCC\Clang\MVSC）
 *     都是支持尾递归优化的。
 */

/*2.函数式编程的几个技术：
 *（1）map&reduce：函数式编程最常见的技术就是对一个集合做Map和Reduce操作。它们很像C++中的for_each()、
 *     find_if()、count_if()之流的函数玩法。map&reduce操作比起过程式的语言来说，在代码上要更容易阅读。
 *     传统过程式的语言需要使用for/while循环，然后在各种变量中把数据倒过来倒过去的。
 *（2）pipeline：就是把函数实例成一个一个的action，然后把一组action放到一个数组或是列表中，然后把数据
 *     传给这个action list，数据就像一个pipeline一样顺序地被各个函数所操作，最终得到想要的结果。
 *（3）recursing：递归最大的好处就简化代码，它可以把一个复杂的问题用很简单的代码描述出来。递归的精髓
 *     是描述问题，而这正是函数式编程的精髓。
 *（4）currying：把一个函数的多个参数分解成多个函数，然后把函数多层封装起来，每层函数都返回一个函数
 *     去接收下一个参数，这样就可以简化函数的多个参数。std::bind()、std::bind1st()和std::bind2nd()
 *     就是C++中用于函数柯里化的工具。
 *（5）higher order function：高阶函数就是函数当参数，把传入的函数做一个封装，然后返回这个封装函数。
 *     现象上就是函数传进传出，就像面向对象编程中对象满天飞一样。
 */

/*3.函数式编程的优点：
 *（1）并行处理（parallelization）：所谓并行的意思就是在并行环境下，各个线程之间不需要同步或互斥。
 *（2）惰性求值（lazy evaluation）：表达式不在它被绑定到变量之后就立即求值，而是在该值被取用的时候求值。
 *     惰性求值需要编译器的支持。
 *（3）确定性（determinism）：所谓确定性的意思就是像数学中函数那样无论在什么场景下，都会得到同样的结果。
 *     而不是像程序中的很多函数那样，同一个参数，却会在不同的场景下计算出不同的结果。其中不同的场景的意思
 *     是指函数会根据一些运行中的状态信息的不同而发生变化。
 */
 
/*4.柯里化：
 *（1）函数式编程中比较灵活的一个地方就是柯里化。柯里化是把多个参数的函数变换成单参数的函数，
 *     并返回一个新函数，这个新函数处理剩下的参数。
 *（2）currying把一个多参数的函数，转化为单参数函数。让我们可以给一个函数传递较少的参数，
 *     得到一个已经记住了某些固定参数的新函数。这是一种对函数参数的缓存，让函数变得更灵活，
 *     让函数的粒度更小。
 */

#include <iostream>
#include <functional>

using namespace std;

int func(int x,int y,int z)
{
	return (x + y) * z;
}

/*假设有许多个应用都会调用func()函数，其中每个应用涉及的x、y参数都是一致的，所以每个应用中只提供
 *参数z就可以得到结果。我们可以在每次调用func()函数时都使用3个参数，但每次都提供x、y参数比较繁琐，
 *并且还极有可能输入错误。我们也可以为每一个应用编写一个新方法，将func()方法中的所有x、y参数替换
 *成默认值。这样做的确复用了底层代码，但是针对每一个应用你都需要定义一个这样的函数，应用有多少个，
 *就需要写多少个函数，假如应用有很多，带来的编码代价也很大。
 */
int func_adapter(int n)
{
	return func(4,5,n);
}

/*函数式编程中的柯里化提供了一种更简洁的解法，它既能充分利用已有的逻辑，又能让func()函数针对每
 *个应用进行定制。func_currying()函数返回一个新函数，它只需要一个参数z就可以运行。因此每个应用，
 *只需要先提供x、y两个参数，获取针对该应用下只需输入一个参数z的函数，然后在该应用中输入一个参数
 *就可以得到相应结果了。
 */
function<int(int)> func_currying(int x,int y)
{
	return [x,y](int z){return func(x,y,z);};
}

int add(int x,int y)
{
	return x + y;
}

function<int(int)> add(int x)
{
	return [=](int y){return add(x,y);};
}

int main(void)
{
	int ret = func(4,5,6);
	cout<<"func(): (4 + 5) * 6 ="<<ret<<endl;
	
	ret = func(4,5,8);
	cout<<"func(): (4 + 5) * 8 ="<<ret<<endl;
	
	/*使用func()的封装函数func_adapter()，可以减少func()调用时重复参数的输入。
	 *但是缺点是需要手动编程一个封装函数。
	 */
	ret = func_adapter(6);
	cout<<"func_adapter(): (4 + 5) * 6 ="<<ret<<endl;
	
	ret = func_adapter(8);
	cout<<"func_adapter(): (4 + 5) * 8 ="<<ret<<endl;
	
	auto foo = func_currying(4,5);
	ret = foo(6);
	cout<<"func_currying(): (4 + 5) * 6 ="<<ret<<endl;
	
	ret = foo(8);
	cout<<"func_currying(): (4 + 5) * 8 ="<<ret<<endl;
	
	/*使用std::bind()进行函数柯里化，即可以减少func()调用时重复参数的输入。
	 *还无需用户定义多余的函数。
	 */
	function<int(int)> bar = std::bind(func,4,5,placeholders::_1);
	ret = bar(6);
	cout<<"std::bind(): (4 + 5) * 6 ="<<ret<<endl;
	
	ret = bar(8);
	cout<<"std::bind(): (4 + 5) * 8 ="<<ret<<endl;
	
	ret = add(2,3);
	cout<<"add(): 2 + 3 ="<<ret<<endl;
	
	/*currying之后add(2)(3)等价于add(2,3)。柯里化默认是从左到右的，大部分编程语言并没有
	 *实现从右到左的柯里化。C++11里面的std::bind()可以实现柯里化，但要实现向左或向右灵活
	 *的柯里化比较困难。
	 */
	ret = add(2)(3);
	cout<<"currying add(): 2 + 3 ="<<ret<<endl;
	
	auto add2 = add(2);
	ret = add2(3);
	cout<<"add2(): 2 + 3 ="<<ret<<endl;
	
	//函数式编程的理念：是把函数当成变量来用，关注于描述问题而不是怎么实现，这样可以让代码更易读。
	function<int(int)> add3 = add(3);
	ret = add3(2);
	cout<<"add3(): 3 + 2 ="<<ret<<endl;
	
	return 0;
}