/*1.stdafx.h预编译头文件：
 *（1）stdafx.h起到的作用是头文件预编译，即把C++工程中使用的MFC头文件预先编译，以后该工程编译时，
 *     直接使用预编译的结果，以加快编译速度。C++编译器通过一个头文件stdafx.h来使用预编译头文件。
 *     stdafx.h并不是标准C++头文件，与项目的源代码存放在同一个文件夹下，通过#include "stdafx.h"引用。
 *（2）stdafx.h是为了提高编译速度而存在的。stdafx.h中包含的头文件都是经常使用且不经常更改的。
 *（3）stdafx的英文全称为：Standard Application Framework Extensions（标准应用程序框架的扩展）。
 *（4）“.pch”预编译头通过编译stdafx.cpp生成，以工程名命名，由于预编译的头文件的后缀是“.pch”，
 *     所以编译结果文件是projectname.pch。编译器通过一个头文件stdafx.h来使用预编译头文件。
 *     stdafx.h头文件名是可以在vs的编译设置里修改的。编译器认为所有在指令#include "stdafx.h"
 *     前的代码都是预编译的，它跳过#include "stdafx.h"指令，使用projectname.pch编译这条指令
 *     之后的所有代码。因此所有的cpp文件中第一条语句都是#include "stdafx.h"。在它前面的所有
 *     代码将被忽略，其他的头文件应该在这一行后面被包含。否则将会得到“No such file or directory”
 *     这样让人百思不得其解的错误提示。
 *（5）stdafx.h是一个预编译头文件，其中包含的头文件经常被使用，但很少被修改。这减少了编译时间
 *     和不必要的处理。
 *（6）Visual Studio中使用预编译头stdafx.h来让编译器知道曾经编译过的文件，不需要从头编译它。
 */

/*2.预编译头的使用注意事项：
 *（1）由于编译器假定预编译头中包含过的头文件会在所有cpp中使用，因此编译器在编译cpp文件的时候，
 *     就会将预编译头中已经编译完的部分加载到内存中。如果编译器发现你的cpp居然没有包含预编译头，
 *     因为不知道该如何将已编译完的部分从内存中请出去，所以整个编译过程就会失败。因此如果使用了
 *     预编译头技术，就必须在所有的cpp中包含预编译头。
 *（2）MFC工程中为你建立了一个默认的预编译头stdafx.h，当然也可以在自己的工程中，使用其它文件名
 *     作为你的预编译头。
 *（3）编译器认为所有在指令#include "stdafx.h"前的代码都是预编译的，它跳过#include "stdafx.h"指令，
 *     使用projectname.pch文件编译这条指令之后的所有代码。因此所有的MFC cpp实现文件第一条语句都是：
 *     #include "stdafx.h"。在它前面的所有代码将被忽略，所以其他的头文件应该在这一行后面被包含。
 *     否则你将会得到"No such file or directory"，这样让你百思不得其解的错误提示。
 *（4）绝对不要在头文件里包含预编译头文件。因为一旦在头文件中#include "stdafx.h"，这时编译器判断
 *     不出包含的stdafx.h是预编译头文件，而当做普通文件编译，所以每次都会编译stdafx.h也就失去了
 *     预编译的意义。
 *（5）将stdfax.cpp属性中预编译头改为/Yc创建，工程中其余cpp属性预编译头均改为/Yu使用，工程属性
 *     预编译头改为/Yu使用。
 */

#ifndef _STDAFX_H
#define _STDAFX_H

#include <iostream>
#include <string>
#include <vector>
#include <functional>
#include "mapreduce.h"

#endif  // _STDAFX_H

 
 