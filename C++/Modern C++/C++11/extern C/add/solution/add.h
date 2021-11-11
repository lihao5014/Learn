#ifndef _ADD_H
#define _ADD_H

/*extern "C"用于告诉C++编译器add()函数是一个C语言接口。extern "C"是C++中的关键字，
 *只对g++编译器有效，而在gcc编译器中会直接报错，编译不通过。
 */
extern "C" int add(int x,int y);   //虽然添加了extern "C"关键字的C接口可以被C++正常调用，但却不能被C代码调用。

#endif