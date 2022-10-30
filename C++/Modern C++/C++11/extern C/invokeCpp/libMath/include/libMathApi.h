/*1.C与C++语言的相互调用：
 *（1）C++是C的超集，C++兼容绝大部分C语言的语法，C/C++天然可以混合编译。但需要注意的一点是C与C++在编译过程中，
 *     对于函数名的处理不相同。C语言使用简单函数名，即不考虑函数的参数类型和个数，而C++函数将参数类型列表当作
 *     函数名的一部分。
 *（2）C++保留了一部分过程式语言特点，因此可以定义不属于任何类的全局变量和函数。但是C++为面向对象语言，
 *     支持函数的重载，C++对全局函数处理方式明显与C不同。extern "C" {}目的是为了让C++正确使用C语言的代码，
 *     加上extern "C"之后，会指示编译器对这部分代码按照C语言进行编译，而不是C++语言进行编译。C++支持多态，
 *     因此编译过程中会将函数的参数类型合入函数名符号中，而不仅仅是函数名。
 *（3）C++调用一个C语言编写的动态库，当#include包含描述动态库中函数的头文件时，应该将对应的头文件放置在
       extern "C" {}格式的{}大括号中。
 *（4）C语言中引用C++中的全局函数时，C++的头文件需要加extern "C"，而C文件中不能用extern "C"。因为C语言中
 *     只有extern关键字，而没有extern "C"。extern "C"是C++语言的关键字，C语言编译器并不认识。
 */
 
/*2.C与C++语言的编译方式：
 *（1）C++能够兼容C语言的编译方式，但是C++编译器会默认以C++的方式来编译C代码。而C编译器却不能编译C++代码，
 *     只能通过动态库的方式来调用C++实现的功能。C语言能以源码的方式供C++程序调用，但是C++却只能以库的方式
 *     供C语言调用。通过库是实现不同程序设计语言间相互调用的通用方式。
 *（2）一般.cpp文件是采用g++去编译，.c文件是采用gcc编译，然而这不是绝对的。gcc和g++都可以编译.c文件，
 *     也都可以编译.cpp文件。g++和gcc是通过后缀名来辨别是c程序还是c++程序的。这一点与Linux辨别文件的
 *     方式不同，Linux是通过文件信息头辨别文件的。
 *（3）在gcc看来.c文件会以c方式去编译，.cpp文件则是以c++的方式去编译。注意gcc不会主动去链接c++用到库stdc++，
 *     所以用gcc编译cpp文件时需要手动指定链接选项-lstdc++。而对于g++不管是.c还是.cpp文件都是以c++方式去编译。
 *（4）并不是说__cpluscplus是g++编译器才会定义的宏，确切的说是只有以c++编译的方式去编译文件的宏才会定义的宏，
 *     这样说来gcc编译.cpp文件、g++编译.c/.cpp文件，这个__cplusplus都会被编译器定义。
 *（5）C方式编译和C++方式编译，其差异就在于符号表标识符。同一个函数名，在C方式编译的其函数名跟编译前的函数一致，
 *     C++方式编译的则是以函数名结合参数作为编译后的函数名。要确保文件以.c方式编译，可以利用__cplusplus这个宏在
 *     C++编译的方式才会定义的宏，再结合extern "C"用法。
 *（6）对于一份.c文件，采用gcc编译时候没有定义__cplusplus，宏判断不起作用且自身用c语言的方式编译。采用g++编译定义
 *     了_cplusplus，经过宏判断所以还是会以c语言的方式编译。注意extern “C”是g++才具有的关键字gcc并没有，所以如果用
 *      gcc编译而不加以宏判断直接使用extern “C”那么就会出现语法错误。
 */

#ifndef _LIB_MATH_API_H_
#define _LIB_MATH_API_H_

#include <stdbool.h>
#include "mymath.h"
#include "libMath_global.h"

//__cplusplus为C++中自定义的宏，extern表明变量和函数是全局性的。
#ifdef __cplusplus
extern "C" {
#endif

//使用C语言中的struct结构体对C++中的class类进行包装。
typedef struct
{
	void* m_unused;
}Point_t,*PointPtr;

LIB_MATH_EXPORT PointPtr point_create(double x,double y);
LIB_MATH_EXPORT void point_destroy(PointPtr* ppointPtr);

LIB_MATH_EXPORT void point_setX(PointPtr pointPtr,double x);
LIB_MATH_EXPORT double point_getX(const PointPtr pointPtr);

LIB_MATH_EXPORT void point_setY(PointPtr pointPtr,double y);
LIB_MATH_EXPORT double point_getY(const PointPtr pointPtr);

LIB_MATH_EXPORT void point_display(const PointPtr pointPtr);

LIB_MATH_EXPORT void point_add(const PointPtr point1,const PointPtr point2,PointPtr pointRet);
LIB_MATH_EXPORT void point_sub(const PointPtr point1,const PointPtr point2,PointPtr pointRet);

//用C方式去编译的C++文件决定不能出现重载函数。
LIB_MATH_EXPORT int abs_int(int n);
LIB_MATH_EXPORT double abs_float(double n);

LIB_MATH_EXPORT bool intToString(int n,char* str);
LIB_MATH_EXPORT bool floatToString(double n,char* str);

LIB_MATH_EXPORT int min_2i(int x,int y);
LIB_MATH_EXPORT int min_3int(int x,int y,int z);
LIB_MATH_EXPORT double min_2f(double x,double y);
LIB_MATH_EXPORT double min_3float(double x,double y,double z);

LIB_MATH_EXPORT int max_2i(int x,int y);
LIB_MATH_EXPORT int max_3int(int x,int y,int z);
LIB_MATH_EXPORT double max_2f(double x,double y);
LIB_MATH_EXPORT double max_3float(double x,double y,double z);

#ifdef __cplusplus
}
#endif


#endif  // _LIB_MATH_API_H_