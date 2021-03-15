#ifndef _STUDENT_GLOBAL_H
#define _STUDENT_GLOBAL_H

/*只有windows操作系统中使用VC++编译器生成动态库时，才需要使用__declspec(dllexport)与__declspec(dllimport)
 *语句来声明dll动态库中符号的导出与导入。如果是Windows操作系统中使用MSVC编译器生成静态库，那么不需要使用这
 *两条符号的导出与导入声明语句。在LInux操作系统中生成动态库或静态库都没有库中符号导出与导入命令。
 */

/*Windows操作系统中使用MSVC编译器生成动态库时，__declspec(dllexport)用于声明一个变量、函数或类
 *从dll动态库中导出，可以被外部应用程序所调用。__declspec(dllimport)用于在动态库提供的头文件中，
 *显示告诉外部应用程序，该动态库里那些变量、函数或类是可以直接从dll中导入的，而不用编译器衔接时
 *再去慢慢的查找，从而提高编译衔接速度。
 */

#ifdef WIN32
#	if defined(STUDENT_LIBRARY)
#  		define STUDENT_SHARED_EXPORT __declspec(dllexport)
#	else
#  		define STUDENT_SHARED_EXPORT __declspec(dllimport)
#	endif
#else
#	define STUDENT_SHARED_EXPORT
#endif

#endif //_STUDENT_GLOBAL_H