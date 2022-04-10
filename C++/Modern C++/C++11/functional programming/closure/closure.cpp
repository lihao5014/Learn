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

/*2.C++中闭包的３种实现方法：
 *（1）重载operator()的函数对象：因为闭包是一个函数加上状态，而状态可以通过隐含的this指针传入，
 *     所以闭包必然是一个函数对象。因为成员变量就是极好的用于保存状态的工具。因此实现operator()
 *     运算符重载，该类的对象就能作为闭包使用。默认传入的this指针提供了访问成员变量的途径。
 *     事实上lambda表达式和std::bind()的原理都是通过仿函数实现的。
 *（2）lambda表达式：c++11中提供的lambda就是实现闭包很好的语法糖。其本质和手写的函数对象没有区别。
 *     实际上编译器是将lambda表达式翻译成未命名类的未命名对象并重载了函数调用运算符，当lambda有捕获
 *     变量时（即未命名对象有自己的成员数据）就形成了闭包。所以lambda表达式就是函数对象的简化写法。
 *（3）std::bind()：c++11标准库中提供的bind()是更加强大的语法糖，可以将需要手写很多代码的闭包，
 *     浓缩到一行bind()就可以搞定了。
 */

/*3.C++中使用闭包的注意事项：
 *（1）闭包的状态特指其运行的上下文。闭包将存贮它运行时需要的上下文，从而保证在closure创建时的上下文
 *     可以在closure运行时依然有效。闭包保存上下文的这一特点通常被称作“capture”捕获或者是"bind"捆绑。
 *     capture捕获可以自己写构造函数传参，也可以用std::bind()。当然最方便的还是让编译器帮你自动完成。
 *     编译器将自动识别closure用到的变量，然后创建一个匿名的类，将这个变量保存到匿名类的成员变量中。
 *（2）C++中lambda表达式有2种capture方式：by value和by reference，写法是[=]和[&]。需要注意按引用捕获
 *     是不会修改被capture变量的生命周期的，要人为保证被capture的变量在closure运行时是有效的。
 *（3）由lambda表达式创建的闭包类型是隐藏的，每次创建一个closure，编译器都会创建一个新的类型。
 *     如果想保存一个闭包时就不是那么直接，因为不知道它的类型。简单的方式是直接用auto关键字或
 *     std::function来保存。
 *（3）C++闭包中保存了其代码内全部向外引用的变量的拷贝或引用。如果是对外界环境中的对象的引用，
 *     且闭包执行时该外界环境的变量已经不存在，那么可导致未定义行为，因为C++并不扩展这些被引用
 *     的外界环境的变量的生命期。即C++中闭包只使用这些变量，不管这些变量的生存周期。
 */

#include <iostream>
#include <functional>       //function,bind(),placeholders::_1,placeholders::_2
#include <string>
#include <memory>           //unique_ptr,shared_ptr
#include <unordered_map>    //unordered_map

#define _ERROR_
#undef _ERROR_

using namespace std;

/*通过在重载"()"函数调用运算符中使用类的成员数据实现闭包，一般在C++中也称闭包为携带了状态的函数对象。
 *外部变量即为函数对象的状态。类中重载"()"操作符的方式使用闭包比较繁琐，对于每一段闭包代码都要单独
 *写一个函数对象类，所以C++11中引入了更为方便的方式，即lambda表达式和std::bind()。
 */
class Accumulator
{
public:
	Accumulator(int init):m_result(init){}
	
	int operator ()(int n)
	{
		m_result += n;
		return m_result;
	}
	
private:
	int m_result;   //一个函数对象就是一个闭包。其中函数对象的成员变量就相当于闭包的状态。
};

/*闭包就是能够读取其他函数内部变量的函数。只有函数内部的子函数才能读取局部变量，
 *所以闭包可以理解成“定义在一个函数内部的函数“。在本质上闭包是将函数内部和函数
 *外部连接起来的桥梁。
 */
#ifndef _ERROR_
function<int(int)> accumulator()
{
	int sum = 0;                 //因为函数内部定义了局部变量，所以该闭包属于有状态、有变量的闭包。
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

/*因为lambda表达式可以通过捕获列表，访问到lambda外部作用域中的变量。
 *所以lamdba表达式是天生支持函数式编程的闭包特性的。
 */
function<int(int)> adder(int x)    //无状态、无变量的闭包
{
	return [x](int y){return x + y;};
}

/*std::bind()通过把外部变量和函数绑定在一起实现闭包，bind()返回值为一个函数对象，
 *可使用类模板std::function接收。
 */
int power(int m,int n)
{
	int ret = 1;
	while(n --> 0)
	{
		ret *= m;
	}
	return ret;
}

/*内部包含static静态变量的函数不是闭包，因为static静态变量是once()函数返回闭包的共有状态。
 *而不是某个闭包的私有状态。
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

//C++为静态语言，使用任何手段模拟动态功能，都意味着性能损失。一味的追求语法方便，与性能上的折中是矛盾的。
unordered_map<string,function<int(void)>> counter(int init)
{
	shared_ptr<int> pnumber(new int{init});
	unordered_map<string,function<int(void)>> funcHash;
	
	funcHash["reset"] = [=]()->int{
		*pnumber = init;
		return *pnumber;
	};
	
	funcHash["next"] = [=]{
		return ++(*pnumber);
	};
	
	return funcHash;
}

int main(void)
{
	int ret = 0;
	int initNumber = 0;
	Accumulator add(initNumber);     //函数对象的构造函数传参，就相当于lambda表达式的捕获参数。
	for(int i=11;i<20;++i)
	{
		ret = add(i);
	}
	cout<<"11 + 12 + ... + 19 ="<<ret<<endl;
	
	function<int(int)> sum = accumulator();    //普通闭包调用
	sum(1);
	sum(2);
	ret = sum(3);
	cout<<"1 + 2 + 3 ="<<ret<<endl;
	
	auto plus = adder(0);            //无状态、无变量的闭包调用
	for(int i=1;i<10;++i)
	{
		ret = plus(i);
		plus = adder(ret);
	}
	cout<<"1 + 2 + ... + 9 ="<<ret<<endl;
	
	/*可调用对象square即为一个闭包。闭包square中包含局部变量exponent与函数power()，
	 *在接下来对square的使用，直接调用power()函数和变量exponent。
	 */
	int exponent = 2;
	auto square = std::bind(power,placeholders::_1,exponent);
	cout<<"5 * 5 ="<<square(5)<<endl;
	cout<<"6^2 ="<<square(6)<<endl;
	
	exponent = 3;
	function<int(int)> cube = std::bind(power,placeholders::_1,exponent);
	cout<<"5 * 5 *5 ="<<cube(5)<<endl;
	cout<<"6^3 ="<<cube(6)<<endl;
	
	auto foo = once();
	foo();
	
	function<void(void)> bar = once();
	foo();
	
	auto fun = fibonacci();
	for(int i=0;i<10;++i)
	{
		cout<<fun()<<" ";
	}
	cout<<endl;
	
	auto counterA = counter(10);
	cout<<"counterA next: "<<counterA["next"]()<<endl;
	cout<<"counterA next: "<<counterA["next"]()<<endl;
	
	cout<<"counterA reset: "<<counterA["reset"]()<<endl;
	cout<<"counterA next: "<<counterA["next"]()<<endl;
	
	return 0;
}