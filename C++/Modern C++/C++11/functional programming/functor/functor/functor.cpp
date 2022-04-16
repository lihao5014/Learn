/*1.JavaScript中的函子：
 *（1）函子是一个容器，包含值和值的变形关系（即函数）。
 *（2）JavaScript中的函子是一个特殊的容器，通过一个普通的对象来实现，该对象具有map()方法，
 *     map()方法可以运行一个函数对值进行处理（变形关系）。
 *（3）C++中的函子又称为函数对象或仿函数，是重载了函数调用运算符"()"的类。与JavaScript中的
 *     函子是包含了map()方法的类，定义是有区别的。
 *（4）函数式编程的运算不直接操作值，而是由函子完成。
 *（5）函子就是一个实现了map契约的对象
 *（6）可以把函子想象成一个盒子，盒子内部封装一个不对外公布的值，想要处理盒子中的值，
 *     我们需要给盒子的map方法传递一个处理值得函数（纯函数），由这个函数来对值进行处理
 *     最终map方法返回一个包含新值得盒子（函子），多次调用map方法，会形成函子嵌套。
 */

#include <iostream>
#include <functional>

using namespace std;

/*Container是一个函子，它的map()方法接受函数fun作为参数，然后返回一个新的函子，
 *里面包含的值是被fun处理过的。
 */
template <typename T>
class Container
{
public:
	Container(T n):m_data(n){}
	Container(const Container& other):m_data(other.m_data){}
	
	/*函数式编程一般约定，函子有一个of()方法，用来生成新的容器。可以用of()方法替换掉new操作符。
	 *因为new运算符是面向对象编程的标志，不符合函数式编程的思想。
	 */
	static Container of(T n)
	{
		return Container(n);     //C++中可以不使用new就可以创建新的对象。
	}
	
	T data()const{return m_data;}
	
	Container map(function<T(T)> fun)
	{
		return Container(fun(m_data));
	}
	
	void display()
	{
		cout<<m_data<<endl;
	}
private:
	T m_data;
};

int main(void)
{
	//使用C++实现JavaScript中的函子。
	Container<int> functor = Container<int>(5)
							.map([](int n){return n * 2;})
							.map([](int n){return n * n;});
	functor.display();
	
	//使用函子可以很方便的实现链式编程。
	double ret = Container<double>::of(3.14)
				.map([](double n){return n + 10;})
				.map([](double n){return n * 5;})
				.data();
	cout<<"ret ="<<ret<<endl;
	
	return 0;
}