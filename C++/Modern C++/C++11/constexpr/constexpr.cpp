/*1.constexpr修饰函数必须满足的4个条件：（constexpr并非可以修改任意函数的返回值，使其成为常量表达式函数）
 *（1）整个函数的函数体中，除了可以包含using指令、typedef语句以及static_assert断言外，
 *     只能包含一条return返回语句。常量表达式函数的return语句中不能包含赋值的操作。
 *     constexpr修饰函数时函数本身是支持递归的。
 *（2）函数必须有返回值，即函数的返回值类型不能是void。这是因为返回值为空的函数
 *     根本无法获得一个常量。
 *（3）函数在使用之前，必须有对应的定义语句。函数的使用分为“声明”和“定义”两部分，
 *     普通的函数调用只需要提前写好该函数的声明部分即可，函数的定义部分可以放在
 *     调用位置之后甚至其它文件中。但常量表达式函数在使用前，必须要有该函数的定义。
 *（4）函数return返回的表达式必须是常量表达式。常量表达式函数的返回值必须是常量
 *     表达式的原因很简单，如果想在程序编译阶段获得某个函数返回的常量，则该函数
 *     的return语句中就不能包含程序运行阶段才能确定值的变量。
 */

/*constexpr可用于修饰函数，而类中的成员方法完全可以看做是“位于类这个命名空间中的函数”，
 *所以constexpr也可以修饰类中的成员函数，只不过此函数必须满足constexpr修饰普通函数的4个条件。
 */

/*2.constexpr修饰构造函数：
 *（1）对于C++内置类型的数据，可以直接用constexpr修饰，但如果是struct/class这样的自定义数据类型，
 *     直接用constexpr修饰是不行的。
 *（2）如果想自定义一个可产生常量的类型时，正确的做法是在该类型的内部添加一个常量构造函数。
 *（3）constexpr修饰类的构造函数时，要求该构造函数的函数体必须为空，且采用初始化列表的方式为
 *     各个成员赋值时，必须使用常量表达式。
 *（4）C++11标准中，不支持用constexpr修饰带有virtual的成员方法。
 */

/*3.constexpr修饰模板函数：
 *C++11语法中，constexpr可以修饰模板函数，但由于模板中类型的不确定性，因此模板函数实例化后的函数
 *是否符合常量表达式函数的要求也是不确定的。C++11标准规定，如果constexpr修饰的模板函数实例化结果
 *不满足常量表达式函数的要求，则constexpr会被自动忽略，即该函数就等同于一个普通函数。
 */

/*4.constexpr和const的区别：
 *（1）constexpr是C++11标准新添加的关键字，在此之前的C++98/03标准中只有const关键字。
 *     而const关键字在使用过程中经常会表现出“常量”和“只读”两种不同的语义。
 *（2）C++11标准中，为了解决const关键字的双重语义问题，保留了const表示“只读”的语义，
 *     而将“常量”的语义划分给了新添加的constexpr关键字。因此C++11标准中，建议将const
 *     和constexpr的功能区分开，即凡是表达“只读”语义的场景都使用const，表达“常量”语义
 *     的场景都使用constexpr。
 *（3）在大部分实际场景中，const和constexpr是可以混用的，它们是完全等价的，都可以在
 *     程序的编译阶段计算出结果。但在某些场景中，必须明确使用constexpr。
 *（4）C++11标准中，const用于为修饰的变量添加“只读”属性；而constexpr关键字则用于指明
 *     其后是一个常量或常量表达式，编译器在编译程序时可以顺带将其结果计算出来，而无需
 *     等到程序运行阶段，这样的优化极大地提高了程序的执行效率。
 */

#include <iostream>
#include <string>
#include <array>
#include <list>

#define _ERROR_
#undef _ERROR_

#define _CHANGE_WAY_
// #undef _CHANGE_WAY_

#ifndef _ERROR_
#define ConstExpr constexpr
#else
#define ConstExpr
#endif

#define ToString(x) #x
#define TOSTRING(x) ToString(x)

using namespace std;

#ifdef _ERROR_
const int square(int num)       //普通函数的返回值，不能再代码编译期就计算出来。
{
	return num * num;
}
#else
constexpr int square(int num)    //常量表达式函数的返回值，可以在代码编译阶段就计算出来。
{
	return num * num;
}	
#endif

#ifdef _ERROR_
struct Person
{
	std::string m_name;    //std::string不是字面值类型，所以不能定义为constexpr
	int m_age;
};
#else
struct Person
{
	const char* m_name;
	int m_age;
};
#endif

#ifndef _CHANGE_WAY_
struct Point
{
	int x;
	int y;
};
#else
class Point
{
public:
	ConstExpr Point():x(0),y(0){}
	ConstExpr Point(int x,int y):x(x),y(y){}
	
	void setX(int x){this->x = x;}
	ConstExpr int getX()const{return x;}
	
	void setY(int y){this->y = y;}
	ConstExpr int getY()const{return y;}
	
	//show()方法必须添加const修饰，否则const Point/constexpr Point常量不能调用non-const方法。
	void show()const{cout<<"("<<x<<","<<y<<")"<<endl;}
private:
	int x;
	int y;
};
#endif

class Sample
{
public:
	constexpr Sample():m_value(0){}
	constexpr Sample(int value):m_value(value){}
	
	void setValue(int value){m_value = value;}
	constexpr int getValue()const{return m_value;}
	
	void display()const{cout<<"m_value ="<<m_value<<endl;}
private:
	int m_value;
};

template <int N>
struct constN
{
	constN(){cout<<"constN: N ="<<N<<endl;}
};

template <int num>
int func()
{
	cout<<"func: num ="<<num<<endl;
	return num;
}

int main(int argc,char** argv)
{
	cout<<"C++ version: "<<endl;

#ifdef _ERROR_
	constexpr std::string str = "constexpr std::string , error";
#else
	constexpr const char* str = "constexpr const char* , right";
#endif
	cout<<"str ="<<str<<endl;

	std::array<int,square(3)> myarray;    //必须使用返回值为constexpr的函数，而不能使用返回值为const的函数。
	cout<<"myarray.size() ="<<myarray.size()<<endl;

#ifdef _ERROR_
	constexpr list<int> seq = {1,2,3,4,5};
#else
	constexpr int seq[] = {1,2,3,4,5};

	enum {
		A = seq[0],
		B = seq[1],
		C = seq[2]
	};
	
	cout<<"A ="<<A<<" , B ="<<B<<" , C ="<<C<<endl;
#endif
	
	constexpr Person person = {"amy",25};
	cout<<"name ="<<person.m_name<<" , age ="<<person.m_age<<endl;

	constexpr Point point = {3,4};
#ifndef _CHANGE_WAY_
	cout<<"x ="<<point.x<<" , y ="<<point.y<<endl;
	constexpr int len = point.x + point.y;
#else
	point.show();
	constexpr int len = point.getX() + point.getY();
#endif
	int arr[len] = {0};        //g++可以使用变量作为数组的大小
	cout<<"arr len ="<<sizeof(arr)/sizeof(arr[0])<<endl;
	
	constexpr Sample sample(10);
	constN<sample.getValue()> out;
	
#ifdef _ERROR_
	sample.setValue(20);     //constexpr常量不能调用非const方法
#endif
	sample.display();
	
	int num = 15;
	Sample sample1(num);
	sample1.display();
#ifdef _ERROR_
	func<sample1.getValue()>();
#endif
	sample1.setValue(25);
	cout<<"sample1.getValue() ="<<sample1.getValue()<<endl;
	
	return 0;
}