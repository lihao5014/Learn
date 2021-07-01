/*正数的原码、反码和补码三者都相等。也可以说正数不区分原码、反码和补码。
 *反码和补码主要是针对负数来说的，负数在内存中就是以补码的形式存储的。
 *正数在内存中是以原码形式存储的。
 */

/*反码是原码和补码之间相互转换的中间码，以便于原码和补码之间的相互计算。
 *实际计算机中并没有一种数字是以反码的形式存储的。
 */

/*1.原码就是符号位加上真值的绝对值，即用第一位表示符号，其余位表示值。
 *2.正数的反码是其本身。负数的反码是在其原码的基础上，符号位不变，其余各个位取反。
 *3.正数的补码就是其本身。负数的补码是在其原码的基础上，符号位不变，其余各位取反，最后加1，
 *  即补码是在反码的基础上加1。
 */

/*mingw编译器提供的标准库只是对msvc编译器标准库的一种封装而已。msvc标准库中实现的函数，
 *在mingw编译器标准库都有对应的函数。而msvc编译器标准库中没有提供的接口，在mingw标准库
 *中多半也没有提供。
 */

#include <stdio.h>
#include <stdlib.h>   //itoa() - cl编译器
#include <string.h>   //memset(),bzero() - gcc编译器

#define _CHANGE_WAY_
#undef _CHANGE_WAY_

#define BUFF_SIZE 64

int main(void)
{
	int x = 6;
	printf("decimal: x =%d\n",x);
	printf("octal: x =%o\n",x);
	printf("hexadecimal: x =%x\n",x);
	
	/*itoa()不是标准C库函数，只有vc++/mingw gcc编译器在string.h头文件中实现了这个函数，而gcc编译器提供的
	 *标准C库头文件string.h中没有定义该函数。
	 */
	char buf[BUFF_SIZE] = {0};
	itoa(x,buf,2);
	printf("binary: x =%s\n\n",buf);   //正数在内存中以原码的形式存储

	int y = -6;
	fprintf(stdout,"decimal: y =%d\n",y);
	fprintf(stdout,"octal: y =%o\n",y);
	fprintf(stdout,"hexadecimal: y =%x\n",y);
	
	/*bzero()也不是标准C库函数，而是曾经的POXIS标准库函数，但在最新的POXIS标准中已经将bzero()函数移除。
	 *而推荐使用memset()代替bzero()函数。因为bzero()只出现在POXIS标准中过，所以只有gcc编译器在string.h
	 *头文件中实现了这个函数，而msvc/mingw编译器提供的标准C库头文件string.h中没有定义该函数。
	 */
#ifndef _CHANGE_WAY_
	memset(buf,0,BUFF_SIZE);
#else
	bzero(buf,sizeof(buf));
#endif
	itoa(y,buf,2);
	fprintf(stdout,"binary: y =%s\n",buf);   //负数在内存中以补码的形式存储
	
	return 0;
}