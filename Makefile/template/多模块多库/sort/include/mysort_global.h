#ifndef _MYSORT_GLOBAL_H_
#define _MYSORT_GLOBAL_H_

#ifdef WIN32
#	ifdef MYSORT_LIBRARY
#		define MYSORT_LIB_EXPORT __declspec(dllexport)
#	else
#		define MYSORT_LIB_EXPORT __declspec(dllimport)
#	endif
#else
#	define DMYSORT_LIB_EXPORT
#endif

#endif // _MYSORT_GLOBAL_H_