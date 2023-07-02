/*1.C语言中的可变参函数：
 *（1）可变参函数：参数的个数和类型都不固定的函数。
 *（2）可变参函数的参数存储其实跟int main(int argc,char* argv[])函数的参数存储很像，由一个连续的参数列表组成，
 *     列表里存放的是每个参数的地址。最后一个固定参数的存储地址后面，就是一系列参数的指针。
 *（3）C语言中可以使用va_list、va_start()、va_arg()和va_end()系列变参宏实现可变参函数，此处va意为variable-argument可变参数。
 *（4）在c/c++语言中使用三个点"..."省略号表示可以接受不定数量的参数。
 *（5）c/c++语言具备一个不同于其他编程语言的特性，即支持可变参数函数。例如C库中的printf(),scanf(),sprintf(),sscanf()等函数，
 *     都支持输入数量不定的参数。
 */
 
/*2.可变参函数的参数列表构成：
 *任何一个可变参数的函数都由两部分构成：固定参数和可选参数。其中至少要有一个固定参数，其声明与普通函数参数声明相同。
 *可选参数由于数目不定（0个或以上），声明时用"..."三个点表示。固定参数和可选参数共同构成可变参数函数的参数列表。
 */
 
 /*3.可变参函数和普通函数的区别：
 *对于一个普通函数，在函数实现中不用关心实参，只需要在函数体内对形参直接操作即可。当函数调用时，
 *传递的实参和形参个数和格式是匹配的。而在可变参函数体内，因为预先不知道传进来的参数类型和个数，
 *所以实现起来会比普通函数稍微麻烦一点。首先要需要解析传进来的实参，然后才能接着像普通函数一样，
 *对实参进行处理。
 */

/*4.可变参数使用的注意事项：
 *（1）至少有一个有效的形参，形参不能完全是"..."省略号形参。
 *（2）省略号形参"..."只能出现在形参列表最后的一个位置。
 *（3）如果有多个非可变参数，那va_start()宏函数的第2个参数就必须要绑定"..."省略号形参之前的那个形参。
 *（4）不建议在C++中使用C语言的省略号形参，应该使用C++11引入的std::initializer_list初始化列表或变长模板代替。
 */
 
 /*5.可变参数函数中判断参数类型和数量的方法：
  *（1）由于C语言不支持函数重载，所以只能通过不同的函数名区分，处理不同类型的可变参数函数。
  *     通常使用的函数命名方式：函数名 = 功能 + 类型。
  *（2）通过固定参数指定可变参数个数，即显式提供变参数目。
  *（3）定义一个结束标记，调用时通过最后一个参数传递该标记以结束变参的遍历，即设定遍历结束条件。
  *（4）显式提供变参类型枚举值或在固定参数中包含足够的类型信息（如printf()函数通过分析格式化字符串format来确定各变参类型）。
  *（5）主调函数和被调函数可约定变参的数目和类型。
  */
  
 
 /*6.可变参数函数的实现原理：
  *
 
  */
  
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>     //va_list,va_start(),va_arg(),va_end()
#include <assert.h>
#include <string.h>

#define _CHANGE_WAY_
// #undef _CHANGE_WAY_

#define BUFF_SIZE 1024

typedef enum
{
	UNKNOW_TYPE,
	CHAR_TYPE,
	SHORT_TYPE,
	INT_TYPE,
	LONG_TYPE,
	FLOAT_TYPE,
	DOUBLE_TYPE,
	STRING_TYPE
}DataType_t;

typedef struct
{
	DataType_t m_paramType;     //参数类型
	size_t m_paramCount;        //参数个数
}ParamInfo;

typedef unsigned int count_t;

//可变参数函数原型声明，至少需要一个确定的参数，括号内的省略号表示可选参数。
static int sum_int(count_t len,...);
static double average_int(count_t len,...);

static double sum_float(size_t size,...);         //sum_float()函数通过固定参数指定可变参数个数，以结束变参的遍历。
static double average_float(size_t size,...);

static int max(count_t len,...);
static int min(count_t len,...);

static double maxf(size_t count,...);            //fmax()与fmin()是C99自带的函数，所以自定义函数不能使用fmax或fmin函数名。
static double minf(size_t count,...);

//concat()函数定义一个结束标记（"\0"或NULL），调用时通过最后一个参数传递该标记，以结束变参的遍历。
static char* concat(char result[],const char* str1,...);
static char* concat_n(char* result,size_t len,const char* str1,...);

#ifndef _CHANGE_WAY_
static void* add(const DataType_t type,size_t count,...);
#else
static void* add(const ParamInfo argInfo,...);
#endif

static int* add_int(size_t count,va_list pargs);
static double* add_double(size_t count,va_list pargs);
static char* add_string(size_t count,va_list pargs);

int main(void)
{
	int ret = sum_int(10,10,11,12,13,14,15,16,17,18,19);
	printf("10 + 11 + ... + 19 =%d\n",ret);
	
	double result = average_int(10,10,11,12,13,14,15,16,17,18,19);
	printf("(10 + 11 + ... + 19)/10 =%f\n",result);
	
	double total = sum_float(5,3.14,2.718,1.414,0.618,1.732);
	printf("3.14 + 2.718 + 1.414 + 0.618 + 1.732 =%f\n",total);
	
	double avg = average_float(5,3.14,2.718,1.414,0.618,1.732);
	printf("(3.14 + 2.718 + 1.414 + 0.618 + 1.732)/5 =%f\n",avg);
	
	int num = max(10,10,11,12,13,14,15,16,17,18,19);
	printf("10,11 + ... + 19 max =%d\n",num);
	
	num = min(10,10,11,12,13,14,15,16,17,18,19);
	printf("10,11 + ... + 19 min =%d\n",num);
	
	double data = maxf(5,3.14,2.718,1.414,0.618,1.732);
	printf("3.14, 2.718, 1.414, 0.618, 1.732 max =%f\n",data);
	
	data = minf(5,3.14,2.718,1.414,0.618,1.732);
	printf("3.14, 2.718, 1.414, 0.618, 1.732 min =%f\n",data);

#ifndef _CHANGE_WAY_
	char buf[BUFF_SIZE] = {0};
	concat(buf,"hello"," ","variable","-","argument"," function!","\0");     //最后一个参数"\0"作为变参结束符，用于循环获取变参的内容。
	printf("buf = %s\n",buf);
	
	memset(buf,0,BUFF_SIZE);
	char* str = concat_n(buf,15,"hello"," ","variable","-","argument"," function!","\0");
	printf("str = %s\n\n",str);
#else
	char buf[BUFF_SIZE] = {0};
	concat(buf,"hello"," ","variable","-","argument"," function!",NULL);
	printf("buf = %s\n",buf);
	
	memset(buf,0,BUFF_SIZE);
	char* str = concat_n(buf,15,"hello"," ","variable","-","argument"," function!",NULL);
	printf("str = %s\n\n",str);	
#endif

#ifndef _CHANGE_WAY_
#pragma message("using multiple parameter!");
	void* pRet_int = add(INT_TYPE,5,21,22,23,24,25);
	printf("21 + 22 + 23 + 24 + 25 =%d\n",*(int*)pRet_int);
	
	void* pRet_double = add(DOUBLE_TYPE,5,3.14,2.718,1.414,0.618,1.732);
	printf("3.14 + 2.718 + 1.414 + 0.618 + 1.732 =%f\n",*(double*)pRet_double);
	
	void* pRet_string = add(STRING_TYPE,5,"this"," time"," is"," 2023/7/2"," 22:40");
	printf("pRet_string =%s\n\n",(char*)pRet_string);
#else
#pragma message("using struct parameter!");
	ParamInfo argInfo = {INT_TYPE,5};
	void* pRet_int = add(argInfo,21,22,23,24,25);
	printf("21 + 22 + 23 + 24 + 25 =%d\n",*(int*)pRet_int);
	
	argInfo.m_paramType = DOUBLE_TYPE;
	argInfo.m_paramCount = 5;
	void* pRet_double = add(argInfo,3.14,2.718,1.414,0.618,1.732);
	printf("3.14 + 2.718 + 1.414 + 0.618 + 1.732 =%f\n",*(double*)pRet_double);
	
	argInfo.m_paramType = STRING_TYPE;
	argInfo.m_paramCount = 5;
	void* pRet_string = add(argInfo,"this"," time"," is"," 2023/7/2"," 22:40");
	printf("pRet_string =%s\n\n",(char*)pRet_string);
#endif
	return 0;
}

int sum_int(count_t len,...)
{
	va_list ap;
	
	int total = 0;
	va_start(ap,len);
	while(len-->0)
	{
		int num = va_arg(ap,int);
		total += num;
	}
	
	va_end(ap);
	return total;
}

/*（1）avg = (a1 + a2 + .. + an) / n求平均值公式，如果n的值很大，那么就可能造成所有数字求和时，整数越界。
 *（2）avg(n) = avg(n-1) + (an - avg(n-1)) / n求平均值公式，不用先对所有数字求和再除以n，就可以避免整数越界问题。
 */
double average_int(count_t len,...)
{
	double ret = 0;
	va_list arg_list;
	va_start(arg_list,len);
	for(int i=1;i <= len;++i)
	{
		int value = va_arg(arg_list,int);
		ret = ret + (value - ret) / i;
	}
	
	va_end(arg_list);
	return ret;
}

double sum_float(size_t size,...)
{
	va_list arg_ptr;
	
	double result = 0.0;
	va_start(arg_ptr,size);
	while(size-->0)
	{
		double data = va_arg(arg_ptr,double);
		result += data;
	}
	
	va_end(arg_ptr);
	return result;
}

double average_float(size_t size,...)
{
	va_list args;
	va_start(args,size);
	
	double ret = 0.0;
	for(int i=0;i<size;++i)
	{
		ret += va_arg(args,double);     //先进行数值累加，再求平均值的做法有可能造成数值越界问题。
	}
	
	va_end(args);
	return ret / size;
}

int max(count_t len,...)
{
	assert(len != 0);
	
	va_list p_args;
	va_start(p_args,len);
	
	int temp = va_arg(p_args,int);
	for(int i=1;i<len;++i)
	{
		int num = va_arg(p_args,int);
		if(num > temp)
		{
			temp = num;
		}
	}
	
	va_end(p_args);
	return temp;
}

int min(count_t len,...)
{
	if(len == 0)
	{
		puts("min() error: len is zero!");
		abort();
	}
	
	va_list valist;
	va_start(valist,len);
	
	int ret = va_arg(valist,int);
	while(len-->1)
	{
		int temp = va_arg(valist,int);
		if(temp < ret)
		{
			ret = temp;
		}
	}
	
	va_end(valist);
	return ret;
}

double maxf(size_t count,...)
{
	if(count == 0)
	{
		puts("maxf() error: count is zero!");
		exit(-1);
	}
	
	va_list pargs;
	va_start(pargs,count);
	
	double temp = va_arg(pargs,double);
	for(int i=1;i<count;++i)
	{
		double num = va_arg(pargs,double);
		if(num > temp)
		{
			temp = num;
		}
	}
	
	va_end(pargs);
	return temp;
}

double minf(size_t count,...)
{
	assert(count != 0);
	
	va_list argsPtr;
	va_start(argsPtr,count);
	
	double ret = va_arg(argsPtr,double);
	while(count-->1)
	{
		double temp = va_arg(argsPtr,double);
		if(temp < ret)
		{
			ret = temp;
		}
	}
	
	va_end(argsPtr);
	return ret;
}

#ifndef _CHANGE_WAY_
//concat()可变参数函数中定义一个结束标记"\0"，调用时通过最后一个参数传递该标记，以结束变参的遍历。
char* concat(char result[],const char* str1,...)
{
	if(result == NULL || str1 == NULL)
	{
		return NULL;
	}
	strcpy(result,str1);
	
	va_list pArg;
	va_start(pArg,str1);
	
	const char* strTemp = va_arg(pArg,char*);
	while(strcmp(strTemp,"\0") != 0)
	{
		strcat(result,strTemp);
		strTemp = va_arg(pArg,char*);
	}
	
	va_end(pArg);
	return result;
}

char* concat_n(char* result,size_t len,const char* str1,...)
{
	if(result == NULL || len == 0 || str1 == NULL)
	{
		return NULL;
	}
	strncpy(result,str1,len);
	
	va_list pArgs;
	va_start(pArgs,str1);
	
	size_t remainLen = len - (strlen(result) + 1);
	const char* strTemp = va_arg(pArgs,char*);
	while(remainLen != 0 || strncmp(strTemp,"\0",strlen("\0")) != 0)
	{
		strncat(result,strTemp,remainLen);
		strTemp = va_arg(pArgs,char*);
		remainLen = len - (strlen(result) + 1);
	}
	
	va_end(pArgs);
	return result;
}
#else
//concat()可变参数函数中定义一个结束标记NULL，调用时通过最后一个参数传递该标记，以结束变参的遍历。
char* concat(char result[],const char* str1,...)
{
	if(result == NULL || str1 == NULL)
	{
		return NULL;
	}
	strcpy(result,str1);
	
	va_list pArg;
	va_start(pArg,str1);
	
	const char* strTemp = va_arg(pArg,char*);
	while(strTemp != NULL)
	{
		strcat(result,strTemp);
		strTemp = va_arg(pArg,char*);
	}
	
	va_end(pArg);
	return result;
}

char* concat_n(char* result,size_t len,const char* str1,...)
{
	if(result == NULL || len == 0 || str1 == NULL)
	{
		return NULL;
	}
	strncpy(result,str1,len);
	
	va_list pArgs;
	va_start(pArgs,str1);
	
	size_t remainLen = len - (strlen(result) + 1);
	const char* strTemp = va_arg(pArgs,char*);
	while(strTemp != NULL || remainLen != 0)
	{
		strncat(result,strTemp,remainLen);
		strTemp = va_arg(pArgs,char*);
		remainLen = len - (strlen(result) + 1);
	}
	
	va_end(pArgs);
	return result;
}
#endif

#ifndef _CHANGE_WAY_
void* add(const DataType_t type,size_t count,...)
{
	if(type == UNKNOW_TYPE || count == 0)
	{
		return NULL;
	}

	va_list valist;
	va_start(valist,count);

	void* p_ret = NULL;
	switch(type){
	case CHAR_TYPE:
		puts("add() warning: char can't used in variable argument function!");
		break;
	case SHORT_TYPE:
		puts("add() warning: short can't used in variable argument function!");
		break;
	case INT_TYPE:
		p_ret = add_int(count,valist);
		break;
	case LONG_TYPE:
		puts("add() warning: don't deal with long type!");
		break;
	case FLOAT_TYPE:
		puts("add() warning: float can't used in variable argument function!");
		break;
	case DOUBLE_TYPE:
		p_ret = add_double(count,valist);
		break;
	case STRING_TYPE:
		p_ret = add_string(count,valist);
		break;
	default:
		puts("unknow type!");
		break;
	}
	
	va_end(valist);
	return p_ret;
}
#else
void* add(const ParamInfo argInfo,...)
{
	if(argInfo.m_paramType == UNKNOW_TYPE || argInfo.m_paramCount == 0)
	{
		return NULL;
	}
	
	va_list args;
	va_start(args,argInfo);

	void* pResult = NULL;
	switch(argInfo.m_paramType){
	case CHAR_TYPE:
		puts("add() warning: char can't used in variable argument function!");
		break;
	case SHORT_TYPE:
		puts("add() warning: short can't used in variable argument function!");
		break;
	case INT_TYPE:
		pResult = add_int(argInfo.m_paramCount,args);
		break;
	case LONG_TYPE:
		puts("add() warning: don't deal with long type!");
		break;
	case FLOAT_TYPE:
		puts("add() warning: float can't used in variable argument function!");
		break;
	case DOUBLE_TYPE:
		pResult = add_double(argInfo.m_paramCount,args);
		break;
	case STRING_TYPE:
		pResult = add_string(argInfo.m_paramCount,args);
		break;
	default:
		puts("unknow type!");
		break;
	}
	
	va_end(args);
	return pResult;
}
#endif

int* add_int(size_t count,va_list pargs)
{
	if(count == 0 || pargs == NULL)
	{
		return 0;
	}

	static int ret = 0;
	ret = 0;
	
	while(count-->0)
	{
		ret += va_arg(pargs,int);
	}
	return &ret;
}

double* add_double(size_t count,va_list pargs)
{
	if(count == 0 || pargs == NULL)
	{
		return 0;
	}

	static double result = 0;
	result = 0;
	
	while(count-->0)
	{
		result += va_arg(pargs,double);
	}
	return &result;	
}

char* add_string(size_t count,va_list pargs)
{
	if(count == 0 || pargs == NULL)
	{
		return NULL;
	}

	static char buf[BUFF_SIZE] = {0};
	memset(buf,0,sizeof(buf));
	
	for(int i=0;i<count;++i)
	{
		char* str = va_arg(pargs,char*);
		strcat(buf,str);
	}
	return buf;
}