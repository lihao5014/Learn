#ifndef _LIB_MATH_GLOBAL_H_
#define _LIB_MATH_GLOBAL_H_

#ifdef _MSC_VER
#	ifdef MATH_LIBRARY
#		define LIB_MATH_EXPORT __declspec(dllexport)
#	else
#		define LIB_MATH_EXPORT __declspec(dllimport)
#	endif  // MATH_LIBRARY
#else
#	define LIB_MATH_EXPORT
#endif // _MSC_VER

#endif // _LIB_MATH_GLOBAL_H_