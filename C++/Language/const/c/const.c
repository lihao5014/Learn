#include <stdio.h>

#define _ERROR_
// #undef _ERROR_

#define SIZE 10

#define UNUSED(x) (void)0

/*C语言中的const变量表示变量只读，而不是真正意义上的常量。而C++中的const关键字即可以用于定义常量，
 *也可以用于修饰变量只读。
 */
static const int g_size = 10;

static void modify_const_variable();
static void specify_array_size();

int main(int argc,char** argv)
{
	UNUSED(argc);
	UNUSED(argv);
	
	modify_const_variable();
	specify_array_size();
	
	return 0;
}

void modify_const_variable()
{
	const int n;

#ifdef _ERROR_
	n = 10;                    //在C/C++语言中const变量都只能在声明定义时进行初始化，以后就不能再为其赋值。
	printf("n=%d\n",n);
#endif
	
	int* p = &n;               //C语言中可以通过指针修改const变量的值
	*p = 20;
	printf("n=%d\n",n);
}

void specify_array_size()
{
#ifdef _ERROR_
	int arr[g_size] = {0};       //C语言中不可以使用const变量指定数组长度。而C++中可以使用const常量指定数组长度。
#else
	int arr[SIZE] = {0};
#endif
}