/*1.gcc中使用预编译头文件：
 *（1）vc的预编译头功能很强大，可以极大的提高编译效率，其实gcc也支持这项功能，设置更为简单。
 *     把所有外部文件都放到一个头文件里（比如predefine.h），所有引用外部文件的cpp文件都包含
 *     这个预编译头文件就可以了。
 *（2）预编译头文件不能包含在其他的头文件里面，只能被源文件包含。C++编码规范也要求尽量不要在
 *     头文件里包含其它的头文件，而是使用前置声明的方式，把需要的头文件放到源文件中。
 *（3）所谓预编译头就是把头文件事先编译成一种二进制的中间格式，供后续的编译过程使用。gcc编译
 *     *.h头文件后的中间文件是*.gch。
 *（4）g++ xx.h命令把.h头文件当成.cpp源文件一样来编译后，会在同个目录里生成一个名叫xx.h.gch的文件。
 *     如果需要控制编译细节，比如宏定义之类，还可以加上其它编译选项。GCC编译器在查找一个.h文件之前，
 *     会自动查找其目录里有没有对应的.gch文件。如果有且可用，则用之；如果没有才会用到真正的.h头文件。
 *     “可用”是指这个.gch格式要正确，版本要兼容，而且编译两者要用同样的选项。如果.gch预编译头不可用，
 *     编译器会给出一条警告：“这个预编译头不能用，只好用原有的.h头文件了”。当然要先打开-Winvalid-pch
 *     选项才行，其默认是关闭的。
 */

/*2.gch预编译头文件的特性：
 *（1）生成的是被解析完成的二进制中间件。
 *（2）编译*.gch文件时，所用到的*.h文件必须在当前目录下，因为编译头文件时，不会过环境变量或者
 *     -I进行路径搜索。
 *（3）*.gch文件和所对应的*.h没有必要的联系，也就是说对*.h文件进行修改时*.gch文件不会自动修改，
 *     需要重新编译。因此通常情况下，不轻易改变的头文件才会编译成中间件。
 */

#ifndef _PRE_DEFINE_H_
#define _PRE_DEFINE_H_

#include "test.h"
#include "matrix.h"

#endif  //_PRE_DEFINE_H_