#ifndef _LIB_SORT_GLOBAL_H_
#define _LIB_SORT_GLOBAL_H_

#if defined(SHARED_LIBRARY) && !defined(_MSC_VER)
#    ifdef SORT_LIBRARY
#        define PUBLIC_FUNCTION __declspec(dllexport)
#    else
#        define PUBLIC_FUNCTION __declspec(dllimport)	
#    endif  //SORT_LIBRARY
#else
#    define PUBLIC_FUNCTION
#endif  //SORT_LIBRARY

#endif  //_LIB_SORT_GLOBAL_H_