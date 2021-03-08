/*如果pro文件中没有添加INCLUDEPATH += $$PWD/include语句，那么源文件中就得添加上头文件的
 *全路径名#include "../include/mymath.h"。不然就会在编译源文件时提示找不到头文件错误。
 */

#include "mymath.h"

int main(void)
{
	operate(5,6);
	return 0;
}