/*1.预编译头文件（precompiled header）：
 *（1）预编译头是程序设计时把头文件编译为中间格式，以节约在开发过程中编译器反复编译
 *     该头文件的开销。可见预编译头的意义就是：防止反复编译某一个头文件。
 *（2）.pch文件全称为：Pre-compiled Header被预先编译过的头文件。对于比较大型的工程，
 *     往往编译时间会很久，通过使用.pch，把那些不经常发生改动的头文件都预先编译出来，
 *     就可以大大节省实际使用时候的编译时间。
 *（3）实际应用中经常把外部调用的API的头文件编译为pch，比如C标准库、STL、Windows API、
 *     windows.h等。
 *（4）stdafx.h中的AFX代表Application Framework eXtensions。AFX是Microsoft Foundation
 *     Classes（MFC）的旧称。
 */

/*2.预编译头产生的原因：
 *有的头文件包含了巨量的源代码（如stdlib.h或windows.h），如果每一个cpp都包含这个头文件，
 *那么就会导致编译过程非常慢，因为头文件不仅大而且还要被编译多次，于是有了预编译头技术。
 *把几乎所有cpp都会包含的一堆头文件提取出来放到一个地方，比如stdafx.h中，并在编译工程时，
 *最先编译stdafx.cpp，然后就生成了一个所有cpp都可以使用的中间文件*.pch。
 */

/*3.预编译文件的特征：
 *如果被预编译的文件是经常会被修改的，那么就失去了预编译的意义。所以预编译的文件都必须是稳定的，
 *不经常被修改的。
 */

/*4.预编译头的使用：
 *使用vs创建工程的时候，默认情况下都会创建预编译头：stdafx.h和stdafx.cpp。那么就可以在stdafx.h中添加工程
 *需要的各种头文件，而在stdafx.cpp中只要#include "stdafx.h"就可以了。当编译时会默认从stdafx.cpp开始编译，
 *生成*.pch文件。当编译其他cpp时，会把*.pch文件加载到内存中，当然其他的cpp都必须#include "stdafx.h"。
 *其实.pch中包含的是到#include"stdafx.h"这一行为止的所有代码编译结果，而我们往往把#include"stdafx.h"
 *放在cpp的第一行。
 */

/*5.使用PCH的缺点：
 *会减弱文件间的关联性。比如原本有一个cpp包含了#include <windows.h>，使用预编译头技术优化编译后，
 *将不经常修改的API头文件放到PCH里。那么之后再阅读源代码，就不知道这个cpp具体包含了哪些头文件了，
 *只知道它用到了PCH，但是不能一眼就看出来它包含了头文件windows.h。
 */

#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             // 从 Windows 头文件中排除极少使用的内容
// Windows 头文件
#include <windows.h>

// C 运行时头文件
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>
