/*C++中函数支持重载，而C并不支持。C++为了支持函数重载，它在“生成”函数符号信息时，不能仅仅通过函数名，
 *因为重载函数的函数名都是一样的，所以它还要根据入参，命名空间等信息来确定唯一的函数签名。
 *或者说C++生成函数签名的方式与C不一致，所以即便是函数名一样，对于C和C++来说它们最终的函数签名还是不一样。
 */

/*1.gcc与g++编译C代码的区别：
 *（1）使用gcc编译C语言代码生成的目标文件或库文件，不能与C++代码直接混合编译生成可执行文件。
 *     但通过修改C头文件，在导出函数前添加extern "C"关键字，就能解决C库与C++代码不可以混合编译问题。
 *     而不需要将C代码重新使用g++编译器重新编译一遍。
 *（2）使用g++编译C语言代码生成的目标文件或库文件，可以与C++代码直接混合编译生成可执行文件。
 */

//__cplusplus是一个C++规范规定的预定义宏。所有的现代C++编译器都预先定义了它，而所有C语言编译器则不会。

/*虽然C接口前添加了extern "C"后，就可以被C++代码正常调用了，但由于C语言中并没有extern "C"关键字， 
 *所以添加了extern "C"后的C函数反而不能被C编译器编译通过了。为了能使C代码既能被C++调用，也能被C语言调用，
 *就需要使用__cplusplus宏来控制是否添加extern "C"关键字。如果是C++编译器那么extern "C"部分会被预处理进去，
 *如果是C编译器那么extern "C"部分就会被忽略，这样C代码就可以既用于C++，也用于C了。
 */

/*3.C语言的头文件中看到以下代码段作用：
 *    #ifdef __cplusplus
 *    extern "C" {
 *    #endif
 *    
 *        // all of your legacy C code here
 *    
 *    #ifdef __cplusplus
 *    }
 *    #endif
 *
 *（1）用于C++和C混合编程时，防止C++的编译器在编译C文件的时候出现错误。因为C++可以进行函数名重载，但是C则没有这种功能。
 *（2）extern "C"是告诉C++的编译器不要打这些C函数的主意。不需要进行名字粉碎工作。
 */

/*4.C和C++语言中函数签名的区别：
 *（1）C语言中函数名可以作为唯一ID和代码段的程序建立联系。
 *（2）C++因为重载的关系，函数名符号会被破坏，从而会根据函数的参数不同而重新生成函数符号。
 */

#pragma once

int add(int x,int y);     //没有向C++编译器说明add()是一个C函数，但只要C++的源文件中没有调用该函数，那么编译运行就不会报错。

#ifndef __cplusplus
#pragma message("C language")
int sub(int x,int y);

int mult(int x,int y);
double divi(int x,int y);

#else
#pragma message("C++ language")        //extern "C"既可以修饰单个函数，也可以修饰多个函数。
extern "C" int sub(int x,int y);       //单个声明的链接规范

extern "C" {                           //一组声明的链接规范

int mult(int x,int y);
double divi(int x,int y);

}
#endif   //__STDC__

#ifdef __cplusplus     //__cplusplus是C++编译器预定义宏。
extern "C" {           //extern "C"用于告诉链接器，这是一个C接口，而不是C++接口。
#endif

double max(double x,double y);
double min(double x,double y);

#ifdef __cplusplus
}
#endif
