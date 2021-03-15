/*Visual Studio安装目录VC\Tools下的一些常用工具：
 *1.编译器cl.exe
 *2.汇编器ml.exe/ml64.exe
 *3.衔接器link.exe
 *4.静态库打包工具lib.exe
 *5.用于Makefile文件构建和编译工具nmake.exe
 *6.查看dll或exe的依赖库工具dumpbin.exe
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 16

char *str = (char*)malloc(SIZE);

int main(void)
{
	memset(str,0,SIZE);
	strcpy(str,"hello world");
	puts(str);
	
	return 0;
}