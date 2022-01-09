/*1.常量表达式：
 *是由多个（≥1）常量组成的表达式。换句话说，如果表达式中的成员都是常量，那么该表达式就是一个常量表达式。
 *这也意味着，常量表达式一旦确定，其值将无法修改。
 */

/*2.常量表达式的应用场景：
 *指定原始数组长度、枚举值、switch语句中的case标签、模板的值类型参数、static_assert()的测试表达式。
 */

/*3.constexpr验证一个表达式是否为常量表达式：
 *（1）C++程序的执行过程大致要经历编译、链接、运行这3个阶段。常量表达式和非常量表达式的计算时机不同，
 *     非常量表达式只能在程序运行阶段计算出结果；而常量表达式的计算往往发生在程序的编译阶段，这可以极大
 *     提高程序的执行效率，因为表达式只需要在编译阶段计算一次，节省了每次程序运行时都需要计算一次的时间。
 *（2）对于用C++编写的程序，性能往往是永恒的追求。那么在实际开发中，如何才能判定一个表达式是否为常量表达式，
 *     进而获得在编译阶段即可执行的“特权”呢？除了人为判定外，C++11标准还提供有constexpr关键字。
 *（3）constexpr关键字的功能是使指定的常量表达式获得在程序编译阶段计算出结果的能力，而不必等到程序运行阶段。
 *     C++11标准中constexpr可用于修饰普通变量、普通函数、模板函数以及类的成员函数和构造函数。
 *（4）获得在编译阶段计算出结果的能力，并不代表constexpr修饰的表达式一定会在程序编译阶段被执行，
 *     具体的计算时机还是编译器说了算。
 */

/*3.字面值类型（literal type）：
 *（1）常量表达式的值需要在编译时就得到计算，因此对声明constexpr时用到的类型必须有所限制。
 *     因为这些类型一般都比较简单，值也显而易见、容易得到，就把它们称为“字面值类型”。
 *（2）constexpr函数的参数和返回值都必须是常量表达式。而常量表达式的最基本要素就是字面值类型。
 *     字面值类型除了包括算数类型、引用和指针以外，某些类也属于字面值类型，C++11称之为字面值常量类。
 *（3）数据成员都是字面类型的聚合类就是一种字面值类型。字面值的聚合继续具有字面值的编译阶段可以求值特征。
 */

/*4.常用的字面值类型：
 *算术类型、引用和指针都属于字面值类型。大部分自定义类型、IO库、string类型则不属于字面值类型，
 *也就不能被定义成constexpr。
 */

/*constexpr函数的返回类型及所有形参都得是字面值类型。一般来说基本数据类型、引用和指针都属于字面值类型，
 *自定义类、IO库、string不属于字面值，不可以定义为constexpr对象。不过某些特殊的自定义类也是字面值类型。
 *和其它类不同的是，字面值类型的类可能含有constexpr成员函数。这样的成员必须符合constexpr函数的所有要求，
 *它们是隐式的const。
 */

/*5.字面值常量类的要求：（如果一个类不是聚合类，但它符合下述要求，则它也是一个字面值常量类）
 *（1）数据成员都必须是字面值类型。
 *（2）类必须至少含有一个constexpr构造函数。
 *（3）如果一个数据成员含有类内初始值，则内置类型成员的初始值必须是一条常量表达式，或者如果成员属于某种类类型，
 *     则初始值必须使用成员自己的constexpr构造函数。
 *（4）类必须使用析构函数的默认定义。
 */

/*6.constexpr构造函数：
 *（1）尽管构造函数不能是const的，但是字面值常量类的构造函数可以是constexpr函数。事实上一个字面值常量类
 *     必须至少提供一个constexpr构造函数。
 *（2）constexpr构造函数可以声明为=default或=delete的形式。否则它就应该既符合构造函数不能包含返回语句的要求，
 *     又符合constexpr函数能拥有的唯一可执行语句就是返回语句的要求。所以constexpr构造函数体一般来说应该是空的，
 *     或者是一条常量表达式。
 *（3）constexpr构造函数必须初始化所有的数据成员。
 *（4）constexpr构造函数用于生成constexpr对象以及constexpr函数的参数或返回类型。
 */

/*7.聚合类满足条件：（聚合类允许利用者直接访问其成员，并且具有特殊的初始化形式）
 *（1）所有成员都是public的。
 *（2）没有定义构造函数。
 *（3）没有类内初始值。
 *（4）没有基类，也没有虚函数。
 */

//聚合类其实就是一个C结构体。当一个类是聚合类时，就可以使用大括号将每个成员变量初始化。

#include <iostream>
#include <string>
#include <vector>

#define _ERROR_
#undef _ERROR_

#define _CHANGE_WAY
#undef _CHANGE_WAY

using namespace std;

class Date
{
public:
	constexpr Date(int year,int mouth,int day)
		:m_year(year)
		,m_mouth(mouth)
		,m_day(day)
	{
		
	}
	
	void setYear(int year){m_year = year;}
	constexpr int getYear()const{return m_year;}

	void setMouth(int mouth){m_mouth = mouth;}
	constexpr int getMouth()const{return m_mouth;}
	
	void setDay(int day){m_day = day;}
	constexpr int getDay()const{return m_day;}
	
	void display()const
	{
		cout<<m_year<<":"<<m_mouth<<":"<<m_day<<endl;
	}
private:
	int m_year;
	int m_mouth;
	int m_day;
};

int main()
{
	cout<<"C++ version: "<<__cplusplus<<endl;
#ifdef _ERROR_
	constexpr string str = "hello world";     //std::string不是字面值类型，所以不能定义std::string常量。
#else
	constexpr const char* str = "hello world";      //C风格字符串是字面值类型，所以可以定义const char*常量。
#endif
	cout<<"str ="<<str<<endl;

#ifdef _ERROR_
	constexpr vector<int> seq = {1,2,3,4,5};
#else
	constexpr int seq[] = {1,2,3,4,5};
#endif
	switch(seq[0]){
	case seq[0]:
		cout<<"seq[0] ="<<seq[0]<<endl;
		break;
	case seq[1]:
		cout<<"seq[1] ="<<seq[1]<<endl;
		break;
	default:
		cout<<"switch default"<<endl;
	}

	constexpr Date date1(2021,3,29);
	constexpr int size = date1.getDay();
	int arr[size] = {0};
	cout<<"arr[] len ="<<sizeof(arr)/sizeof(int)<<endl;
	
	int year = 2020;
	int mouth = 11;
	int day = 9;
#ifdef _ERROR_
	constexpr Date date2(year,mouth,day);
#else
	Date date2(year,mouth,day);
#endif
	date2.display();
	
	return 0;
}