#ifndef _TOOLS_H_
#define _TOOLS_H_

#include "libMath_global.h"

/*用c方式去编译c++文件，还要注意重载函数。c方式编译的c++文件决定不能出现重载函数。
 *在c语言中肯定不能出现同名函数，不然编译器怎么知道它要调用的是哪一个。
 */
LIB_MATH_EXPORT int absolute(int n);
LIB_MATH_EXPORT double absolute(double n);

/*C++编译方式会将重载函数名结合参数形成唯一的函数名。但是c方式编译的可执行文件却并非如此，
 *函数名经过编译后的符号还是之前的函数名。所以当C语言去调用C++库，如果编译制作C++库时没有
 *添加extern "C"关键字，还是使其采用c++方式编译，就会出现找不到调用函数的现象。
 */
LIB_MATH_EXPORT bool toString(int n,char* str);
LIB_MATH_EXPORT bool toString(double n,char* str);

/*C语言要调用C++编写的代码，涉及到的可能有C程序调用c++的普通函数、C程序调用c++的重载函数、
 *C程序调用C++的成员函数(包括虚函数)。C程序自然是采用C的方式去编译的，即是采用gcc编译器，
 *然而C++是采用C++方式编译，所以要使用extern "C"关键字，强制将C++代码以C的方式去编译。
 */
LIB_MATH_EXPORT int min(int x,int y);
LIB_MATH_EXPORT int min(int x,int y,int z);
LIB_MATH_EXPORT double min(double x,double y);
LIB_MATH_EXPORT double min(double x,double y,double z);

/*在extern "C" {}中是不允许出现重载函数的，因为C编译方式下的程序并不支持重载函数的，
 *所以需要对重载函数进行接口封装。使用extern "C"是要告诉编译器按照C的方式来编译封装接口，
 *接口里面的函数实现还是按照C++的语法和C++方式去编译。
 */
LIB_MATH_EXPORT int max(int x,int y);
LIB_MATH_EXPORT int max(int x,int y,int z);
LIB_MATH_EXPORT double max(double x,double y);
LIB_MATH_EXPORT double max(double x,double y,double z);

#endif // _TOOLS_H_