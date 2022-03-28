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

/*7.std::bind绑定一个引用参数:
 *（1）默认情况下std::bind()的那些不是占位符的参数，是被直接拷贝到bind()返回的可调用对象中。
 *     但是与lambda类似，有时希望绑定的参数以引用的方式传递，或是要绑定参数的类型无法拷贝。
 *     这是就必须使用标准库提供的std::ref()函数。
 *（2）std::ref()只是尝试模拟引用传递，并不能真正变成引用，在非模板状况下ref()根本无法实现引用传递，
 *     只有模板自动推导类型时，std::ref()能用包装类型reference_wrapper来代替本来会被识别的值类型，
 *     而reference_wrapper能隐式转换为被引用的值的引用类型。
 *（3）C++本身有引用类型&，而又在C++11中引入了std::ref和std::cref，主要是考虑std::bind()在使用时，
 *     是对参数直接拷贝，而不是引用。
 *（4）C++中&是类型说明符，std::ref()是一个函数，返回std::reference_wrapper。
 */

#include <iostream>
#include <sstream>   //ostringstream
#include <string>
#include <vector>
#include <functional>    //function,bind(),ref(),std::plus,std::minus,std::multiplies,std::divides
#include <algorithm>
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

//引入std::ref主要是考虑函数式编程（如std::bind）在使用时，是对参数直接拷贝，而不是引用。
void foo(int& x,int& y,const int& z)
{
	cout<<"in foo(): "<<x<<" "<<y<<" "<<z<<endl;
	++x;
	++y;
}

ostream& print(ostream& os,const string& str,char ch)
{
	os<<str<<ch;
	return os;
}

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

	/*（1）定义成员函数指针时，必须指定类的作用域。即必须说明成员函数指针指向，那个类中的那个成员函数。
	 *（2）因为类中的非静态成员函数是对象独有的，所以必须对象来调用成员函数指针。
	 */
	Compare compare;
	bool (Compare::*pfun)(double,double) = &Compare::less;
	cout<<"5 < 8 = "<<(compare.*pfun)(5,8)<<endl;
	
	pfun = &Compare::greater;
	cout<<"8 > 5 = "<<(&compare->*pfun)(8,5)<<endl;
	
	auto isNegative = std::bind(&Compare::less,&compare,_1,0);
	function<bool(double)> greaterThan_5 = bind(&Compare::greater,&compare,_1,5);
	
	cout<<"isNegative(-3.14) ="<<isNegative(-3.14)<<endl;
	cout<<"greaterThan_5(9.8) ="<<greaterThan_5(9.8)<<endl<<endl;
	
	//std::bind默认使用的是参数的拷贝而不是引用。如果需要使用引用传参，加上std::ref即可。
	int x = 1,y = 2,z = 3;
	function<void()> bar = bind(foo,x,std::ref(y),std::cref(z));
	
	x = 10;
	y = 11;
	z = 12;
	cout<<"before bar(): "<<x<<" "<<y<<" "<<z<<endl;
	bar();
	cout<<"after bar(): "<<x<<" "<<y<<" "<<z<<endl;
	
	char ch = ' ';
	ostringstream os;
	vector<string> words{"hello","world","this","is","c++11"};
	for_each(words.begin(),words.end(),[&os,ch](const string& str){os<<str<<ch;});
	cout<<os.str()<<endl;
	
	/*若希望传递给bind一个对象，而不拷贝它，就必须使用标准库提供的std::ref()函数。
	 *因为ostream不能拷贝，所以传递给bind()函数时，只能使用引用传递。
	 */
	ostringstream os1;
	for_each(words.begin(),words.end(),bind(print,std::ref(os1),placeholders::_1,ch));
	cout<<os1.str()<<endl<<endl;
	
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