/*1.使用Valgrind调试程序：
 *（1）gcc -g hellovalgrind.c -o hellovalgrind                                //编译时添加-g选项，使编译出的程序包含调试信息。
 *（2）valgrind -q --leak-check=yes --log-file=error.txt ./hellovalgrind      //默认使用memcheck工具，并打开内存泄漏检查。
 */

#include <stdio.h>
#include <stdlib.h>

void foo(void)
{
   int* p = malloc(10 * sizeof(int));    //problem1: memory leak -- p not freed
   p[10] = 0;                            //problem2: heap block overrun
}

int main(void)
{
   printf("hello valgrind\n");
   foo();
   
   return 0;
}