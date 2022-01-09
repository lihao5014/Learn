/*C++本身已经具备了常量表达式的概念，比如1+2, 3*4这种表达式总是会产生相同的结果并且没有任何副作用。
 *如果编译器能够在编译时就把这些表达式直接优化并植入到程序运行时，将能增加程序的性能。
 */

/*1.constexpr和const的区别：
 *（1）在C++11之前只有const关键字，从功能上来说const关键字有双重语义：变量只读，修饰常量。
 *（2）在C++11中添加了一个新的constexpr关键字，用来修饰常量表达式的。所谓常量表达式指的就是由多个常量组成，
 *     并且在编译过程中就得到计算结果的表达式。
 *（3）constexpr和const都代表可读，但const只表示read only的语义，只保证了运行时不可以被修改，
 *     但它修饰的仍然有可能是个动态变量，而constexpr修饰的才是真正的常量，它会在编译期间就会被计算出来，
 *     整个运行过程中都不可以被改变。constexpr可以用于修饰函数，该函数的返回值会尽可能在编译期间被计算出来，
 *     并被当作一个常量。但是如果编译期间此函数不能被计算出来，那它就会当作一个普通函数被处理。
 *（4）constexpr声明的函数可以在编译时执行，生成一个值，用在需要常量表达式的地方，如定义数组时指定大小、
 *     作为初始化模板的整形参数等。C++11中的constexpr函数只能包含一个表达式，但C++14标准放松了这些限制，
 *     支持条件语句（if/switch）、循环语句（for/while/do/范围for）和函数递归。
 */

/*2.非常量表达式与常量表达式的计算时机：
 *  C++程序从编写完毕到执行分为4个阶段：预处理、 编译、汇编和链接，得到可执行程序之后就可以运行了。
 *  常量表达式和非常量表达式的计算时机不同，非常量表达式只能在程序运行阶段计算出结果，但常量表达式的
 *  计算往往发生在程序的编译阶段，这可以极大提高程序的执行效率，因为表达式只需要在编译阶段计算一次，
 *  节省了每次程序运行时都需要计算一次的时间。
 */

/*在C++11中添加了constexpr关键字之后，就可以在程序中使用它来告诉编译器一个表达式是不是常量表达式，
 *以提高程序的执行效率。使用中建议将const和constexpr的功能区分开，即凡是表达“只读”语义的场景都使用const，
 *表达“常量”语义的场景都使用constexpr。在定义常量时const和constexpr是等价的，都可以在程序的编译阶段计算出结果。
 */

/*3.常量表达式函数：
 *为了提高C++程序的执行效率，可以将程序中值不需要发生变化的变量定义为常量，也可以使用constexpr修饰函数的返回值，
 *这种函数被称作常量表达式函数。常量表达式函数主要包括以下几种：普通函数、类成员函数、类的构造函数、模板函数。
 */

/*4.constexpr函数要求：
 *常量表达式函数的返回类型及所有形参都得是字面值类型，且在C++11标准中常量表达式函数体必须有且只有一条return语句。
 *一般来说基本数据类型、引用和指针都属于字面值类型，但自定义类、STL容器、string不属于字面值，不能定义为constexpr。
 */

/*与普通函数不一样，内联函数和constexpr函数可以在程序中多次定义。毕竟编译器要想展开函数仅有函数声明是不够的，
 *还需要函数的定义。不过对于某个给定的内联函数或者constexpr函数来说，它的多个定义必须完全一致。基于这个原因，
 *内联函数和constexpr函数通常定义在头文件中。
 */

#include <iostream>

using namespace std;

#define _ERROR_
#undef _ERROR_

#define _CHANGE_WAY_
// #undef _CHANGE_WAY_

#define SIZE 10

#define PrintMacroHelper(x) #x
#define PrintMacro(x) #x " = " PrintMacroHelper(x)

/*const关键字修饰参数num，表示此变量是只读的，但不是常量。使用只读变量num定义一个数组，
 *编译器是会报错的，提示num不可用作为常量来使用。
 */
void fun(const int num)
{
#ifdef _ERROR_
	int arr[num] = {0};    //编译会报错，因为num是一个只读变量，不是常量。定义数组时大小不能是变量。
#else
	int arr[SIZE] = {0};   //SIZE宏会在预处理时被替换为常量10，所以可以用于指定数组大小。
	#pragma message(PrintMacro(SIZE))     //在编译器打印出宏值
#endif

	const int count = 10;      //count是一个常量，因此可以使用这个常量来定义一个静态数组。
#ifndef _CHANGE_WAY_
	static_assert(count != 10,"count =10");
#else
	int array[count] = {0};    //cl编译器中不能使用变量作为数组大小，但g++编译器中可以使用变量作为数组大小。
#endif
	
	int a = 20;
	const int &b = a;       //变量只读并不等价于常量，二者是两个概念不能混为一谈。
	// b = 30;              //因为b是一个常量引用，所以不能通过常量引用b修改值。
	a = 40;
	cout<<"b ="<<b<<endl;   //引用b是只读的，但是并不能保证它的值是不可改变的，也就是说它不是常量。
}

/*（1）const修饰的变量并不一定都是常量。在函数传参时，const修饰的变量就是不是常量，而是只读变量。
 *     const关键字的作用有两种：声明变量只读，定义常量。
 *（2）constexpr修饰的变量就一定是常量。constexpr关键字的作用有两种：定义常量，声明常量表达式函数。
 */
int foo(const int num)
{
	return num + 1;
}

constexpr int bar(int num)
{
	return num * 2;
}

//constexpr函数体中可以包含静态断言、类型别名、using声明等其他语句，只要这些语句在运行时不执行任何操作就行。
constexpr int qux()
{
	static_assert(6 > 5,"6 < 5");
	typedef double (*pf)(double x,double y);
	using uint = unsigned int;
	
	constexpr uint ret = 10u;
	return ret;
}

/*对于C++内置类型的数据，可以直接用constexpr修饰，但如果是自定义的数据类型，直接用constexpr修饰是不行的。
 *即定义struct或class时，添加constexpr关键字修饰是无效的。
 */
/* constexpr */ struct Test
{
    int id;
    int num;
};

int main(void)
{
	fun(10);
	
	const int n = foo(15);  //n不是常量表达式。n的值只有在运行时才会获取。
	const int m = 25;       //是一个常量表达式。且完全等价于constexpr int m = 25。
	const int k = m + 1;    //常量表达式。此时完全等价于constexpr int k = m + 1。
#ifndef _CHANGE_WAY_
	static_assert(k != 26,"k =26");
#else
	int arr1[k] = {0};   //因为没有办法在编译期打印常量的值，所以用定义数组的方式来判断一个const变量是不是常量。
#endif

	constexpr int i = 11;       //是一个常量表达式。且完全等价于const int i = 11。
	constexpr int j = i + 5;    //常量表达式。此时完全等价于const int k = j = i + 5。
#ifndef _CHANGE_WAY_
	static_assert(j != 16,"j =16");     //constexpr变量就一定是常量。
#else
	int arr2[j] = {0};   //因为没有办法在编译期打印常量的值，所以用定义数组的方式来判断一个变量是不是常量。
#endif

	int a = 21;
	bar(a);      //普通函数
	
	/*执行该初始化任务时，编译器把对constexpr函数的调用替换成其结果值。
	 *为了能在编译过程中随时展开，constexpr函数被隐式地指定为内联函数。
	 */
	constexpr int b = bar(m);    //编译期间就会被计算出来
#ifndef _CHANGE_WAY_
	static_assert(b != m * 2,"b =25 * 2");
#else
	int arr3[b] = {0};
	cout<<"arr3 len ="<<sizeof(arr3)/sizeof(arr3[0])<<endl;
#endif

	enum {
		DUMMY = qux()
	};
	cout<<"DUMMY ="<<DUMMY<<endl;
	
	constexpr Test test{11,22};
    // t.num += 100;              //对象test是一个常量，因此它的成员也是常量，常量是不能被修改的。
    cout << "id: " << test.id << ", num: " << test.num << endl;
	
	return 0;
}