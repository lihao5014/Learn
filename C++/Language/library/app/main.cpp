#include <stdio.h>
#include "mymath.h"

//用于显式加载静态库或导入库。注意加载库的当前路径是执行build.bat脚本的路径
#ifdef _CHANGE_WAY_
#pragma message("---explicit load mymath.lib")
#pragma comment(lib,"bin/lib/mymath.lib")
#else
#pragma message("---implicit load mymath,lib")
#endif

#define PRINT(expr) printf("%s =%d\n",#expr,(expr))

int main(void)
{
	PRINT(add(4,5));
	PRINT(sub(9,3));
	
	return 0;
}