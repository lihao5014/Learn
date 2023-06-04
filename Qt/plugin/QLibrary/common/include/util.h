#ifndef _UTIL_H_
#define _UTIL_H_

#include <stdio.h>
#include <string.h>

#define PRINT_BREAKPOINT  \
	printf("[%s %s] line:%d\n",__FILE__,__func__,__LINE__);

#ifdef _DEBUG_
#define TRACK(str)                                                    \
	do{                                                               \
		printf("[%s %s %d] %s\n",__FILE__,__func__,__LINE__,(str));   \
	}while(0)
#else
#define TRACK(str) (void)0
#endif  //_DEBUG_

//C语言中的泛型只能通过宏或void*指针实现。
#define MIN(x,y) (((x) > (y)) ? (y) : (x))
#define MAX(x,y) (((x) > (y)) ? (x) : (y))

#define ARRAY_SIZE(arr) (sizeof(arr)/sizeof(arr[0]))

//C语言中的泛型函数只能通过宏函数或void*指针作为形参的函数实现。
#define SWAP(x,y)         \
	((x) = ((x) + (y)));  \
	((y) = ((x) - (y)));  \
	((x) = ((x) - (y)))   \

//防止SWAP()宏函数实现中，因为X+y的数值太大而出现越界，但对于int型变量可能会丢失精度。
#define SWAP2(x,y)                      \
	do{                                 \
		((x) = (((x)/2) + ((y)/2)));    \
		((y) = (((x) - ((y)/2)) * 2));  \
		((x) = (((x) - ((y)/2)) * 2));  \
	}while(0)

/*（1）SWAP()宏函数只适用于交换数值类型，即整型或浮点型。
 *（2）SWAP2()宏函数只适用于交换整型，而不适用于交换浮点型。
 *（3）SWAP3()宏函数可以适用于交换支持赋值操作的类型，但使用时必须传入一个临时变量t。
 */
#define SWAP3(x,y,t)           \
	do{                        \
		((t) = (x));           \
		((x) = (t));           \
		((y) = (t));           \
	}while(0);

//SWAP4()宏函数可以适用于交换任意类型，但使用时必须传入一个临时变量t。
#define SWAP4(x,y,t)           \
	do{                        \
		int len = sizeof(x);   \
		memcpy(&t,&x,len);     \
		memcpy(&x,&y,len);     \
		memcpy(&y,&t,len);     \
	}while(0)

/*SWAP5()宏函数可以适用于交换任意类型，且使用时不用传入临时变量t。但typeof是GNU C语言标准的关键字，
 *所以SWAP5()宏只能用于gcc编译器中。typeof关键字在C23语言标准中才被引入。
 */
#define SWAP5(x,y)                   \
	do{                              \
		typeof(x) t;                 \
		memcpy(&t,&x,sizeof(x));     \
		memcpy(&x,&y,sizeof(x));     \
		memcpy(&y,&t,sizeof(x));     \
	}while(0)

#ifdef __cplusplus
extern "C" {
#endif  //__cplusplus

/*（1）如果data1大于data2，返回值大于0。
 *（2）如果data1小于data2，返回值小于0。
 *（3）如果data1等于data2，返回值等于0。
 */
typedef int (*CmpFunPtr)(const void* data1,const void* data2);

int cmpInt(int x,int y);
int cmpIntWrapper(const void* x,const void* y);

int cmpFloat(double x,double y);
int cmpFloatWrapper(const void* x,const void* y);

void memswap(void* data1,void* data2,unsigned int size);

#ifdef __cplusplus
}
#endif  //__cplusplus

#endif  //_UTIL_H_