#ifndef _LIB_SEARCH_GLOBAL_H_
#define _LIB_SEARCH_GLOBAL_H_

#if defined(SHARED_LIBRARY) && !defined(_MSC_VER)
#    ifdef SEARCH_LIBRARY
#        define PUBLIC_FUNCTION __declspec(dllexport)
#    else
#        define PUBLIC_FUNCTION __declspec(dllimport)	
#    endif  //SEARCH_LIBRARY
#else
#    define PUBLIC_FUNCTION
#endif  //SEARCH_LIBRARY

#endif  //_LIB_SEARCH_GLOBAL_H_