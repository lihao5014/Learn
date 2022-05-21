/*1.预编译头文件（precompiled headers）:
 *（1）预编译头文件将不经常改动的代码编译成二进制文件，在之后每次编译的时候，可以直接调用预编译头文件
 *     的二进制文件，以实现加快编译速度。
 *（2）预编译头是某些编译器支持的性能功能，用于编译稳定的代码体，并将代码的编译状态存储在二进制文件中。
 *     在后续编译期间，编译器将加载存储的状态，并继续编译指定的文件。由于不需要重新编译稳定的代码，
 *     因此每个后续编译都更快。
 *（3）由于C文件的预编译头文件可能不包含C++代码，因此预编译的头文件需要将C include和C++ include分开。
 */
 
/*2.Qt中使用预编译头文件：
 *（1）要使Qt项目使用预编译头，只需在项目文件中定义PRECOMPILED_HEADER变量。qmake将处理其余部分，
 *     以确保创建和使用预编译头。不需要在HEADERS中包含预编译的头文件，因为如果配置支持预编译头，
 *     则qmake会这样做。默认情况下，针对Windows的msvc和g++规范启用precompile_header。
 *（2）precompile_header选项可以在使用预编译头时，触发项目文件中的条件块以添加设置。 
 *（3）要对msvc nmake目标上的C文件也使用预编译头，请将precompile_header_c添加到CONFIG变量中。
 *     如果头文件也用于C++，并且包含C++关键字/包含，请使用#ifdef __cplusplus括起来。
 *（4）precompile.h中头文件可按需添加，原则是添加各个头文件中重复包含较多的公用头文件；
 *     如果precompile.h中包含头文件有内容修改，需重新构建。
 */

#ifndef _STABLE_H_
#define _STABLE_H_

#include <iostream>

#include "dataacquirerfactory.h"

#endif  //_STABLE_H_