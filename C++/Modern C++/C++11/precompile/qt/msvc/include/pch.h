﻿/*1.预编译头技术：
 *（1）预编译头就是把一个工程中的那一部分代码，预先编译好放在一个文件里（通常是以.pch为扩展名），
 *     这个文件就称为预编译头文件。这些预先编译好的代码可以是任何的C/C++代码，甚至是inline的函数，
 *     但是必须是稳定的，在工程开发的过程中不会被经常改变。如果这些代码被修改，则需要重新编译生成
 *     预编译头文件。注意预编译头文件通常很大且生成预编译头文件是很耗时间的。需要及时清理那些没有
 *     用的预编译头文件。
 *（2）现在的编译器都有Time stamp时间戳的功能，编译器在编译整个工程的时候，它只会编译那些经过修改的文件，
 *     而不会去编译那些从上次编译过，到现在没有被修改过的文件。那么为什么还要预编译头文件，是因为编译器
 *     是以文件为单位编译的，一个文件经过修改后，会重新编译整个文件，当然在这个文件里包含的所有头文件中
 *     的东西都要重新处理一遍。VC的预编译头文件保存的正是这部分信息。以避免每次都要重新处理这些头文件。
 *（3）预编译头文件的作用当然就是提高便宜速度了，有了它你没有必要每次都编译那些不需要经常改变的代码。
 *     编译性能当然就提高了。
 *（4）如果vs工程选用了预编译头文件的方式，那么每一个.cpp源文件的第一行代码必须#include “stdafx.h”
 *     包含预编译头文件，否则会编译出错。
 */

/*2.预编译头的使用：
 *（1）要使用预编译头我们必须指定一个头文件，这个头文件包含不会经常改变的代码和其他的头文件，
 *     然后用该头文件来生成一个预编译头文件（.pch文件）。很多人都认为stdafx.h头文件是VC提供的
 *     一个“系统级别”的，编译器带自带的一个头文件。其实不是的，预编译头文件可以是任何名字的。
 *（2）头文件是不能编译的，所以还需要一个cpp文件来生成.pch文件。这个文件默认的就是stdafx.cpp。
 *     在stdafx.cpp里只有一句代码就是：#include “stdafx.h”。原因是我们仅仅是要它能够编译而已，
 *     也就是说，要的只是它的.cpp的扩展名。可以用/Yc编译开关来指定stdAfx.cpp来生成一个.pch文件，
 *     通过/Fp编译开关来指定生成的pch文件的名字。
 *（3）/Yc的作用就是指定一个cpp文件来创建一个.pch预编译头文件。/Yc后面的文件名是那个包含了稳定代码的头文件，
 *     一个工程里只能有一个文件的可以有/Yc开关。VC根据/Yc选项把stdafx.cpp编译成一个.obj文件和一个.pch文件。
 *（4）如果使用了/Yu选项，就是说使用了预编译头。在每个cpp文件的最开头，需要包含你指定产生.pch文件的.h文件，
 *     默认是“stdafx.h”，不然就会有问题。如果没有包含这个头文件，编译时就会报“Unexpected file end”错误。
 *     如果不是在最开头包含的，可能会产生各种奇怪的错误。
 *（5）如果.pch文件不小心丢了，只要需要让编译器重新生成一个pch文件就行。即把stdafx.cpp重新编译一遍就可以了。
 *     简单一点就是打开指定了/Yc的那个cpp文件，按一下Ctrl + F7就可以了。当然也可以傻傻的Rebuild all。
 */

/*3.预编译头技术的原理：
 *（1）在Windows程序开发时，经常要在各个文件中包含windows.h、stdlib.h等标准头文件，而这些文件非常的大，
 *     在编译时就非常的耗时。为解决这个问题，于是就有了预编译头文件的技术。
 *（2）头文件预编译技术就是把工程中，常用的一些头文件包含在stdafx.h中，并在所有的.cpp文件编译之前对stdafx.h
 *     进行预先编译，得到编译结果.pch文件，后期工程中在编译其它.cpp文件时，即使#include “stdafx.h”包含了它，
 *     都不再编译stdafx.h中的内容，仅仅使用预编译的结果。其中stdafx.h叫做预编译头文件，stdafx的英文全称为：
 *     Standard Application Framework Extensions，当然你也可以自定义预编译头文件的名称，手动重命名stdafx.h，
 *     ProjectName.pch叫做预编译头。
 *（3）采用预编译头技术可以加快编译速度，节省编译时间。因为只需要预先编译一次就可以在所有的.cpp编译时使用，
 *     不用再次编译。但这样带来的一个问题就是每一个.cpp文件的开头都要包含预编译头文件#include "stdafx.h"。
 *     因为预编译头技术是假定预编译头中的内容会在所有.cpp文件中使用，在编译你的.cpp的时候，就会将预编译头
 *     中已经编译完的部分加载到内存中。
 */

/*4.使用预编译头文件的注意事项：
 *（1）编写的任何.cpp文件都必须首先包含stdafx.h。
 *（2）工程中的大多数.cpp文件需要的.h文件，顺便将它们加在stdafx.h后面，然后预编译stdafx.cpp。
 *（3）由于.pch文件具有大量的符号信息，所以它是工程文件里最大的文件。
 */

#ifndef _PCH_H_
#define _PCH_H_

#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif

#include <QApplication>
#include <QWidget>
#include <QIcon>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QMessageBox>
#include <QGridLayout>
#include <QDialog>

#endif  //_PCH_H_
