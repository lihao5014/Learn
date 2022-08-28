#ifndef _MYMATH_GLOBAL_H_
#define _MYMATH_GLOBAL_H_

#ifdef _MSC_VER
#	ifdef MYMATH_LIBRARY
#		define MYMATH_LIB_EXPORT __declspec(dllexport)
#	else
#		define MYMATH_LIB_EXPORT __declspec(dllimport)
#	endif
#else
#	define MYMATH_LIB_EXPORT
#endif

#endif //_MYMATH_GLOBAL_H_