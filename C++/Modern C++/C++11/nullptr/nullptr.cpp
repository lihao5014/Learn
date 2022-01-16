//野指针：没有明确指向的指针，操作也这种指针极可能导致程序发生异常。

/*1.C++11引入nullptr空指针的原因：
 *（1）在C++程序开发中，为了提高程序的健壮性，一般会在定义指针的同时完成初始化操作，
 *     或在指针的指向尚未明确的情况下，都会给指针初始化为NULL，避免产生野指针。
 *（2）C++头文件中NULL都是定义为#define NULL 0，因此本质上NULL的类型是int，使用NULL来表示空指针是非常不合适的行为，
 *     于是C++11重新定义了一个不是int类型且适用于空指针的关键词。
 *（3）nullptr是c++11用来表示空指针新引入的常量值，在c++中如果表示空指针语义时建议使用nullptr而不要使用NULL，
 *     因为NULL本质上是个int型的0，而不是个指针。使用nullptr可以很完美的解决的函数重载问题。
 *（4）关键词nullptr代表指针字面量。它是std::nullptr_t类型的纯右值。存在从nullptr到任何指针类型及任何成员指针类型的隐式转换。
 *     同样的转换对于任何空指针常量也存在，空指针常量包括std::nullptr_t的值，以及宏NULL、nullptr、指针字面量。
 *（5）C++不允许直接将void*隐式转换到其他类型。没有了void*隐式转换的C++只好将NULL定义为0。而这依然会产生新的问题，
 *     将NULL定义成0将导致C++中重载特性发生混乱。
 */

/*2.C++98/03标准中将一个指针初始化为空指针的2种方式:
 *（1）char *ptr = 0;
 *（2）char *ptr = NULL;
 */

/*3.C++中NULL宏的定义:
 *    #ifndef NULL
 *        #ifdef __cplusplus
 *            #define NULL 0
 *        #else
 *            #define NULL ((void *)0)
 *        #endif
 *    #endif
 *
 *（1）如果源码是C++程序NULL就是0，如果是C程序NULL表示(void*)0。因为C++中void*类型无法隐式转换为其他类型的指针，
 *     此时使用0代替(void*)0用于解决空指针的问题。这个0表示的就是虚拟地址空间中的0x00000000地址，该地址是只读的。
 *（2）C++中将NULL定义为字面常量0，并不能保证在所有场景下都能很好的工作，比如函数重载时，NULL和0无法区分。
 *     出于兼容性的考虑，C++11标准并没有对NULL的宏定义做任何修改，而是另其炉灶，引入了一个新的关键字nullptr。
 *     nullptr专用于初始化空类型指针，不同类型的指针变量都可以使用nullptr来初始化。
 *（3）C++编译器会将nullptr隐式转换成int*、char*和double*等指针类型。使用nullptr可以很完美的解决的函数重载问题。
 *（4）nullptr无法隐式转换为整形，但是可以隐式匹配指针类型。在C++11标准下，相比NULL和0，使用nullptr初始化空指针
 *     可以令我们编写的程序更加健壮。
 *（5）C++11引入nullptr关键字，专门用来区分空指针和0。而nullptr的类型为nullptr_t，能够隐式的转换为任何指针或成员指针的类型，
 *     也能和他们进行相等或者不等的比较。
 */

#include <iostream>

using std::cout;
using std::endl;

void fun(int *ptr)
{
	cout<<"void fun(int *ptr)"<<endl;
}

void fun(int n)     //C++中NULL空指针，会当作0对待。
{
	cout<<"void fun(int n)"<<endl;
}

int main(int argc,char* argv[])
{
	cout<<"C++ version: "<<__cplusplus<<endl;
	
	//c语言中将NULL定义为空指针，而在c++中直接定义为0。因为C++是强类型的，void*是不能隐式转换成其他指针类型的。
	if(NULL == 0)
	{
		cout<<"NULL == 0"<<endl;
	}
	
	//nullptr是为了解决原来C++中NULL的二义性问题而引进的一种新的类型，因为NULL实际上代表的是0。
	char* p = nullptr;   //C++编译器会将nullptr隐式转换成char*类型指针。
	char* q = NULL;      //如果C++编译器尝试把NULL定义为(void*)0， 那么这里就会违背void*类型不能隐式转换到其他类型的原则。
	if(p == q)
	{
		cout<<"p == q"<<endl;  //p == q，说明p和q都是空指针。
	}
	else
	{
		cout<<"p != q"<<endl;
	}
	
	/*（1）cl编译器：想调用指针传递版本的重载函数void fun(int *ptr)，但最终调用的却是值传递版本的重载函数void fun(int n)。
	 *（2）g++编译器：编译失败，fun(NULL)会产生函数调用二义性错误。
	 */
	fun(NULL);
	
	fun(100);       //调用值传递版本的重载函数void fun(int n)。
	fun(nullptr);   //C++编译器会将nullptr隐式转换成int*类型指针，从而调用指针传递版本的重载函数void fun(int *ptr)。
	
	std::nullptr_t null;    //使用nullptr_t定义的任何变量都具有nullptr一样的行为。
	fun(null);              //nullptr的类型为std::nullptr_t。
	
	return 0;
}