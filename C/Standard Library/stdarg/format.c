/*

       int vprintf(const char *format, va_list ap);
       int vfprintf(FILE *stream, const char *format, va_list ap);
       int vsprintf(char *str, const char *format, va_list ap);
       int vsnprintf(char *str, size_t size, const char *format, va_list ap);
*/

/*1.32位和64位机器上各数据类型所占字节数：
 *	C类型		32位机器(字节)		64位机器(字节)
 *	char	  		1					1
 *	short	  		2					2
 *	int	      		4					4
 *	long int  		4					8
 *	long long 		8					8
 *	char*	  		4					8
 *	float	  		4					4
 *
 *（1）在32位和64机器中int类型都占用4个字节。编译器可以根据自身硬件来选择合适的大小，但是需要满足约束：
 *     short和int型至少为16位，long型至少为32位，并且short型长度不能超过int型，而int型不能超过long型。
 *     这即是说各个类型的变量长度是由编译器来决定的，而当前主流的编译器中一般是32位和64位机器中int类型
 *     都是4个字节。
 *（2）在32位系统和64位系统上各数据类型所占字节数，最大的不同点就是在long型和指针类型长度不一样。
 *     对于指针而言，64位机器可以寻址2^64，每个内存地址长度为64位，即8字节。而32位机器可以寻址2^32，
 *     每个内存地址长度为32位，即4字节。
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <assert.h>
#include <string.h>
#include <math.h>      //NAN,isnan(),INFINITY,isinf()

#define _ERROR_
#undef _ERROR_

static void foreach_parameter_stack(char ch,int num,double data,const char* str);

static void printArgs(unsigned int count,...);

static int sum_int(unsigned int count,...);
static double average_int(unsigned int arg_cnt,...);

static double sum_float(double n1,...);
static double average_float(double num1,...);

void my_printf(const char* format,...);
void my_fprintf(FILE *fp,const char* format,...);

void my_sprintf(char* str,const char* format,...);
void my_snprinft(char* str,size_t size,const char* format,...);

int main(void)
{
	printf("sizeof(int) =%d, sizeof(int*) =%d\n\n",sizeof(int),sizeof(int*));
	
	foreach_parameter_stack('a',100,2.71828,"function parameter stack");
	puts("");
	
	printArgs(5,10,11,12,13,14);
	putc('\n',stdout);
	
	int ret = sum_int(5,10,11,12,13,14);
	printf("10,11 + ... + 15 =%d\n\n",ret);
	
	double avg = average_int(5,10,11,12,13,14);
	printf("(10 + 11 + ... + 14)/5 =%f\n\n",avg);
	
	double total = sum_float(3.14,2.718,1.414,0.618,1.732,NAN);
	printf("3.14 + 2.718 + 1.414 + 0.618 + 1.732 =%f\n\n",total);
	
	double result = average_float(3.14,2.718,1.414,0.618,1.732,NAN);
	printf("(3.14 + 2.718 + 1.414 + 0.618 + 1.732)/5 =%f\n\n",result);
	
	int num = 5;
	double value = 3.14;
	const char* str = "hello world";
	my_printf("num =%d,value =%f,str =%s\n",num,value,str);
	
	FILE* fp = fopen("file.txt", "w+");
	if(fp == NULL)
	{
		perror("file.txt can't open!");
	}
	else
	{
		my_fprintf(fp,"num =%d,value =%f,str =%s\n",num,value,str);
	}
	
	char buf[512] = {0};
	my_sprintf(buf,"num =%d,value =%f,str =%s\n",num,value,str);
	puts(buf);
	
	memset(buf,0,sizeof(buf));
	my_snprinft(buf,16,"num =%d,value =%f,str =%s\n",num,value,str);
	puts(buf);

	return 0;
}

/*foreach_parameter_stack()函数的参数栈：
 *（1）32位系统中：
 *  +-----------------------+  ->  char*
 *  | 4字节，存储一个char   |
 *  +-----------------------+  ->  int*
 *  | 4字节，存储一个int    |
 *  +-----------------------+  ->  double*
 *  | 8字节，存储一个double |
 *  +-----------------------+  ->  char**
 *  | 4字节，存储一个char*  |
 *  +------------------------+
 *
 *（2）64位系统中：
 *  +-----------------------+  ->  char*
 *  | 8字节，存储一个char   |
 *  +-----------------------+  ->  int*
 *  | 8字节，存储一个int    |
 *  +-----------------------+  ->  double*
 *  | 8字节，存储一个double |
 *  +-----------------------+  ->  char**
 *  | 8字节，存储一个char*  |
 *  +-----------------------+
 */
void foreach_parameter_stack(char ch,int num,double data,const char* str)
{
	printf("%p, ch =%c\n",&ch,ch);
	printf("%p, num =%d\n",&num,num);
	printf("%p, data =%f\n",&data,data);
	printf("%p, %p, str =%s\n",&str,str,str);
	putchar('\n');
	
	//在函数体中可以不通过形参变量名，而直接使用指向参数栈的指针，获取到函数传入的每个参数值。
	char* p = &ch;
	printf("address: %p, ch =%c\n",p,*p);
	
	p += sizeof(int*);
	printf("address: %p, num =%d\n",p,*((int*)p));
	
	p += sizeof(double*);
	printf("address: %p, data =%f\n",p,*((double*)p));

#ifdef _WIN32
	p += sizeof(double);        //32位系统中double类型为8个字节，比指针所占用的4个字节还要大，因此p只移动4个字节还不够。
	printf("address: %p, %p, str =%s\n",p,*((char**)p),*((char**)p));
#else
	p += sizeof(void*);        //64位系统中double类型和指针都占用的8个字节，因此p只移动1个指针大小的距离就足够了。
	printf("address: %p, %p, str =%s\n",p,*((char**)p),*((char**)p));
#endif	
}

#ifdef _ERROR_
/*在64位系统中int类型占4个字节，而指针类型占8各字节。(int*)&count + 1和parg++都只能使指针向前移动4个字节。
 *而64位机器上函数参数栈里的每两个变量的地址之间相差一个指针大小，即8个字节。所以parg指针每次只向前移动4个
 *字节明显不够，需要移动8个字节才能正常解析函数传进来的实参。
 */
void printArgs(unsigned int count,...)
{
	int* parg = (int*)&count + 1;        //(int*)&count + 1 = (int*)&count + 1 * sizeof(int)
	for(int i=0;i<count;++i)
	{
		printf("address: %p,arg_%d = %d\n",parg,i,*parg);
		parg++;
	}
}
#else
void printArgs(unsigned int count,...)
{
	char* parg = (char*)&count + sizeof(void*);
	for(int i=0;i<count;++i)
	{
		printf("address: %p,arg_%d = %d\n",parg,i,*((int*)parg));
		parg += sizeof(char*);
	}
}
#endif

int sum_int(unsigned int count,...)
{
	int result = 0;
	char* arg_p = (char*)&count + sizeof(int*);
	while(count-->0)
	{
		result += *((int*)arg_p);
		arg_p += sizeof(int*);
	}

	return result;
}

double average_int(unsigned int arg_cnt,...)
{
	double ret = 0;
	char* argPtr = (char*)&arg_cnt + sizeof(void*);
	for(int i=1;i<=arg_cnt;++i)
	{
		ret = ret + (*(int*)argPtr - ret) / i;
		argPtr += sizeof(int*);
	}
	
	argPtr = NULL;
	return ret;
}

double sum_float(double n1,...)
{
	va_list p_args;
	va_start(p_args,n1);
	
	double result = n1;
	double temp = va_arg(p_args,double);
	while(!isnan(temp))                    //isnan()函数用于判断一个值是不是数字，NAN（not a number）
	{
		result += temp;
		temp = va_arg(p_args,double);
	};
	
	return result;
}

double average_float(double num1,...)
{
	va_list arg_list;
	va_start(arg_list,num1);
	
	double ret = num1;
	double temp = va_arg(arg_list,double);
	for(int i=1;!isnan(temp);++i)
	{
		ret += (temp - ret) / i;
		temp = va_arg(arg_list,double);
	}
	
	return ret;
}

void my_printf(const char* format,...)
{
	va_list ap;
	va_start(ap,format);
	vprintf(format,ap);
	va_end(ap);
}

void my_fprintf(FILE *fp,const char* format,...)
{
	va_list argp;
	va_start(argp,format);
	vfprintf(fp,format,argp);
	va_end(argp);
}

void my_sprintf(char* str,const char* format,...)
{
	assert(str != NULL);
	
	va_list args;
	va_start(args,format);
	vsprintf(str,format,args);
	va_end(args);
}

void my_snprinft(char* str,size_t size,const char* format,...)
{
	assert(str != NULL);
	
	va_list arg_ptr;
	va_start(arg_ptr,format);
	vsnprintf(str,size,format,arg_ptr);
	va_end(arg_ptr);
}