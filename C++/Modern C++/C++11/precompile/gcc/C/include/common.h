/*1.gcc中使用预编译头文件：
 *（1）Visual C++具有很高编译效率的原因是其支持“预编译头文件”（Pre-Compiled Header、PCH）。
 *     当使用Visual C++创建项目时，常常会建立stdafx.cpp和stdafx.h文件。其中stdafx.h包含了
 *     项目中所有C/C++源文件所要用到的一些系统或标准库头文件，而stdafx.cpp只包含了stdafx.h。
 *     这两个文件便是用来建立预编译头文件”项目名.pch”的。预编译头是将项目中普遍使用的头文件
 *     内容的词法分析、语法分析等结果缓存在一个特定格式的二进制文件中。当然编译C/C++源文件时，
 *     就不必从头对这些头文件进行词法-语法分析，而只需要利用那些已经完成词法-语法分析的结果
 *     就可以了。
 *（2）事实上gcc从3.4.x版和4.x版开始，也支持了预编译头文件这种提高编译效率的机制。只是由于gcc
 *     没有简单的自动项目管理工具支持这项功能，因而许多人还不知道gcc的预编译头功能。
 *（3）gcc手册中建议使用make管理预编译头文件，还指出C语言的预编译头文件和C++语言的预编译头文件
 *     是不一样的。项目中只有C或C++一种语言的源文件时，只需建立一个预编译头文件。如果项目既包含
 *     C语言源文件，也包含C++语言源文件，就需要为两种语言分别维护一个预编译头文件。
 */

/*2.gch预编译头文件：
 *（1）gch文件是gcc编译器将.h头文件当作.cpp源文件进行编译之后出现的结果。在头文件进行编译后
 *     就会在文件夹中看到一个“文件名.h.gch”的文件。如果在再次对.h.gch文件进行编译的时候就会
 *     将gch文件当作cpp源文件一样对待。这是一种预编译，可以提高编译的速度，但是gch文件并不会
 *     随着你对头文件的修改而修改，所以在对头文件进行修改的时候，就会出现一些莫名其妙的错误，
 *     因为在再次编译的时候使用的是你之前预编译的中间文件.gch文件。
 *（2）gch预编译头的作用就是将头文件预编译为二进制代码后，以供后续编译使用。当多个源文件都包含
 *     同一个头文件时，正常流程是将其在每个源文件中都解析一遍，造成了重复解析头文件的资源浪费。
 *     使用gch将头文件作预编译头形成中间处理的二进制代码，然后再包含进源文件中。可以大大的提升
 *     编译的速度。
 */

/*3.gch预编译头的使用步骤：
 *（1）先使用include-what-you-use这个开源工具，去除重复包含的头文件。前置声明替换，也是一种优化。
 *（2）分析路径下头文件的包含频率。
 *（3）筛选包含频率高但是改动频率小的头文件，放在新的inc.h文件中。
 *（4）剔除cpp文件包含的上一步的头文件，并在cpp中首行插入#include "inc.h"。
 *（5）修改Makefile，修改依赖关系，编译时先对inc.h进行编译，生成最新的inc.h.gch。
 *（6）gcc编译时可以加入-Winvalid-pch，当inc.h.gch不可用时编译报错。
 */

#ifndef _COMMON_H_
#define _COMMON_H_

#include <stdio.h>
#include "vector2d.h"
#include "vector3d.h"

#endif  //_COMMON_H_