//一个minunit测试用例是一个没有参数列表，且通过测试后返回0（NULL）的函数。
//如果测试失败，这个函数应该返回一个测试失败的描述字符串。

#ifndef _MINUNIT_H
#define _MINUNIT_H

#include <stdio.h>

#define PRINT(expr) printf("%s =%d\n",#expr,expr)

#define mu_assert(message,test_expr)                \
	do{                                             \
		if(!(test_expr))                            \
		{                                           \
			return message;                         \
		}                                           \
	}while(0)
		
#define mu_run_test(test_case)                      \
	do{                                             \
		char* message = test_case();                \
		tests_run++;                                \
		                                            \
		if(message != NULL)                         \
		{                                           \
			return message;                         \
		}                                           \
	}while(0)

extern int tests_run;

#endif //_MINUNIT_H