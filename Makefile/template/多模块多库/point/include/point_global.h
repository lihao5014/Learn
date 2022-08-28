#ifndef _POINT_GLOBAL_H_
#define _POINT_GLOBAL_H_

#ifdef _MSC_VAR
#	ifdef POINT_LIBRARY
#		define POINT_LIB_EXPORT __declspec(dllexport)
#	else
#		define POINT_LIB_EXPORT __declspec(dllimport)
#	endif
#else
#	define POINT_LIB_EXPORT
#endif

#endif //_POINT_GLOBAL_H_