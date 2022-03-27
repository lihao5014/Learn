/*1.C++中可调用对象的5种类型:
 *（1）普通函数指针。
 *（2）具有operator()成员运算符的类对象。
 *（3）可被转换成函数指针的类对象。
 *（4）类的成员函数指针。
 *（5）lambda表达式。
 */
 
/*C++中可调用对象的虽然都有一个比较统一的操作形式，但是定义方法五花八门，这就导致使用统一的方式保存
 *可调用对象或者传递可调用对象时，会十分繁琐。C++11中提供了function和bind统一了可调用对象的各种操作。
 */

/*2.std::function可调用对象包装器:
 *（1）std::function是一个可调用对象包装器，是一个类模板，可以容纳除了类成员函数指针之外的所有
 *     可调用对象，它可以用统一的方式处理函数、函数对象、函数指针，并允许保存和延迟它们的执行。
 *（2）std::function可以取代函数指针的作用，因为它可以延迟函数的执行，特别适合作为回调函数使用。
 *     它比普通函数指针更加的安全、灵活和便利。
 */

/*3.std::bind函数适配器：
 *（1）可将std::bind函数看作一个通用的函数适配器，它接受一个可调用对象，生成一个新的可调用对象，
 *     来“适应”原对象的参数列表。
 *（2）std::bind将可调用对象与其参数一起进行绑定，绑定后的结果可以使用std::function保存。
 */

/*4.std::bind的两个主要作用：
 *（1）将可调用对象和其参数绑定成一个仿函数。
 *（2）只绑定部分参数，减少可调用对象传入的参数。
 */

/*5.std::bind绑定普通函数：
 *（1）std::bind的第一个参数是函数名，普通函数做实参时，会隐式转换成函数指针。
 *（2）_1表示占位符位于<functional>中，std::placeholders::_1。
 *（3）_2表示占位符位于<functional>中，std::placeholders::_2。
 */

/*6.std::bind绑定一个成员函数:
 *（1）bind绑定类成员函数时，第一个参数表示对象的成员函数的指针，第二个参数表示对象的地址。
 *（2）必须使用&取地址符显示的指定成员函数地址，因为编译器不会将对象的成员函数隐式转换成函数指针，
 *     所以必须在成员函数前添加&。
 *（3）使用对象成员函数的指针时，必须要知道该指针属于哪个对象，因此std::bind的第二个参数为对象的地址。
 */

#include <iostream>
#include <functional>
#include "calculator.h"

using namespace std;

int add(int x,int y)    //可调用对象：普通函数
{
	return x + y;
}

struct subtract         //可调用对象：函数对象类/仿函数
{
	int operator ()(int x,int y)
	{
		return x - y;
	}
};

auto mod = [](int x,int y){return x % y;};   //可调用对象：lambda表达式

class Compare
{
public:
	bool less(double x,double y)
	{
		return x < y; 
	}
	
	bool greater(double x,double y)
	{
		return x > y ? true : false;
	}
};

int main(int argc,char** argv)
{
	/*add，subtract和mod三种可调用对象虽然类型不同，但是共享了同一种调用形式int(int,int)，
	 *即不同类型的可调用对象，可能具有相同的调用形式。使用std::function<int(int,int)>就可以
	 *将这三种可调用对象类型保存起来。
	 */
	using pf = int(int,int);
	function<pf> func_add = add;
	function<pf> func_sub = subtract();
	function<pf> func_mod = mod;
	
	cout<<"func_add(1,2) ="<<func_add(1,2)<<endl;
	cout<<"func_sub(3,1) ="<<func_sub(3,1)<<endl;
	cout<<"func_mod(5,2) ="<<func_mod(5,2)<<endl<<endl;
	
	/*因为C++标准库中已经有了std::multiplies函数对象，所以为了避免标识符重名，
	 *使用自定义的multiplies()函数时，必须加上“::”全局作用域。
	 */
	auto twice = std::bind(::multiplies,placeholders::_1,2);
	
	using placeholders::_1;
	function<data_t(data_t)> half = bind(::divides,_1,2);
	
	cout<<"twice(4) ="<<twice(4)<<endl;
	cout<<"half(6) ="<<half(6)<<endl<<endl;

	Compare compare;
	auto isNegative = std::bind(&Compare::less,&compare,_1,0);
	function<bool(double)> greaterThan_5 = bind(&Compare::greater,&compare,_1,5);
	
	cout<<"isNegative(-3.14) ="<<isNegative(-3.14)<<endl;
	cout<<"greaterThan_5(9.8) ="<<greaterThan_5(9.8)<<endl<<endl;
	
	int ret = calculate(4,5,ADD);
	cout<<"4 + 5 ="<<ret<<endl;
	
	ret = calculate(9,3,SUB);
	cout<<"9 - 3 ="<<ret<<endl;
	
	ret = calculate(7,6,MULT);
	cout<<"7 * 6 ="<<ret<<endl;
	
	ret = calculate(8,2,DIVI);
	cout<<"8 / 2 ="<<ret<<endl;
	
	return 0;
}