/*1.objdump命令：
 *（1）objdump命令是Linux下的反汇编目标文件或可执行文件的命令，用于查看目标文件或者可执行文件的构成。
 *（2）objdump -t选项可以查看目标文件、库文件和可执行文件中的符号表。
 *（3）objdump命令使用教程：https://www.cnblogs.com/baiduboy/p/7061365.html
 */

/*2.objdump命令常用选项：
 *（1）-a/--archive-headers：显示档案库的成员信息，类似ls -l将lib*.a的信息列出。
 *（2）-b bfdname/--target=bfdname：指定目标码格式。这不是必须的，objdump能自动识别许多格式。
 *（3）-C/--demangle：将底层的符号名解码成用户级名字，除了去掉所开头的下划线之外，还使得C++函数名以可理解的方式显示。
 *（4）-g/--debugging：显示调试信息。企图解析保存在文件中的调试信息并以C语言的语法显示出来。仅仅支持某些类型的调试信息。有些其他的格式被readelf -w支持。
 *（5）-e/--debugging-tags：类似-g选项，但是生成的信息是和ctags工具相兼容的格式。
 *（6）-d/--disassemble：从objfile中反汇编那些特定指令机器码的section。
 *（7）-D/--disassemble-all：与-d类似，但反汇编所有section。
 *（8）--prefix-addresses：反汇编的时候，显示每一行的完整地址。这是一种比较老的反汇编格式。
 *（9）-EB/-EL/--endian={big|little}：指定目标文件的小端。这个项将影响反汇编出来的指令。在反汇编的文件没描述小端信息的时候用。
 *（10）-f/--file-headers：显示objfile中每个文件的整体头部摘要信息。
 *（11）-h/--section-headers/--headers：显示目标文件各个section的头部摘要信息。
 *（12）-H/--help：查看objdump命令的帮助信息。
 *（13）-j name/--section=name：仅仅显示指定名称为name的section的信息 
 *（14）-l/--line-numbers：用文件名和行号标注相应的目标代码，仅仅和-d、-D或者-r一起使用使用-ld和使用-d的区别不是很大，在源码级调试的时候有用，要求编译时使用了-g之类的调试编译选项。
 *（15）-m machine/--architecture=machine：指定反汇编目标文件时使用的架构，当待反汇编文件本身没描述架构信息的时候(比如S-records)，这个选项很有用。可以用-i选项列出这里能够指定的架构. 
 *（16）-r/--reloc：显示文件的重定位入口。如果和-d或者-D一起使用，重定位部分以反汇编后的格式显示出来。
 *（17）-R/--dynamic-reloc：显示文件的动态重定位入口，仅仅对于动态目标文件意义，比如某些共享库。
 *（18）-s/--full-contents：显示指定section的完整内容。默认所有的非空section都会被显示。
 *（19）-S/--source：尽可能反汇编出源代码，尤其当编译的时候指定了-g这种调试参数时，效果比较明显。隐含了-d参数。
 *（20）--show-raw-insn：反汇编的时候，显示每条汇编指令对应的机器码，如不指定--prefix-addresses，这将是缺省选项。
 *（21）--no-show-raw-insn：反汇编时，不显示汇编指令的机器码，如不指定--prefix-addresses，这将是缺省选项。
 *（22）--start-address=address：从指定地址开始显示数据，该选项影响-d、-r和-s选项的输出。 
 *（23）--stop-address=address：显示数据直到指定地址为止，该项影响-d、-r和-s选项的输出。 
 *（24）-t/--syms：显示文件的符号表入口。类似于nm -s提供的信息
 *（25）-T/--dynamic-syms：显示文件的动态符号表入口，仅仅对动态目标文件意义，比如某些共享库。它显示的信息类似于 nm -D|--dynamic 显示的信息。 
 *（26）-V/--version：查看objdump命令的版本信息。
 *（27）-x/--all-headers：显示所可用的头信息，包括符号表、重定位入口。-x 等价于-a -f -h -r -t 同时指定。 
 *（28）-z/--disassemble-zeroes：一般反汇编输出将省略大块的零，该选项使得这些零块也被反汇编。 
 *（29）@file：可以将选项集中到一个文件中，然后使用这个@file选项载入。
 */

#include <stdio.h>
#include <string.h>
#include "libMathApi.h"

#define UNUSED(x) (void)x

int main(int argc,char** argv)
{
	double data = power(10,2);
	printf("power(10,2) =%f\n",data);
	
	printf("add(3,7) =%f\n",add(3,7));
	printf("sub(3,7) =%f\n",sub(3,7));
	printf("mult(3,7) =%f\n",mult(3,7));
	printf("divi(3,7) =%f\n",divi(3,7));
	putc('\n',stdout);
	
	PointPtr pointPtr = point_create(4,5);
	if(pointPtr == NULL)
	{
		puts("pointPtr is null!");
		return -1;
	}
	point_display(pointPtr);
	
	point_setX(pointPtr,14);
	point_setY(pointPtr,15);
	
	double x = point_getX(pointPtr);
	double y = point_getY(pointPtr);
	printf("(%f,%f)\n",x,y);
	
	PointPtr point1 = point_create(10,20);
	PointPtr point2 = point_create(3.14,2.718);
	point_add(point1,point2,pointPtr);
	point_display(pointPtr);
	
	point_sub(point1,point2,pointPtr);
	point_display(pointPtr);
	
	point_destroy(&pointPtr);
	point_destroy(&point1);
	point_destroy(&point2);
	puts("");
	
	int num = abs_int(-5);
	printf("abs_int(-5) =%d\n",num);
	
	double value = abs_float(-0.618);
	printf("abs_float(-0.618) =%f\n",value);
	
	printf("min_2i(2,1) =%d\n",min_2i(2,1));
	printf("min_3int(8,7,9) =%d\n",min_3int(8,7,9));
	
	printf("min_2f(3.5,5.5) =%f\n",min_2f(3.5,5.5));
	printf("min_3float(25.7,11.5,17.63) =%f\n",min_3float(25.7,11.5,17.63));
	
	printf("max_2i(2,1) =%d\n",max_2i(2,1));
	printf("max_3int(8,7,9) =%d\n",max_3int(8,7,9));
	
	printf("max_2f(3.5,5.5) =%f\n",max_2f(3.5,5.5));
	printf("max_3float(25.7,11.5,17.63) =%f\n",max_3float(25.7,11.5,17.63));
	
	char buf[32] = {0};
	intToString(654321,buf);
	printf("buf =%s\n",buf);
	
	memset(buf,0,sizeof(buf));
	intToString(-1234,buf);
	printf("buf =%s\n",buf);
	
	memset(buf,0,sizeof(buf));
	floatToString(123.1415926,buf);
	printf("buf =%s\n",buf);

	floatToString(-981.414,buf);
	printf("buf =%s\n",buf);
	
	return 0;
}