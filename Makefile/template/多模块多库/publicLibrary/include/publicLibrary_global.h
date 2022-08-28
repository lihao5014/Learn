#ifndef _PUBLIC_LIBRARY_GLOBAL_H_
#define _PUBLIC_LIBRARY_GLOBAL_H_

#ifdef _MSC_VER
#	ifdef PUBLIC_LIBRARY
#		define PUBLIC_LIB_EXPORT __declspec(dllexport)
#	else
#		define PUBLIC_LIB_EXPORT __declspec(dllimport)
#	endif
#else
#	define PUBLIC_LIB_EXPORT
#endif

#endif  // _PUBLIC_LIBRARY_GLOBAL_H_