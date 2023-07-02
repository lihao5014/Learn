//C语言中宏和回调函数是实现软件框架的两种重要技术，框架或库开发程序员必须精通这两种技术。
//而对于一般的应用程序开发人员来说，对宏和回调函数的使用要求没有那么高。

//C++中开发软件框架的技术有宏、回调函数和多态。

#ifndef _MACRO_UTILS_H
#define _MACRO_UTILS_H

#include <stdio.h>
#include <stdlib.h>

#define NULL_PTR ((void*)0)

//当一个宏对他的某一个参数进行#或##操作时，这个参数使用点并不会被替换为展开后的文本
#define Conn(x,y) (x##y)           //##连接操作符。Gcc编译器中不可以使用##连两字符串，但是VC++编译器可以
#define CONN(x,y) Conn(x,y)        //将宏x,y展开后的结果进行连接

#define LinkStr(x,y) x y           //Gcc和VC++都可以使用这种方式连两字符串

/*
#define ToChar(x) (#@x)            //#@字符化操作符。#@不是标准C支持的语法，Gcc编译器不支持,VC++编译器支持
#define TOCHAR(x) ToChar(x)        //将宏x展开后的结果转化为字符
*/

#define ToString(x) (#x)           //#字符串化操作符
#define TOSTRING(x) ToString(x)    //将宏x展开后的结果转化为字符串

#define Show_Integer(value) printf("%s =%d\n",#value,value)
#define Show_Double(value) printf("%s =%f\n",#value,value)
#define Show_String(value) printf("%s =%s\n",#value,value)

//format是输出格式控制字符d-整型数，f-浮点数，s-字符串
#define ShowValue(value,format) printf("%s =%"#format"\n",#value,value)

#define Debug(msg)                                                                     \
	do{                                                                                \
		printf("[%s %s %s line:%d] %s\n",__DATE__,__TIME__,__FILE__,__LINE__,(msg));   \
	}while(0)

#define Warn_IF(expr)                                \
	do{                                              \
		if(expr)                                     \
		{                                            \
			fprintf(stderr,"warning: "#expr"\n");    \
		}                                            \
	}while(0)

#define Assert(expr)                                                                   \
	do{                                                                                \
		if(!(expr))                                                                    \
		{                                                                              \
			printf("assert failed: %s, file %s, line %d\n",#expr,__FILE__,__LINE__);   \
			abort();                                                                   \
		}                                                                              \
	}while(0)

#define Max(x,y) (((x) > (y)) ? (x) : (y))
#define Min(x,y) (((x) < (y)) ? (x) : (y))

#define ArraySize(a) (sizeof((a))/sizeof((a[0])))

#define Swap(x,y)              \
	do{                        \
		((x) = ((x) + (y)));   \
		((y) = ((x) - (y)));   \
		((x) = ((x) - (y)));   \
	}while(0)

#define SWAP(x,y,t) (((t) = (x)),((x) = (y)),((y) = (t)))

#define Malloc(size,type) ((type*)malloc((size)*sizeof(type)))

#define Free(p)                \
	do{                        \
		if(NULL != (p))        \
		{                      \
			free(p);           \
			(p) = NULL;        \
		}                      \
	}while(0)

#define TypeSize(var) ((char*)((&(var)) + 1) - (char*)(&(var)))         //求变量类型的大小，等同于sizeof()
#define MemberSize(type,member) (sizeof(((type*)0)->member))            //求结构体中成员类型的大小
#define OffsetSize(type,member) ((size_t)&(((type*)0)->member))         //求成员在结构体中的偏移量，size_t在32位系统上是unsigned int，在64位的系统上位unsigned long

#define Loop(a,b) for(int i=0;i<b;++i)
#define Print(x) printf("%s =%d\n",#x,x)

#endif  //_MACRO_UTILS_H