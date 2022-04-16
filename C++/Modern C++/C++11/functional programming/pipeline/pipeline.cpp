/*1.pipeline表现形式:
 *（1）pipeline把一组函数放到一个数组或是列表中，然后把数据传给这个列表。数据就像一个链条一样
 *     顺序地被各个函数所操作，最终得到我们想要的结果。它的设计哲学就是让每个功能就做一件事，
 *     并把这件事做到极致，软件或程序的拼装会变得更为简单和直观。 
 *（2）pipeline链式调用的用法和Unix Shell的管道操作比较像，|前面的数据或函数作为|后面函数的输入，
 *     顺序执行直到最后一个函数。这种管道方式的函数调用让逻辑看起来更加清晰明了，也非常灵活，
 *     允许你将多个高阶函数自由组合成一个链条，同时还可以保存起来实现惰性求值。
 *（3）可以把pipeline分解为几部分：高阶函数，惰性求值，运算符|、柯里化和pipeline，把这几部分实现
 *     之后就可以组成一个完整的pipeline了。
 */

/*2.实现pipeline的关键技术：
 *（1）高阶函数：函数式编程的核心就是函数，它是一等公民，最灵活的函数就是高阶函数，现代C++的算法中
 *     已经有很多高阶函数了，比如for_each()、transform()、copy_if()、remove_if()和accumulate()等。
 *     这些高阶函数不仅可以接受lambda表达式，还能接受std::function、函数对象、普通全局函数和函数指针。
 *     需要注意的是普通的全局函数在pipeline时存在局限性，因为它不像函数对象一样可以保存起来延迟调用，
 *     所以我们需要一个方法将普通的函数转换为函数对象。std::bind()也可以将函数转化为函数对象，
 *     但是bind()不够通用，使用的时候它只能绑定有限的参数，如果函数本身就是可变参数的就无法bind了。
 *（2）惰性求值：惰性求值是将求值运算延迟到需要值时候进行，通常的做法是将函数或函数的参数保存起来，
 *     在需要的时候才调用函数或者将保存的参数传入函数实现调用。现代C++里已经提供可以保存起来的函数
 *     对象和lambda表达式，因此需要解决的问题是如何将参数保存起来，然后在需要的时候传给函数实现调用。
 *     我们可以借助std::tuple、type_traits和可变模版参数来实现目标。
 *（3）运算符“|”：pipeline的一个主要表现形式是通过运算符“|”来将数据和函数分隔开，或将函数和函数组成
 *     一个链条。C++实现类似的调用可以通过重载运算符来实现。
 *（4）柯里化：函数式编程中比较灵活的一个地方就是柯里化。柯里化是把多个参数的函数变换成单参数的函数，
 *     并返回一个新函数，这个新函数处理剩下的参数。
 *（5）pipeline：C++中通过运算符“|”重载，虽然可以实现一个简单的pipeline，进行管道方式的链式计算，
 *     但是它只是将data和函数通过“|”连接起来了，还没有实现函数和函数的连接，并且函数是立即计算的，
 *     没有实现延迟计算。因此还需要实现通过“|”连接函数，从而实现灵活的pipeline。我们可以通过一个
 *     function chain来接受任意个函数并组成一个函数链。利用可变模版参数、tuple和type_traits就可以
 *     实现了。
 */

#include <iostream>
#include <functional>
#include <utility>    //std::forward()

using namespace std;

/*在C++20引入范围库之后，可以使用operator |链接两个范围适配器闭包对象的结果。
 *而在此之前我们可以尝试重载管道符，达到类似的效果。
 */
template <typename T,class F>
auto operator |(T&& param,const F& fun) -> decltype(fun(forward<T>(param)))
{
	return fun(forward<T>(param));
}

int increment(int n)
{
	return n + 1;
}

struct Square
{
	int operator ()(int n)const
	{
		return n * n;
	}
};

int main(void)
{
	int result = 5 | [](int n){return n * 2;};
	cout<<"5 * 2 = "<<result<<endl;
	
	function<int(int)> inc = bind(increment,placeholders::_1);
	int ret = 2 | inc | Square() | [](int n){return n * 10;};
	cout<<"(2 + 1)^2 * 10 ="<<ret<<endl;
	
	auto foo = [](int n){return n + 3;};
	auto bar = [](int n){return n * 3;};
	auto qux = [](int n){return n * n * n;};
	ret = 1 | foo | bar | qux;
	cout<<"((1 + 3) * 3)^3 ="<<ret<<endl;
	
	return 0;
}