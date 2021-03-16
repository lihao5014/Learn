#ifndef _MYMATH_H
#define _MYMATH_H

#ifdef WIN32
#	ifdef SHARED_LIBRARY
#		define DLL_EXPORT __declspec(dllexport)
#	else
#		define DLL_EXPORT __declspec(dllimport)
#	endif
#else
#	define DLL_EXPORT
#endif

typedef int data_t;

DLL_EXPORT data_t add(data_t x,data_t y);
DLL_EXPORT data_t sub(data_t x,data_t y);

#endif //_MYMATH_H